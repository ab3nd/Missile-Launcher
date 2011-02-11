/* 
 * USB Helper functions generated from usbsnoop log using
 * http://iki.fi/lindi/usb/usbsnoop2libusb.pl
 *
 * Copyright (c) 2007 Andreas Henriksson <andreas@fatal.se>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <ctype.h>
#include <usb.h>
#if 0
 #include <linux/usbdevice_fs.h>
 #define LIBUSB_AUGMENT
 #include "libusb_augment.h"
#endif

#include "usbhelper.h"

/* usb helper functions */
void release_usb_device(int dummy) {
    int ret;
    ret = usb_release_interface(dev->devh, 0);
    if (!ret)
	printf("failed to release interface: %d\n", ret);
    usb_close(dev->devh);
    if (!ret)
	printf("failed to close interface: %d\n", ret);
    exit(1);
}

void list_devices() {
    struct usb_bus *bus;
    for (bus = usb_get_busses(); bus; bus = bus->next) {
	struct usb_device *dev;
	
	for (dev = bus->devices; dev; dev = dev->next)
	    printf("0x%04x 0x%04x\n",
		   dev->descriptor.idVendor,
		   dev->descriptor.idProduct);
    }
}    

struct supported_device* _check_dev(struct supported_device list[],
		struct usb_device *dev)
{
	struct supported_device *ret;
	int i;

	for (i = 0; list[i].vendor != 0; i++) {
		int vid = dev->descriptor.idVendor;
		int pid = dev->descriptor.idProduct;

		if (vid == list[i].vendor && pid == list[i].product) {
			ret = malloc(sizeof(*ret));
			if (!ret) {
				fprintf(stderr, "Error: malloc failed!\n");
				continue;
			}

			/* copy vendor, product, quirks.... */
			memcpy(ret, &list[i], sizeof(*ret));

			ret->dev = dev;

			return ret;
		}
	}

	return NULL;
}

struct supported_device *find_device(struct supported_device *list) {
	struct supported_device *ret;
	struct usb_bus *bus;
    
	for (bus = usb_get_busses(); bus; bus = bus->next) {
		struct usb_device *dev;
	
		for (dev = bus->devices; dev; dev = dev->next) {
			ret = _check_dev(list, dev);
			if (ret) /* supported device found! */
				return ret;
		}

	}
	return NULL;
}

void print_bytes(char *bytes, int len) {
    int i;
    if (len > 0) {
	for (i=0; i<len; i++) {
	    printf("%02x ", (int)((unsigned char)bytes[i]));
	}
	printf("\"");
        for (i=0; i<len; i++) {
	    printf("%c", isprint(bytes[i]) ? bytes[i] : '.');
        }
        printf("\"");
    }
}

