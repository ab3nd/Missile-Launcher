/*
 * missile_launcher.cpp
 *
 *  Created on: Feb 11, 2011
 *      Author: ams
 *
 *  OO interface to the Dream Cheeky Missile Launcher
 *
 */

#include "missile_launcher.h"

void MissileLauncher::fire()
{
	cout << "Fire zee missiles!!!" << endl;
	//need to wait 6.77 seconds to fire
	struct timespec toWait;
	toWait.tv_sec = 6;
	toWait.tv_nsec = 770000000;

	const struct timespec* delay = &toWait;
	struct timespec* remainder;

	//Start launch sequence and wait for launch
	if (sendMsg(FIRE) < 0)
	{
		cerr << "Could not fire." << endl;
		return;
	}
	nanosleep(delay, remainder);

	//Stop, so no more missiles launch
	stop();
}

void MissileLauncher::turn(MissileCmd direction, double delay)
{
	if (direction == FIRE)
	{
		fire();
	}
	else if (direction == STOP)
	{
		stop();
	}
	else
	{
		if (delay = 0)
		{
			/* Start moving. This means it keeps moving until you tell it to stop.
			 * Good for feedback loops, bad for not hitting the stops and abusing
			 * the slip clurch.
			 */
			sendMsg(direction);
		}
		else
		{
			/* Move for the specified time period, then stop.
			 * This is good for making little scripts, but assumes you know
			 * the pose of the gun. It's a shame there's little to no feedback from it.
			 */
			//Convert the delay into a timespec
			struct timespec toWait;
			toWait.tv_sec = (int) delay;
			toWait.tv_nsec = (delay - toWait.tv_sec) * 100000000;

			const struct timespec* delay = &toWait;
			struct timespec* remainder;

			//Start turn and wait for movement
			sendMsg(direction);
			nanosleep(delay, remainder);

			//Stop turning
			stop();
		}
	}
}

void MissileLauncher::stop()
{
	int ret = sendMsg(STOP);
	if (ret < 0)
	{
		cerr << "Cannot stop, error: " << ret << endl;
	}
}

int MissileLauncher::sendMsg(MissileCmd control)
{
	char msg[8];

	for (int ii = 0; ii < 8; ii++)
	{
		msg[ii] = 0x0;
	}

	//send control message
	msg[0] = control;
	int ret = usb_control_msg(launcher, 0x21, 0x9, 0x200, 0, msg, 8, 1000);
	if (ret < 0)
	{
		cerr << "Cannot send command, error:" << ret << endl;
	}

	return ret;
}

void MissileLauncher::deinit()
{
	usb_release_interface(launcher, 0);
	usb_close(launcher);
}

int MissileLauncher::init()
{
	struct usb_bus *busses;

	usb_init();
	usb_find_busses();
	usb_find_devices();

	busses = usb_get_busses();

	struct usb_bus *bus;

	//Iterate through buses and devices, looking for a missile launcher
	for (bus = busses; bus; bus = bus->next)
	{
		struct usb_device *dev;

		for (dev = bus->devices; dev; dev = dev->next)
		{
			/* Check if this device is a missile launcher  */
			if (dev->descriptor.idVendor == 0x1941)
			{
				launcher = usb_open(dev);

				//Make sure it's not claimed
				char driverName[32];
				int retval = usb_get_driver_np(launcher, 0, driverName, 31);
				if (retval == 0)
				{
					cout << "Claimed by " << driverName << endl;
					retval = usb_detach_kernel_driver_np(launcher, 0);
					if (retval)
					{
						cout << driverName << " can't be detached" << endl;
						return 1;
					}
					cout << "Detached " << driverName << endl;
				}

				//Claim it ourselves
				int claimed = usb_claim_interface(launcher, 0);
				if (claimed == 0)
				{
					//Rock on, we have a handle on it.
					return 0;
				}
				else
				{
					cerr << "Could not claim Missile Launcher" << endl;
					return 1;
				}
			}
		}
	}

	cerr << "Did not find Missile Launcher. Is it plugged in?" << endl;
	return 1;
}
