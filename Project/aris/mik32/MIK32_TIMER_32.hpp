#ifndef _MIK32_TIMER_32_HPP_
#define _MIK32_TIMER_32_HPP_

#include <stdint.h>
#include <MIK32_APB.hpp>
#include <MIK32_PAD.hpp>


/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]
   ╔═════╗    ╔═════════╗  ╔═════════╗  ╔═════════╗
  ╔██████╚═╗  ██████████║  ██████████╝  ██████████╝
 ██╚═════██║  ██╚═════██║      ██║      ██╚═══════╗
 ██████████║  ██████████╝      ██║      ██████████║
 ██║     ██║  ██║   ██╚═╗  ╔═══██╚═══╗  ╔═══════██║
 ██╝     ██╝  ██╝     ██╝  ██████████╝  ██████████╝

[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]
 (Argenix RISC-V Interface Standart)
 
 > Автор: _Salch_
 > Микроконтроллер: МИК32 Амур
*/


// Базоавые адреса 32-битных таймеров
#define TIMER_32_1_BASE 0x00082800
#define TIMER_32_2_BASE 0x00082C00

// Структура регисторв 32-битного таймера
struct Timer32_Struct {
  volatile uint32_t VALUE;
  volatile uint32_t TOP;
  volatile uint32_t PRESCALER;
  volatile uint32_t CONTROL;
  volatile uint32_t ENABLE;
  volatile uint32_t INT_MASK;
  volatile uint32_t INT_CLEAR;
  volatile uint32_t INT_FLAG;
  uint32_t reserved[24]; 
  volatile uint32_t CH1_CNTRL;
  volatile uint32_t CH1_OCR;
  volatile uint32_t CH1_ICR;
  volatile uint32_t CH2_CNTRL;
  volatile uint32_t CH2_OCR;
  volatile uint32_t CH2_ICR;
  volatile uint32_t CH3_CNTRL;
  volatile uint32_t CH3_OCR;
  volatile uint32_t CH3_ICR;
  volatile uint32_t CH4_CNTRL;
  volatile uint32_t CH4_OCR;
  volatile uint32_t CH4_ICR;
};

// Структуры регистров 32-битных таймеров
#define TIMER_32_1 ((Timer32_Struct*)TIMER_32_1_BASE)
#define TIMER_32_2 ((Timer32_Struct*)TIMER_32_2_BASE)


// Настройки таймера
enum {
  TIMER32_COMPARISON_MODE = 0b01 << 5,
  TIMER32_CAPTURE_MODE    = 0b10 << 5,
  TIMER32_PWM_MDOE        = 0b11 << 5,

  TIMER32_ENABLE          = 1 << 7,
};


// Структура 32-битного таймера
template <uintptr_t baseAddress, uint32_t clkMask, typename GpioPort>
class Timer32 {
public:
  __attribute__((always_inline)) void enable() {
    reinterpret_cast<Timer32_Struct*>(baseAddress)->ENABLE = 1;
  }

  __attribute__((always_inline)) void disable() {
    reinterpret_cast<Timer32_Struct*>(baseAddress)->ENABLE = 0;
  }

  __attribute__((always_inline)) void reset() {
    reinterpret_cast<Timer32_Struct*>(baseAddress)->ENABLE = 0x01 << 1 | 0x01;
  }

  __attribute__((always_inline)) void setupGpio(const uint8_t channel) {
    GpioPort().setPadMode(channel, PAD_MODE_2);
  }

  __attribute__((always_inline)) void setClocking(const bool state) {
    (state ? APB->CLK_PERIPHERY_SET : APB->CLK_PERIPHERY_CLEAR) = clkMask;
  }
  
  __attribute__((always_inline)) void setTop(const uint32_t value) {
    reinterpret_cast<Timer32_Struct*>(baseAddress)->TOP = value;
  }

  __attribute__((always_inline)) void setPrescaler(const uint32_t value) {
    reinterpret_cast<Timer32_Struct*>(baseAddress)->PRESCALER = value;
  }

  __attribute__((always_inline)) void setOCR(uint8_t ch, uint32_t value) {
    (&reinterpret_cast<Timer32_Struct*>(baseAddress)->CH1_OCR)[ch * 3] = value;
  }

  __attribute__((always_inline)) void setupChannelPWM(uint8_t ch) {
    (&reinterpret_cast<Timer32_Struct*>(baseAddress)->CH1_CNTRL)[ch * 3] = (0b11 << 5) | (1 << 7);
  }
};


// 32-битные таймеры
static Timer32<TIMER_32_1_BASE, CLK_TIMER_32_1, decltype(Gpio_0)> Timer32_1;
static Timer32<TIMER_32_2_BASE, CLK_TIMER_32_2, decltype(Gpio_1)> Timer32_2;


#endif /* _MIK32_TIMER_32_HPP_ */