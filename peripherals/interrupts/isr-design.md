# ⚡ ISR Design Best Practices

An Interrupt Service Routine (ISR) should be fast, efficient, and safe!

## 🧠 Key Principles
- Keep ISRs short—do the minimum
- Clear interrupt flags early
- Use `volatile` for shared variables
- Avoid blocking calls and long loops
- Defer heavy work to main loop (set a flag)

## 🧰 Tips
- Use ring buffers for data
- Prioritize critical interrupts
- Test for reentrancy and stack usage

---

✨ *A great ISR is like a ninja—quick, precise, and invisible!*

🔑 **Mnemonic:** "I**S**R: **I**mmediate, **S**hort, **R**esponsive!"

## ✅ ISR Do/Don't
- Do: capture timestamp/flag, clear source, exit.
- Do: protect shared state access.
- Don't: block, print long logs, or spin in loops.
- Don't: allocate memory inside ISR.

## 🔍 Debug Checklist
- Confirm correct vector binding.
- Verify pending flag clear behavior.
- Measure ISR runtime under worst-case load.
- Inspect stack usage if nested interrupts are enabled.