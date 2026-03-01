# 🎯 Capture/Compare Explained

⏱️ **Capture/Compare** is a powerful timer feature for measuring time intervals, pulse widths, and generating precise events.

## 🏹 Capture Mode
- Captures the timer value when an external event (edge) occurs
- Used for measuring pulse width, frequency, or time between events
- Example: Measure the duration of a high pulse on an input pin

## 🧮 Compare Mode
- Compares timer value to a set value (compare register)
- Triggers an action (interrupt, output toggle) when matched
- Used for PWM, periodic interrupts, or output waveforms

## 📐 Quick Calculations
- Input signal frequency from period capture:
	\( f = \frac{f_{timer}}{\Delta ticks} \)
- Pulse width from two captures:
	\( t_{pulse} = \Delta ticks \times T_{tick} \)
- Compare interval:
	choose compare value so that \( \Delta ticks = t_{target} / T_{tick} \)

## 🧪 Implementation Flow
1. Configure timer clock and prescaler first.
2. Configure capture input edge (rising/falling/both) or compare output behavior.
3. Enable interrupt flags and clear pending status bits.
4. In ISR, store timestamps and compute deltas safely (handle counter wraparound).
5. Expose results via volatile variables or queue events to main loop.

## ⚠️ Common Pitfalls
- Forgetting to account for timer overflow between two captures.
- Changing prescaler at runtime without updating conversion math.
- Not clearing interrupt flags, causing ISR retrigger storms.
- Measuring noisy signals without input filtering/hysteresis.

## 🔬 Validation Checklist
- Validate measured frequency against a known signal generator.
- Confirm ISR latency is low enough for maximum expected input rate.
- Check waveform timing in a logic analyzer for compare-generated outputs.
- Test both low-frequency and high-frequency edge cases.

## 🧠 Tips
- Use input capture for frequency counters, ultrasonic sensors, etc.
- Use output compare for PWM, precise timing, or event scheduling
- Combine with interrupts for real-time response

---

✨ *Capture/Compare: The "stopwatch" and "alarm clock" of your MCU!*

🔑 **Mnemonic:** "C**C**: **C**apture the moment, **C**ompare to act!"