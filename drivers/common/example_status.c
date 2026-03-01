#include "drv_status.h"

extern const char *drv_status_to_string(drv_status_t status);

int main(void) {
    // Framework-level init for shared driver services.
    if (drv_init() != DRV_OK) return -1;

    const char *ok = drv_status_to_string(DRV_OK);
    const char *err = drv_status_to_string(DRV_ERR_HW);

    // Replace with board logger/UART print in target integration.
    (void)ok;
    (void)err;
    return 0;
}
