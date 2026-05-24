#ifndef _MIK32_GPIO_HPP_
#define _MIK32_GPIO_HPP_

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


enum {
  GPIO_INPUT  = 0,
  GPIO_OUTPUT = 1,
};

// Базовые адреса портов
constexpr uintptr_t GPIO_0_BASE = 0x00084000;
constexpr uintptr_t GPIO_1_BASE = 0x00084400;
constexpr uintptr_t GPIO_2_BASE = 0x00084800;


// Карта регистров порта
struct GpioPort_RegMap {
  volatile uint32_t STATE;
  volatile uint32_t CLEAR;
  volatile uint32_t DIRECTION_OUT;
  volatile uint32_t DIRECTION_IN;
  volatile uint32_t OUTPUT;
  volatile uint32_t CONTROL;
};

// Регистровые порты
inline GpioPort_RegMap& GPIO_0_REG = *reinterpret_cast<GpioPort_RegMap*>(GPIO_0_BASE);
inline GpioPort_RegMap& GPIO_1_REG = *reinterpret_cast<GpioPort_RegMap*>(GPIO_1_BASE);
inline GpioPort_RegMap& GPIO_2_REG = *reinterpret_cast<GpioPort_RegMap*>(GPIO_2_BASE);


template<uintptr_t gpioAddress, uintptr_t padAddress, uint32_t clkMask>
class Gpio {
public:
  static void setClocking(bool state) {
    (state ? APB->CLK_PERIPHERY_SET : APB->CLK_PERIPHERY_CLEAR) = clkMask;
  }

  static void setMode(uint8_t pinNumber, uint8_t mode) {
    (mode ? port()->DIRECTION_OUT : port()->DIRECTION_IN ) = 1 << pinNumber;
  }

  static void setState(uint8_t pinNumber, bool state) {
    (state ? port()->STATE : port()->CLEAR) = 1 << pinNumber;
  }

  static void setPadMode(uint8_t pinNumber, uint8_t mode) {
    *pad() |= mode << pinNumber * 2;
  }

private:
  // Вспомогательные функции
  static constexpr inline auto port() { return reinterpret_cast<GpioPort_RegMap*> (gpioAddress); }
  static constexpr inline auto pad()  { return reinterpret_cast<volatile uint32_t*>(padAddress); }
};


// Порты
static Gpio<GPIO_0_BASE, PAD0, CLK_GPIO_0> GPIO_0;
static Gpio<GPIO_1_BASE, PAD1, CLK_GPIO_1> GPIO_1;
static Gpio<GPIO_2_BASE, PAD2, CLK_GPIO_2> GPIO_2;


#endif /* _MIK32_GPIO_HPP_ */