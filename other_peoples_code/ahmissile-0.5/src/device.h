#ifndef _DEVICE_H_
#define _DEVICE_H_

/* supported devices and quirks */

struct supported_device {
	/* public */
	int vendor;
	int product;
	int quirks;
	/* private */
	struct usb_device *dev;
	struct usb_dev_handle *devh;
};

#define DEVICE_QUIRK_OLDDEV (1<<0)
#define DEVICE_QUIRK_NEWDEV (1<<1)

static struct supported_device missiledevs[] = {
	{
		.vendor = 0x1941,
		.product = 0x8021,
		.quirks = DEVICE_QUIRK_OLDDEV,
	},
	{
		.vendor = 0xa81,
		.product = 0x701,
		.quirks = DEVICE_QUIRK_NEWDEV,
	},
	{ 0, }
};


/* global device handle */
struct supported_device *dev;

#endif
