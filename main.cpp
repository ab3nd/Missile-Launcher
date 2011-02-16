/*
 * main.cpp
 *
 *  Created on: Feb 11, 2011
 *      Author: ams
 *
 *  Uses the object-oriented control program for controlling the Dream Cheeky
 *  Missile Launcher to move the launcher and fire the missiles.
 *
 */

#include <iostream>
#include "missile_launcher.h"

using namespace std;

int main(int argc, char* argv[])
{
	MissileLauncher mc;
	if(mc.init() == 0){
		mc.turn(LEFT, 1.5);
		mc.turn(UP, 1);
		mc.turn(RIGHT, 1.5);
		mc.turn(DOWN, 1);
		//mc.fire();
	}else{
		cerr << "Failed to initialize missile launcher" << endl;
	}
	mc.deinit();
	return 0;
}
