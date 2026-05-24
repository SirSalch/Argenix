#ifndef _PIN_HPP_
#define _PIN_HPP_

#include <MIK32_GPIO.hpp>
#include <MIK32_APB.hpp>


/*
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]
   ╔═════╗    ╔═════════╗  ╔═════════╗  ╔═════════╗  ╔═╗     ╔═╗  ╔═╗     ╔═╗  ╔═╗     ╔═╗  ╔═════════╗ 
  ╔██████╚═╗  ██████████║  ██████████╝  ██████████╝  ██║     ██║  ██║   ╔═██║  ██║   ╔═██╝  ██████████╝ 
 ██╚═════██║  ██╚═════██║  ██║          ██╚═══════╗  ██╚═════██║  ██║ ╔═████║  ██╚═══██╝    ██║         
 ██████████║  ██████████╝  ██║          ██████████╝  ██████████║  ██╚═██╝ ██║  ██████╚═╗    ██║         
 ██║     ██║  ██║          ██║          ██╚═══════╗  ██║     ██║  ████╝   ██║  ██║   ██╚═╗  ██╚═══════╗ 
 ██╝     ██╝  ██╝          ██╝          ██████████╝  ██╝     ██╝  ██╝     ██╝  ██╝     ██╝  ██████████╝ 
 
[=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=═=]
 > Автор: _Salch_
 > Библиотека управлеия пинами
*/


// Структура пина
template<typename Port, uint8_t pinNumber>
class GpioPin {
public:
  constexpr GpioPin(Port) {}

  static void setup(uint8_t mode) {
    Port::setClocking(true);
    Port::setMode(pinNumber, mode);
  }

  static void set(bool state) {
    Port::setState(pinNumber, state);
  }
};


template<typename GpioPin>
class Pin {
public:
  constexpr Pin(GpioPin){ }

  static void setup(uint8_t mode) {
    GpioPin::setup(mode);
  }

  static void set(bool state) {
    GpioPin::set(state);
  }
};


// Пины порта №0
GpioPin<decltype(GPIO_0), 0>  PIN_0_0 (GPIO_0);
GpioPin<decltype(GPIO_0), 1>  PIN_0_1 (GPIO_0);
GpioPin<decltype(GPIO_0), 2>  PIN_0_2 (GPIO_0);
GpioPin<decltype(GPIO_0), 3>  PIN_0_3 (GPIO_0);
GpioPin<decltype(GPIO_0), 4>  PIN_0_4 (GPIO_0);
GpioPin<decltype(GPIO_0), 5>  PIN_0_5 (GPIO_0);
GpioPin<decltype(GPIO_0), 6>  PIN_0_6 (GPIO_0);
GpioPin<decltype(GPIO_0), 7>  PIN_0_7 (GPIO_0);
GpioPin<decltype(GPIO_0), 8>  PIN_0_8 (GPIO_0);
GpioPin<decltype(GPIO_0), 9>  PIN_0_9 (GPIO_0);
GpioPin<decltype(GPIO_0), 10> PIN_0_10(GPIO_0);

// Пины порта №1
GpioPin<decltype(GPIO_1), 0>  PIN_1_0 (GPIO_1);
GpioPin<decltype(GPIO_1), 1>  PIN_1_1 (GPIO_1);
GpioPin<decltype(GPIO_1), 2>  PIN_1_2 (GPIO_1);
GpioPin<decltype(GPIO_1), 3>  PIN_1_3 (GPIO_1);
GpioPin<decltype(GPIO_1), 4>  PIN_1_4 (GPIO_1);
GpioPin<decltype(GPIO_1), 5>  PIN_1_5 (GPIO_1);
GpioPin<decltype(GPIO_1), 6>  PIN_1_6 (GPIO_1);
GpioPin<decltype(GPIO_1), 7>  PIN_1_7 (GPIO_1);
GpioPin<decltype(GPIO_1), 8>  PIN_1_8 (GPIO_1);
GpioPin<decltype(GPIO_1), 9>  PIN_1_9 (GPIO_1);
GpioPin<decltype(GPIO_1), 10> PIN_1_10(GPIO_1);

// Пины порта №2
GpioPin<decltype(GPIO_2), 0>  PIN_2_0 (GPIO_2);
GpioPin<decltype(GPIO_2), 1>  PIN_2_1 (GPIO_2);
GpioPin<decltype(GPIO_2), 2>  PIN_2_2 (GPIO_2);
GpioPin<decltype(GPIO_2), 3>  PIN_2_3 (GPIO_2);
GpioPin<decltype(GPIO_2), 4>  PIN_2_4 (GPIO_2);
GpioPin<decltype(GPIO_2), 5>  PIN_2_5 (GPIO_2);
GpioPin<decltype(GPIO_2), 6>  PIN_2_6 (GPIO_2);
GpioPin<decltype(GPIO_2), 7>  PIN_2_7 (GPIO_2);

#endif /* _PIN_HPP_ */