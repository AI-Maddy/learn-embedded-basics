#ifndef DRV_STATUS_H
#define DRV_STATUS_H

typedef enum {
    DRV_OK = 0,
    DRV_ERR_BUSY,
    DRV_ERR_TIMEOUT,
    DRV_ERR_ARG,
    DRV_ERR_HW,
    DRV_ERR_UNSUPPORTED
} drv_status_t;

drv_status_t drv_init(void);
const char *drv_status_to_string(drv_status_t status);

#endif
