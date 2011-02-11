/*
 * missile_launcher.cpp
 *
 *  Created on: Feb 11, 2011
 *      Author: ams
 *
 *  Creates and maintains info about a Dream Cheeky Missile Launcher.
 *
 */

#include "missile_launcher.h"

void MissileLauncher::fire()
{

}

int MissileLauncher::init()
{
	struct usb_bus *busses;

	usb_init();
	if (usb_find_busses() != 0)
	{
		cerr << "Failed to find USB buses" << endl;
		return 1;
	}

	if (usb_find_devices() != 0)
	{
		cerr << "Failed to find USB devices" << endl;
		return 1;
	}

	busses = usb_get_busses();

	struct usb_bus *bus;

	//Iterate through buses and devices, looking for a missile launcher
	for (bus = busses; bus; bus = bus->next)
	{
		struct usb_device *dev;

		for (dev = bus->devices; dev; dev = dev->next)
		{
			/* Check if this device is a missile launcher */
			if (dev->descriptor.idVendor == 6465)
			{
				launcher = usb_open(dev);

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
