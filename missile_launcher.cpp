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
	cout << "Fire ze missiles!!!" << endl;
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
