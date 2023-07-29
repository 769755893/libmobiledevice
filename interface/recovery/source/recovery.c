#include "../header/recovery.h"

lockdownd_error_t enter_recovery(lockdownd_client_t client) {
    return lockdownd_enter_recovery(client);
}

restored_error_t exit_recovery(restored_client_t client) {
    return restored_reboot(client);
}