# :material-puzzle: Common Embedded Patterns

## :material-toggle-switch: Pattern 1 — Bit Field Access

```c
// Safe read-modify-write
#define BIT(n)         (1u << (n))
#define SET_BIT(r,n)   ((r) |=  BIT(n))
#define CLR_BIT(r,n)   ((r) &= ~BIT(n))
#define TGL_BIT(r,n)   ((r) ^=  BIT(n))
#define READ_BIT(r,n)  (((r) >> (n)) & 1u)
```

---

## :material-timer-outline: Pattern 2 — Non-Blocking Delay (Tick Timer)

```c
static volatile uint32_t ticks = 0;

void SysTick_Handler(void) { ticks++; }

uint32_t get_ticks(void)    { return ticks; }

bool timeout(uint32_t start, uint32_t ms) {
    return (get_ticks() - start) >= ms;
}

// Usage
uint32_t t = get_ticks();
do_something();
while (!timeout(t, 100));  // wait up to 100ms
```

---

## :material-reload: Pattern 3 — State Machine ISR

```c
typedef enum { STATE_IDLE, STATE_BUSY, STATE_DONE, STATE_ERR } state_t;
static volatile state_t state = STATE_IDLE;

void DMA_IRQHandler(void) {
    if (DMA->ISR & DMA_ISR_TCIF) {
        DMA->IFCR = DMA_IFCR_CTCIF;   // clear flag
        state = STATE_DONE;
    } else if (DMA->ISR & DMA_ISR_TEIF) {
        state = STATE_ERR;
    }
}

// Application
state = STATE_BUSY;
dma_start_transfer();
while (state == STATE_BUSY);  // or use RTOS semaphore
if (state == STATE_ERR) handle_error();
```

---

## :material-layers: Pattern 4 — Ring Buffer

```c
typedef struct {
    uint8_t  data[256];   // power of 2 for fast modulo
    uint8_t  head, tail;  // 8-bit wraps at 256 automatically
} rb_t;

static inline bool rb_push(rb_t *b, uint8_t v) {
    if ((uint8_t)(b->head - b->tail) == 256u - 1u) return false;
    b->data[b->head++] = v;
    return true;
}
static inline bool rb_pop(rb_t *b, uint8_t *v) {
    if (b->head == b->tail) return false;
    *v = b->data[b->tail++];
    return true;
}
```

---

## :material-alert: Pattern 5 — Error Code Propagation

```c
drv_status_t init_system(void) {
    drv_status_t s;
    if ((s = gpio_driver_init()) != DRV_OK) return s;
    if ((s = uart_driver_init(115200)) != DRV_OK) return s;
    if ((s = i2c_driver_init(I2C_400KHZ)) != DRV_OK) return s;
    return DRV_OK;
}
```

---

!!! tip "Pattern Recognition for Embedded"
    - Need **precise timing**? → Timer + interrupt
    - Need **fast data transfer**? → DMA (not polling)
    - Need **event-driven response**? → EXTI interrupt
    - Need **non-blocking operation**? → State machine + ISR flag
    - Need **portable code**? → HAL driver layer
    - Need **ultra-low power**? → Sleep modes + WFI/WFE
