#include "drv_status.h"

drv_status_t drv_init(void) {
    return DRV_OK;
}

const char *drv_status_to_string(drv_status_t status) {
    switch (status) {
        case DRV_OK: return "DRV_OK";
        case DRV_ERR_BUSY: return "DRV_ERR_BUSY";
        case DRV_ERR_TIMEOUT: return "DRV_ERR_TIMEOUT";
        case DRV_ERR_ARG: return "DRV_ERR_ARG";
        case DRV_ERR_HW: return "DRV_ERR_HW";
        case DRV_ERR_UNSUPPORTED: return "DRV_ERR_UNSUPPORTED";
        default: return "DRV_ERR_UNKNOWN";
    }
}
