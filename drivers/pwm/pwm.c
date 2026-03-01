#include "pwm.h"

#define PWM_MAX_CHANNELS 8u

static uint32_t pwm_freq_hz;
static float pwm_duty[PWM_MAX_CHANNELS];
static int pwm_ready;

drv_status_t pwm_driver_init(void) {
    pwm_freq_hz = 0;
    for (uint8_t i = 0; i < PWM_MAX_CHANNELS; ++i) {
        pwm_duty[i] = 0.0f;
    }
    pwm_ready = 1;
    return DRV_OK;
}

drv_status_t pwm_init(const pwm_config_t *cfg) {
    if (cfg == 0 || cfg->base_frequency_hz == 0 || cfg->channels == 0 || cfg->channels > PWM_MAX_CHANNELS) {
        return DRV_ERR_ARG;
    }
    if (pwm_driver_init() != DRV_OK) {
        return DRV_ERR_HW;
    }
    pwm_freq_hz = cfg->base_frequency_hz;
    return DRV_OK;
}

drv_status_t pwm_set_frequency(uint32_t hz) {
    if (!pwm_ready || hz == 0) {
        return DRV_ERR_ARG;
    }
    pwm_freq_hz = hz;
    return DRV_OK;
}

drv_status_t pwm_set_duty(uint8_t channel, float duty_percent) {
    if (!pwm_ready || channel >= PWM_MAX_CHANNELS || duty_percent < 0.0f || duty_percent > 100.0f) {
        return DRV_ERR_ARG;
    }
    pwm_duty[channel] = duty_percent;
    return DRV_OK;
}

drv_status_t pwm_start(uint8_t channel) {
    if (!pwm_ready || channel >= PWM_MAX_CHANNELS) {
        return DRV_ERR_ARG;
    }
    return DRV_OK;
}

drv_status_t pwm_stop(uint8_t channel) {
    if (!pwm_ready || channel >= PWM_MAX_CHANNELS) {
        return DRV_ERR_ARG;
    }
    return DRV_OK;
}
