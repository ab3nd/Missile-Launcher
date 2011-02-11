/*
 * Copyright (c) 2007 Andreas Henriksson <andreas@fatal.se>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <ctype.h>
#include <usb.h>

/* pipes & forks */
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "ahmissile.h"
#include "usbhelper.h"

#include <config.h> /* for VERSION */

/* internal declarations */
void _ahmissile_command(enum mcommand);
void missile_worker();

int mc_pipes[2];

/* stop the missile launcher movement */
void ahmissile_control_stop()
{
	if (dev->quirks & DEVICE_QUIRK_NEWDEV) {
		ahmissile_control_newstop();
	} else {
		d_printf("STOP\n");
		enum mcommand mc = stop;
		_ahmissile_command(mc);
	}
}

/* stop command for new type missile launcher */
void ahmissile_control_newstop()
{
	d_printf("NEWSTOP\n");
	enum mcommand mc = newstop;
	_ahmissile_command(mc);
}

/* start missile launcher movement */
void ahmissile_control_up()
{
	d_printf("UP\n");
	enum mcommand mc = up;
	_ahmissile_command(mc);
}

void ahmissile_control_down()
{
	d_printf("DOWN\n");
	enum mcommand mc = down;
	_ahmissile_command(mc);
}

void ahmissile_control_left()
{
	d_printf("LEFT\n");
	enum mcommand mc = left;
	_ahmissile_command(mc);
}

void ahmissile_control_right()
{
	d_printf("RIGHT\n");
	enum mcommand mc = right;
	_ahmissile_command(mc);
}

void ahmissile_control_fire()
{
	d_printf("FIRE\n");
	enum mcommand mc = fire;
	_ahmissile_command(mc);
}

void ahmissile_control_upleft()
{
	d_printf("UPLEFT\n");
	enum mcommand mc = upleft;
	_ahmissile_command(mc);
}

void ahmissile_control_upright()
{
	d_printf("UPRIGHT\n");
	enum mcommand mc = upright;
	_ahmissile_command(mc);
}

void ahmissile_control_downleft()
{
	d_printf("DOWNLEFT\n");
	enum mcommand mc = downleft;
	_ahmissile_command(mc);
}

void ahmissile_control_downright()
{
	d_printf("DOWNRIGHT\n");
	enum mcommand mc = downright;
	_ahmissile_command(mc);
}


/* init helpers */


int __ahmissile_open()
{
	int ret, vendor, product;
	char buf[65535];

#if 0
	usb_urb *isourb;
	struct timeval isotv;
	char isobuf[32768];
#endif

	usb_init();
//	usb_set_debug(255);
	usb_find_busses();
	usb_find_devices();


	dev = find_device(missiledevs);
	if (!dev) {
		return -1;
	}
	assert(dev);

	dev->devh = usb_open(dev->dev);
	assert(dev->devh);
    
	signal(SIGTERM, release_usb_device);

	ret = usb_get_driver_np(dev->devh, 0, buf, sizeof(buf));
	d_printf("usb_get_driver_np returned %d\n", ret);
	if (ret == 0) {
		fprintf(stderr,
			"interface 0 already claimed by driver \"%s\","
			" attempting to detach it\n", buf);
		ret = usb_detach_kernel_driver_np(dev->devh, 0);
		d_printf("usb_detach_kernel_driver_np returned %d\n", ret);
	}
	ret = usb_claim_interface(dev->devh, 0);
	if (ret != 0) {
		fprintf(stderr, "claim failed with error %d\n", ret);
		exit(1);
	}
    
	ret = usb_set_altinterface(dev->devh, 0);
	assert(ret >= 0);
}

void __ahmissile_close()
{
	int ret;

	fprintf(stderr, "WARN: abort pipe not implemented yet :(\n"); // FIXME

	ret = usb_release_interface(dev->devh, 0);
	assert(ret == 0);
	ret = usb_close(dev->devh);
	assert(ret == 0);
}

void __ahmissile_setup()
{
	int ret;
	char buf[65535];

	ret = usb_get_descriptor(dev->devh, 0x0000001, 0x0000000, buf, 0x0000012);
	if (ret < 0) {
		printf("1 get descriptor returned %d, bytes: ", ret);
		print_bytes(buf, ret);
		printf("\n");
	}
	usleep(15*1000);

	ret = usb_get_descriptor(dev->devh, 0x0000002, 0x0000000, buf, 0x0000009);
	if (ret < 0) {
		printf("2 get descriptor returned %d, bytes: ", ret);
		print_bytes(buf, ret);
		printf("\n");
	}
	usleep(11*1000);

	ret = usb_get_descriptor(dev->devh, 0x0000002, 0x0000000, buf, 0x0000022);
	if (ret < 0) {
		printf("3 get descriptor returned %d, bytes: ", ret);
		print_bytes(buf, ret);
		printf("\n");
	}
	usleep(23*1000);

	ret = usb_release_interface(dev->devh, 0);
	if (ret != 0)
		fprintf(stderr, 
			"failed to release interface before"
			" set_configuration: %d\n", ret);
	ret = usb_set_configuration(dev->devh, 0x0000001);
	if (ret < 0)
		fprintf(stderr, "WARN: set configuration returned %d\n", ret);
	ret = usb_claim_interface(dev->devh, 0);
	if (ret != 0)
		fprintf(stderr, "WARN: claim after set_configuration"
			" failed with error %d\n", ret);

	ret = usb_set_altinterface(dev->devh, 0);
	if (ret < 0)
		fprintf(stderr, "WARN: set alternate setting returned %d\n",
			ret);
	usleep(37*1000);
	
	ret = usb_control_msg(dev->devh, USB_TYPE_CLASS + USB_RECIP_INTERFACE,
			0x000000a, 0x0000000, 0x0000000, buf,
			0x0000000, 1000);
	if (ret < 0)
		fprintf(stderr, "WARN: control msg returned %d\n", ret);
	usleep(4*1000);

	ret = usb_get_descriptor(dev->devh, 0x0000022, 0x0000000, buf, 0x0000074);
	if (ret < 0) {
		printf("6 get descriptor returned %d, bytes: ", ret);
		print_bytes(buf, ret);
		printf("\n");
	}
	usleep(31*1000);
}

/* other commands */
int ahmissile_init()
{
	if (__ahmissile_open()) {
		return -1;
	}
	__ahmissile_setup();

	if (pipe(mc_pipes) < 0) {
		perror("pipe");
		return -2;
	}

	switch (fork()) {
	case -1:
		perror("fork");
		return -3;
	break;
	case 0: /* child */
		missile_worker();
	break;
	default: /* parent */
	break;
	}

	return 0;
}

int ahmissile_supports_diag()
{
	if (dev->quirks & DEVICE_QUIRK_OLDDEV)
		return 1;
	return 0;
}

void _ahmissile_command(enum mcommand mc)
{
	static enum mcommand lastmc = stop;

	/* work around keyboard repeat, for keys being held down */
	if ((lastmc != stop) && (lastmc != fire) && (lastmc == mc)) {
		d_printf("skipping repeated command (%d)\n", mc);
		return;
	}

	lastmc = mc;
	
	write(mc_pipes[1], &mc, sizeof(mc));
}

void _worker_command(enum mcommand mc)
{
	int ret;
	char buf[65535];
	const char *hexdir;

	if (dev->quirks & DEVICE_QUIRK_NEWDEV) {
		/* up and down are switched on new devices */
		if (mc == up)
			mc = down;
		else if (mc == down)
			mc = up;
	}

	hexdir = mcommand_hex[(int)mc];

	/* start command */
	memcpy(buf, hexdir, 0x0000008);
	ret = usb_control_msg(dev->devh,
			USB_TYPE_CLASS + USB_RECIP_INTERFACE,
			0x0000009, 0x0000200, 0x0000000,
			buf, 0x0000008, 1000);

	if (ret < 0) {
		fprintf(stderr, "WARN: control msg returned %d\n", ret);
		sleep(1); /* wait for device to clear error */
	}

	//usleep(10*1000);


	if (mc == fire) {
		/* delay the time it takes the device to fire */
		sleep(FIRE_DELAY);

		/* autostop command */
		if (dev->quirks & DEVICE_QUIRK_NEWDEV)
			memcpy(buf, DEVICE_NEWSTOP, 0x0000008);
		else
			memcpy(buf, DEVICE_STOP, 0x0000008);

		ret = usb_control_msg(dev->devh,
				USB_TYPE_CLASS + USB_RECIP_INTERFACE,
				0x0000009, 0x0000200, 0x0000000,
				buf, 0x0000008, 1000);

		if (ret < 0)
			fprintf(stderr, "WARN: control msg returned %d\n", ret);

		usleep(10*1000);
	}

#if 0
	if (dev->quirks & DEVICE_QUIRK_NEWDEV) {
		/* all commands needs to be stopped on new device */

		usleep(1000*1000);

		memcpy(buf, DEVICE_NEWSTOP, 0x00000008);
		ret = usb_control_msg(dev->devh,
				USB_TYPE_CLASS + USB_RECIP_INTERFACE,
				0x0000009, 0x0000200, 0x0000000,
				buf, 0x0000008, 1000);

		if (ret < 0)
			fprintf(stderr, "WARN: control msg returned %d\n", ret);

	}
#endif

}

void _worker_checkpos(enum mcommand mc)
{
	int ret;
	char buf[65535];

	/* check missile launcher position */
	/* FIXME: this needs to spin until STOP, not just checked once */
	ret = usb_interrupt_read(dev->devh, 0x00000081, buf, 0x0000008, 1000);
	//printf("7 interrupt read returned %d, bytes: ", ret);
	//print_bytes(buf, ret);
	//printf("\n");
	/* if buf contains - we have reached
	 * 80 00 00 00 00 00 00 00 = max up
	 * 40 00 00 00 00 00 00 00 = max down
	 * 00 04 00 00 00 00 00 00 = max left
	 * 00 08 00 00 00 00 00 00 = max right
	 */
	if (ret == 8) {
		int max = 0;
		if (((mc == up) || (mc == upleft) || (mc == upright)) &&
				(buf[0] & (1<<7))) {
			d_printf("worker-checkpos: reached MAXUP\n");
			max = 1;
		}
		if (((mc == down) || (mc == downleft) || (mc == downright))
				&& (buf[0] & (1<<6))) {
			d_printf("worker-checkpos: reached MAXDOWN\n");
			max = 1;
		}
		if (((mc == left) || (mc == upleft) || (mc == downleft))
				&& (buf[1] & (1<<2))) {
			d_printf("worker-checkpos: reached MAXLEFT\n");
			max = 1;
		}
		if (((mc == right) || (mc == upright) || (mc == downright))
				&& (buf[1] & (1<<3))) {
			d_printf("worker-checkpos: reached MAXRIGHT\n");
			max = 1;
		}

		if (max) {
			mc = stop;
			_worker_command(mc);
		}
	}

}


void ahmissile_about()
{
	char *authors[] = { "Andreas Henriksson <andreas@fatal.se>", "Jonas Andradas <j.andradas@gmail.com> (RE of diagonal movement, testing)", "Philipp Stern <info@getdigital.de> (sponsored new hardware)", NULL };
	char *license = "AH Missile - Control program for Dream Cheeky USB Missile Launcher\n"
"Copyright (c) 2007 Andreas Henriksson <andreas@fatal.se>\n" 
"\n"
"This program is free software; you can redistribute it and/or\n"
"modify it under the terms of the GNU General Public License\n"
"as published by the Free Software Foundation; either version 2\n"
"of the License, or (at your option) any later version.\n"
"\n"
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n"
""
"You should have received a copy of the GNU General Public License\n"
"along with this program; if not, write to the Free Software\n"
"Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.\n";

	gtk_show_about_dialog(NULL,
	"authors", authors,
	"comments", "An application to control the Dream Cheeky USB Missile Launcher",
	"copyright", "Copyright (c) 2007 Andreas Henriksson <andreas@fatal.se>",
	"license", license,
	"name", "AH Missile",
	"version", VERSION,
	NULL);
}

void ahmissile_quit()
{
	int status;

	/* make sure the device isn't moving */
	ahmissile_control_stop();

	/* kill the worker child */
	enum mcommand mc = quit;
	write(mc_pipes[1], &mc, sizeof(mc));
	wait(&status);

	/* close the usb handle */
	__ahmissile_close();

	gtk_main_quit();
}


void missile_worker()
{
	enum mcommand mc;
	int ret;
	static enum mcommand lastmc = stop;

	fcntl(mc_pipes[0], F_SETFL, O_NONBLOCK);

	while (1) {
		ret = read(mc_pipes[0], &mc, sizeof(mc));
		if (ret < 0) {
			if ((lastmc!=stop) && (lastmc!=fire)) {
				_worker_checkpos(lastmc);
			}
			usleep(10*1000);
			continue;
		}

		lastmc = mc;

		switch(mc) {
		case up:
			d_printf("worker: received UP command\n");
			_worker_command(mc);
		break;
		case down:
			d_printf("worker: received DOWN command\n");
			_worker_command(mc);
		break;
		case left:
			d_printf("worker: received LEFT command\n");
			_worker_command(mc);
		break;
		case right:
			d_printf("worker: received RIGHT command\n");
			_worker_command(mc);
		break;
		case fire:
			d_printf("worker: received FIRE command\n");
			_worker_command(mc);
		break;
		case stop:
			d_printf("worker: received STOP command\n");
			_worker_command(mc);
		break;
		case newstop:
			d_printf("worker: received NEWSTOP command\n");
			_worker_command(mc);
		break;
		case quit:
			d_printf("worker: received QUIT command\n");
			exit(0);
		break;
		case upleft:
			d_printf("worker: received UPLEFT command\n");
			_worker_command(mc);
		break;
		case upright:
			d_printf("worker: received UPRIGHT command\n");
			_worker_command(mc);
		break;
		case downleft:
			d_printf("worker: received DOWNLEFT command\n");
			_worker_command(mc);
		break;
		case downright:
			d_printf("worker: received DOWNRIGHT command\n");
			_worker_command(mc);
		break;
		default:
			fprintf(stderr,
				"worker: received unknown command (%d)\n",
				mc);
		break;
		}
	}
}
