#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include "../common/drv_status.h"

typedef struct {
    uint32_t base_frequency_hz;
    uint8_t channels;
} pwm_config_t;

drv_status_t pwm_driver_init(void);
drv_status_t pwm_init(const pwm_config_t *cfg);
drv_status_t pwm_set_frequency(uint32_t hz);
drv_status_t pwm_set_duty(uint8_t channel, float duty_percent);
drv_status_t pwm_start(uint8_t channel);
drv_status_t pwm_stop(uint8_t channel);

#endif
