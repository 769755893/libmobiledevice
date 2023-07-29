#include "stdlib.h"
#include "stdio.h"

char *get_first_device_udid(idevice_info_t *devices)
{
    char *ret;
    for (int i = 0; devices[i] != NULL; i++)
    {
        ret = devices[i]->udid;
        break;
    }
    printf("get first device: %s\n", ret);
    return ret;
}

void CLOGSTR(const char * value) {
    printf("LOGGING: %s\n", value);
}

void CLOGINT(int value) {
    printf("LOGGING: %d\n", value);
}