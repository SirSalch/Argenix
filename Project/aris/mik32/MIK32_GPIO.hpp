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


// Имена Gpio
enum {
  GPIO_INPUT  = 0,
  GPIO_OUTPUT = 1,
};


// Базовые адреса портов
constexpr uintptr_t GPIO_0_BASE = 0x00084000;
constexpr uintptr_t GPIO_1_BASE = 0x00084400;
constexpr uintptr_t GPIO_2_BASE = 0x00084800;


// Структура регистров порта
struct GpioPort {
  volatile uint32_t STATE;
  volatile uint32_t CLEAR;
  volatile uint32_t DIRECTION_OUT;
  volatile uint32_t DIRECTION_IN;
  volatile uint32_t OUTPUT;
  volatile uint32_t CONTROL;
};
// Регистровые порты
inline GpioPort& GPIO_0 = *reinterpret_cast<GpioPort*>(GPIO_0_BASE);
inline GpioPort& GPIO_1 = *reinterpret_cast<GpioPort*>(GPIO_1_BASE);
inline GpioPort& GPIO_2 = *reinterpret_cast<GpioPort*>(GPIO_2_BASE);


// Главный класс Gpio
template <uintptr_t baseAddress, uint32_t clkMask, uintptr_t padAddress>
class Gpio {
public:
  // Состояние тактирования
  inline static void setClocking(bool state) {
    (state? APB->CLK_PERIPHERY_SET : APB->CLK_PERIPHERY_CLEAR) = clkMask;
  }

  // Выходное значение (HIGH/LOW)
  inline static void setState(uint8_t pinNumber, bool state) {
    (state ? port()->STATE : port()->CLEAR) = 1 << pinNumber;
  }

  // Режим работы
  inline static void setMode(uint8_t pinNumber, uint8_t mode) {
    switch(mode) {
      case GPIO_OUTPUT: port()->DIRECTION_OUT = (1 << pinNumber); break;
      case GPIO_INPUT:  port()->DIRECTION_IN  = (1 << pinNumber);
    }
  }

  // Альтернативные функции (PAD)
  inline static void setPadMode(uint8_t pin, uint8_t mode) {
    *pad() |= mode << (pin * 2);
  }

private:
  // Вспомогательные функции
  static constexpr inline auto port() { return reinterpret_cast<GpioPort*>(baseAddress); }
  static constexpr inline auto pad()  { return reinterpret_cast<volatile uint32_t*>(padAddress); }
};


static Gpio<GPIO_0_BASE, CLK_GPIO_0, PAD0> Gpio_0;
static Gpio<GPIO_1_BASE, CLK_GPIO_1, PAD1> Gpio_1;
static Gpio<GPIO_2_BASE, CLK_GPIO_2, PAD2> Gpio_2;

#endif /* _MIK32_GPIO_HPP_ */