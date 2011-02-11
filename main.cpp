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

int main(int argc, char** argv)
{
	MissileLauncher mc;
	if(mc.init() == 0){
		mc.fire();
	}else{
		cerr << "Failed to initialize missile launcher" << endl;
	}

	return 0;
}
