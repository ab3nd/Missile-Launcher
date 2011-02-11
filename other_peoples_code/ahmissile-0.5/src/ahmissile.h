#ifndef AHMISSILE_H
#define AHMISSILE_H

#include "device.h"

//#define DEBUG

#define DEVICE_STOP	"\x00\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_UP	"\x01\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_DOWN	"\x02\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_LEFT	"\x04\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_RIGHT	"\x08\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_FIRE	"\x10\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_NEWSTOP	"\x20\x00\x00\x00\x00\x00\x00\x00"

#define DEVICE_UP_LEFT		"\x05\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_UP_RIGHT		"\x09\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_DOWN_LEFT	"\x06\x00\x00\x00\x00\x00\x00\x00"
#define DEVICE_DOWN_RIGHT	"\x0A\x00\x00\x00\x00\x00\x00\x00"

#define FIRE_DELAY 7



enum mcommand {
	/* regular movement */
	up,
	down,
	left,
	right,
	/* diagonal movement */
	upleft,
	upright,
	downleft,
	downright,
	/* special commands */
	fire,
	stop,
	newstop,
	/* internal signals */
	quit = 99
};

/* must be same order as the enums! */
static const char *mcommand_hex[] = {
	DEVICE_UP,
	DEVICE_DOWN,
	DEVICE_LEFT,
	DEVICE_RIGHT,
	DEVICE_UP_LEFT,
	DEVICE_UP_RIGHT,
	DEVICE_DOWN_LEFT,
	DEVICE_DOWN_RIGHT,
	DEVICE_FIRE,
	DEVICE_STOP,
	DEVICE_NEWSTOP,
};



/* global device handle */
struct supported_device *dev;

/* stop the missile launcher movement */
void ahmissile_control_stop();
void ahmissile_control_newstop();

/* start missile launcher movement */
void ahmissile_control_up();
void ahmissile_control_down();
void ahmissile_control_left();
void ahmissile_control_right();
void ahmissile_control_fire();
void ahmissile_control_upleft();
void ahmissile_control_upright();
void ahmissile_control_downleft();
void ahmissile_control_downright();

/* other commands */
int ahmissile_init();
void ahmissile_about();
void ahmissile_quit();

/* enable/disable debugging printf */
#ifdef DEBUG
#	define d_printf printf
#else
#	define d_printf(...)
#endif /* DEBUG */

#endif
