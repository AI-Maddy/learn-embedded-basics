# PWM Driver

Pulse Width Modulation (PWM) drivers generate variable-duty waveforms for motor control, LED dimming, and power control.

## Scope
- Timer/channel initialization for PWM output
- Duty cycle update in percent or ticks
- Frequency configuration based on timer clock
- Optional complementary outputs/dead-time (advanced MCUs)

## Suggested Driver API
- `pwm_init(const pwm_config_t *cfg)`
- `pwm_set_frequency(uint32_t hz)`
- `pwm_set_duty(uint8_t channel, float duty_percent)`
- `pwm_start(uint8_t channel)`
- `pwm_stop(uint8_t channel)`

## Baremetal Bring-Up Order
1. Enable timer and GPIO clocks
2. Configure GPIO alternate output mode
3. Set timer prescaler/period for target frequency
4. Set compare value for initial duty
5. Enable timer output and verify waveform

## Common Pitfalls
- Miscalculated timer base frequency
- Duty update glitch due to non-buffered register writes
- Wrong polarity assumptions for load behavior

## Validation Checklist
- Frequency matches target on oscilloscope
- Duty sweep (10% to 90%) behaves linearly
- Multiple channels stay synchronized if required