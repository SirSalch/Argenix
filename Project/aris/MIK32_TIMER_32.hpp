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
struct Timer32_RegisterMap {
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
#define TIMER_32_1_REG ((Timer32_RegisterMap*)TIMER_32_1_BASE)
#define TIMER_32_2_REG ((Timer32_RegisterMap*)TIMER_32_2_BASE)


// Настройки таймера
enum {
  TIMER32_COMPARISON_MODE = 0b01 << 5,
  TIMER32_CAPTURE_MODE    = 0b10 << 5,
  TIMER32_PWM_MDOE        = 0b11 << 5,

  TIMER32_ENABLE          = 1 << 7,
};


template<uintptr_t timerAddress, typename Port, uint32_t clkMask>
class Timer32 {
public:
  static void setClocking(bool state) {
    (state ? APB->CLK_PERIPHERY_SET : APB->CLK_PERIPHERY_CLEAR) = clkMask;
  }

  static void enable() {
    timer()->ENABLE = 1;
  }

  static void disable() {
    timer()->ENABLE = 0;
  }

  static void reset() {
    timer()->ENABLE = 1 << 1 | 1;
  }

  static void setupPin(uint8_t channel) {
    Port::setPadMode(channel, PAD_MODE_2);
  }

  static void setTop(uint32_t value) {
    timer()->TOP = value;
  }

  static void setPrescaler(uint32_t value) {
    timer()->PRESCALER = value;
  }

  static void setCompare(uint8_t channel, uint32_t value) {
    (&timer()->CH1_OCR)[channel * 3] = value;
  }

  static void setupPwmChannel(uint8_t channel) {
    (&timer()->CH1_CNTRL)[channel * 3] = (0b11 << 5) | (1 << 7);
  }

private:
  static inline auto timer() { return reinterpret_cast<Timer32_RegisterMap*>(timerAddress); }
};


static Timer32<TIMER_32_1_BASE, decltype(GPIO_0), CLK_TIMER_32_1> TIMER_32_1;
static Timer32<TIMER_32_2_BASE, decltype(GPIO_1), CLK_TIMER_32_2> TIMER_32_2;

#endif /* _MIK32_TIMER_32_HPP_ */