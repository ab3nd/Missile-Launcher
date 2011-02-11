#include <usb.h>
#include <stdio.h>
#include <curses.h>

//I know this is bad style, suck it!
usb_dev_handle* launcher;


int lines, cols;
int halfLines;
int halfCols;

void pauseForMove()
{
	struct timespec moveDelayTime;
	moveDelayTime.tv_sec = 0;
	moveDelayTime.tv_nsec = 50000000;

	const struct timespec* moveDelay = &moveDelayTime;
	struct timespec* timeLeft;

	nanosleep(moveDelay, timeLeft);
}

//wrapper for control_msg
int send_message(char* msg, int index)
{
	int i = 0;
	int j = usb_control_msg(launcher, 0x21, 0x9, 0x200, index, msg, 8, 1000);

	//be sure that msg is all zeroes again
	msg[0] = 0x0;
	msg[1] = 0x0;
	msg[2] = 0x0;
	msg[3] = 0x0;
	msg[4] = 0x0;
	msg[5] = 0x0;
	msg[6] = 0x0;
	msg[7] = 0x0;

	return j;
}

void movement_handler(char control)
{
	char msg[8];
	//reset
	msg[0] = 0x0;
	msg[1] = 0x0;
	msg[2] = 0x0;
	msg[3] = 0x0;
	msg[4] = 0x0;
	msg[5] = 0x0;
	msg[6] = 0x0;
	msg[7] = 0x0;

	//send 0s
	int deally = send_message(msg, 1);

	//send control
	msg[0] = control;
	deally = send_message(msg, 0);

	//and more zeroes
	deally = send_message(msg, 1);
				
}

void fire()
{
	//warn the user
	move(4, halfCols - 12);
	attron(A_STANDOUT);
	printw("LAUNCH SEQUENCE INITIATED");
	curs_set(0);
	refresh();
	
	//need to wait 6.5ish seconds
	struct timespec toWait;
	toWait.tv_sec = 6;
	toWait.tv_nsec = 770000000;

	const struct timespec* waiting = &toWait;

	//will hald the time remaining
	struct timespec* whoCares;

	movement_handler(16);

	nanosleep(waiting, whoCares);

	movement_handler(0);

	move(4, halfCols - 12);
	attroff(A_STANDOUT);
	printw("                            ");
	curs_set(0);
}

//window drawing functions
void drawScreen()
{
	getmaxyx(stdscr, lines, cols);
	halfLines = lines / 2;
	halfCols = cols / 2;

	move(0,halfCols - 13);
	printw("WELCOME TO MISSLE COMMAND");
	move(1, halfCols - 9);
	printw("press '0' to fire");

	move(halfLines - 2, halfCols);
	printw("8");

	move(halfLines - 1, halfCols);
	printw("|");

	move(halfLines, halfCols - 3);
	printw("4--+--6");

	move(halfLines + 1, halfCols);
	printw("|");

	move(halfLines + 2, halfCols);
	printw("5");

	move(lines - 1, 0);
	printw("press 'q' to quit");

}

void fixHighlights()
{
	
	move(halfLines - 2, halfCols);
	addch('8' | A_NORMAL);

	move(halfLines, halfCols + 3);
	addch('6' | A_NORMAL);

	move(halfLines, halfCols - 3);
	addch('4' | A_NORMAL);

	move(halfLines + 2, halfCols);
	addch('5' | A_NORMAL);

	curs_set(0);

}

int main()
{
    	struct usb_bus *busses;
    
    	usb_init();
    	usb_find_busses();
    	usb_find_devices();
    
    	busses = usb_get_busses();
        


   	struct usb_bus *bus;
    	int c, i, a;
    
    	/* ... */
    
    	for (bus = busses; bus; bus = bus->next) 
	{
    		struct usb_device *dev;
    
    		for (dev = bus->devices; dev; dev = dev->next) 
		{
    			/* Check if this device is a printer */
    			if (dev->descriptor.idVendor == 6465)
			{
				launcher = usb_open(dev);

				//do stuff
				int claimed = usb_claim_interface(launcher, 0);
				if (claimed == 0)
				{
					int c;
					int redrawNeeded = 0;
					//movement_handler(0x10);

					//c = getchar();

					//movement_handler(0x0);
					//set up curses
					initscr();
					noecho();
					keypad(stdscr, TRUE);
					cbreak();
					nodelay(stdscr, TRUE);

					//draw the interface
					drawScreen();

					//main program loop
					while ( c = getch() )
					{
						//up
						if (c == '8')
						{
							movement_handler(1);

							move(halfLines - 2, halfCols);
							addch('8' | A_BOLD);
							redrawNeeded = 1;

							pauseForMove();
						}
						//down
						else if (c == '5')
						{
							movement_handler(2);

							move(halfLines + 2, halfCols);
							addch('5' | A_BOLD);
							redrawNeeded = 1;

							pauseForMove();
						}
						//left
						else if (c == '4')
						{
							movement_handler(4);

							move(halfLines, halfCols - 3);
							addch('4' | A_BOLD);
							redrawNeeded = 1;

							pauseForMove();
						}
						//right
						else if (c == '6')
						{
							movement_handler(8);
							
							move(halfLines, halfCols + 3);
							addch('6' | A_BOLD);
							redrawNeeded = 1;

							pauseForMove();
						}
						//fire
						else if (c == '0')
						{
							fire();
						}
						else if (c == 'q')
						{
							break;
						}
						else
						{
							movement_handler(0);
							if (redrawNeeded)
							{
								fixHighlights();
								redrawNeeded = 0;
							}
						}
					}


					//stop curses
					endwin();

					usb_release_interface(launcher, 0);
				}

				usb_close(launcher);
    			}
		}
    
    	}
}
