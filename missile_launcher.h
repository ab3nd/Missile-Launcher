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

class MissileLauncher
{
public:
	int init();
	void fire();
private:
	usb_dev_handle* launcher;
};

#endif /* MISSILE_LAUNCHER_H_ */
