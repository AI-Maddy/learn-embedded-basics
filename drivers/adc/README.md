# ADC Driver

Analog-to-Digital Converter (ADC) drivers convert sensor voltages into digital values for your application.

## Scope
- Single-shot and continuous conversion flows
- Channel selection and sample-time configuration
- Result scaling (raw counts to millivolts)
- Polling and interrupt-driven data capture

## Suggested Driver API
- `adc_init(const adc_config_t *cfg)`
- `adc_config_channel(uint8_t channel, adc_sample_time_t sample_time)`
- `adc_start_conversion(uint8_t channel)`
- `adc_is_conversion_done(void)`
- `adc_read_raw(void)`
- `adc_read_mv(uint16_t vref_mv)`

## Baremetal Bring-Up Order
1. Enable peripheral clock and required GPIO analog mode
2. Configure ADC resolution, alignment, and sample time
3. Calibrate ADC if the MCU supports calibration
4. Trigger conversion and wait for completion
5. Read result and convert to engineering units

## Common Pitfalls
- Forgetting ADC clock source or prescaler setup
- Sampling too fast for high source impedance sensors
- Ignoring reference voltage tolerance in calculations

## Validation Checklist
- Raw code stable for fixed voltage input
- Millivolt conversion matches multimeter reading
- Multiple channels do not cross-talk unexpectedly