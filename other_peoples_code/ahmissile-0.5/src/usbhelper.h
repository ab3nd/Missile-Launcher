#ifndef USBHELPER_H
#define USBHELPER_H

#include "device.h"

/* usb helper functions */
void release_usb_device(int);
void list_devices();
struct supported_device *find_device(struct supported_device*);
void print_bytes(char*, int);

#endif
