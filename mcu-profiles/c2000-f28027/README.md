# C2000 F28027 Profile

## MCU Snapshot
- Core: TI C28x DSP-oriented MCU
- Best for: motor control, digital power, real-time control loops
- Strength: deterministic peripherals and control-focused timers

## Baremetal Startup Order
1. Call system control init (`InitSysCtrl`-style flow)
2. Configure clock tree and peripheral clocks
3. Initialize GPIO mux and direction registers
4. Configure PIE + interrupt vectors
5. Start control timer/PWM loop and enable global interrupts

## Toolchain
- Compiler/IDE: TI Code Composer Studio toolchain
- Linker command file controls memory sections tightly

## Flash + Debug
- Typical debug probe: XDS100/XDS110 class probes
- Flash via CCS or TI flash utilities
- Real-time debug and watch windows are key for control tuning

## Pin/Peripheral Priorities
- ePWM modules for switching/control outputs
- ADC trigger coupling with PWM events
- GPIO mux settings must be verified per pin
- CPU timers for deterministic scheduling

## Bring-Up Checklist
- GPIO output verified on scope
- PWM frequency/duty confirmed
- ADC sampled in sync with PWM trigger
- Interrupt latency verified for control loop target

## References in Repo
- Peripheral docs: `peripherals/pwm`, `peripherals/adc`, `peripherals/interrupts`
- Driver skeletons: `drivers/*`