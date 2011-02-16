/*
 * missile_launcher.h
 *
 *  Created on: Feb 11, 2011
 *      Author: ams
 */

#ifndef MISSILE_LAUNCHER_H_
#define MISSILE_LAUNCHER_H_

#include <usb.h>
#include <iostream>

using namespace std;

typedef enum
{
	FIRE = 0x10, LEFT = 0x4, RIGHT = 0x8, UP = 0x1, DOWN = 0x2, STOP = 0x0
} MissileCmd;

class MissileLauncher
{
public:
	//Setup and teardown
	int init();
	void deinit();
	//Motion commands
	void fire();
	void stop();
	void turn(MissileCmd direction, double duration);
private:
	usb_dev_handle* launcher;
	int sendMsg(MissileCmd cmd);
};

#endif /* MISSILE_LAUNCHER_H_ */
