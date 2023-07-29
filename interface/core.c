#include "./device/header/device.h"
#include "./recovery/header/recovery.h"
#include "./util/util.c"

int main() {
    idevice_info_t info = get_device_id_list();
    char * deviceKey = get_first_device_udid(info);
    idevice_error_t ERROR = LOCKDOWN_E_UNKNOWN_ERROR;
    lockdownd_error_t clientError = LOCKDOWN_E_UNKNOWN_ERROR;

    lockdownd_client_t client = NULL;
    idevice_t device = NULL;
    
    ERROR = idevice_new(&device, deviceKey);
    CLOGSTR("Create new device ret: ");
    CLOGINT(ERROR);

    clientError = lockdownd_client_new(device, &client, "");
    CLOGSTR("Create new client with device ret: ");
    CLOGINT(clientError);
    

    // clientError = enter_recovery(client);
    // CLOGSTR("Start enter recovery ret: ");
    // CLOGINT(clientError);

    // if (clientError == LOCKDOWN_E_SESSION_INACTIVE) {
    //     lockdownd_client_free(client);
    //     client = NULL;
    //     clientError = lockdownd_client_new_with_handshake(device, &client, "");
    //     clientError = lockdownd_enter_recovery(client);
    //     CLOGSTR("Again enter recovery ret: ");
    //     CLOGINT(clientError);
    // }

    #ifndef WIN32
	signal(SIGPIPE, SIG_IGN);
    #endif

    return 0;
}