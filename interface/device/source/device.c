#include "../header/device.h"

idevice_info_t get_device_id_list() {
	idevice_info_t *dev_list = NULL;
	int i;

	if (idevice_get_device_list_extended(&dev_list, &i) < 0)
	{
		fprintf(stderr, "ERROR: Unable to retrieve device list!\n");
		return -1;
	}
	printf("Success to get available device\n");
	
	for (i = 0; dev_list[i] != NULL; i++)
	{
		printf("%s\n", dev_list[i]->udid);
	}
	return dev_list;
}