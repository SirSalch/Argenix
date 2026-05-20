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
template<typename Gpio, uint8_t PinNumber>
class GpioPin {
public:
  Gpio& port;                                    // Gpio порт пина
  static constexpr uint8_t number = PinNumber;  // Номер пина
  
  // Конструктор класса
  constexpr GpioPin(Gpio& _port) : port(_port){} 
};


// Класс пина
template<typename GpioPin>
class Pin {
public:
  // Конструктор класса
  constexpr inline Pin(GpioPin& _pin, uint8_t mode) : pin(_pin) {
    pin.port.setClocking(true);
    pin.port.setMode(pin.number, mode);
  }

  // Выходное значение пина (HIGH/LOW)
  constexpr inline void set(uint8_t state) {
    pin.port.setState(pin.number, state);
  }

private:
  GpioPin& pin;
};


// Пины порта №0
static GpioPin<decltype(Gpio_0), 0>  PIN_0_0 (Gpio_0);
static GpioPin<decltype(Gpio_0), 1>  PIN_0_1 (Gpio_0);
static GpioPin<decltype(Gpio_0), 2>  PIN_0_2 (Gpio_0);
static GpioPin<decltype(Gpio_0), 3>  PIN_0_3 (Gpio_0);
static GpioPin<decltype(Gpio_0), 4>  PIN_0_4 (Gpio_0);
static GpioPin<decltype(Gpio_0), 5>  PIN_0_5 (Gpio_0);
static GpioPin<decltype(Gpio_0), 6>  PIN_0_6 (Gpio_0);
static GpioPin<decltype(Gpio_0), 7>  PIN_0_7 (Gpio_0);
static GpioPin<decltype(Gpio_0), 8>  PIN_0_8 (Gpio_0);
static GpioPin<decltype(Gpio_0), 9>  PIN_0_9 (Gpio_0);
static GpioPin<decltype(Gpio_0), 10> PIN_0_10(Gpio_0);

// Пины порта №1
static GpioPin<decltype(Gpio_1), 0>  PIN_1_0 (Gpio_1);
static GpioPin<decltype(Gpio_1), 1>  PIN_1_1 (Gpio_1);
static GpioPin<decltype(Gpio_1), 2>  PIN_1_2 (Gpio_1);
static GpioPin<decltype(Gpio_1), 3>  PIN_1_3 (Gpio_1);
static GpioPin<decltype(Gpio_1), 4>  PIN_1_4 (Gpio_1);
static GpioPin<decltype(Gpio_1), 5>  PIN_1_5 (Gpio_1);
static GpioPin<decltype(Gpio_1), 6>  PIN_1_6 (Gpio_1);
static GpioPin<decltype(Gpio_1), 7>  PIN_1_7 (Gpio_1);
static GpioPin<decltype(Gpio_1), 8>  PIN_1_8 (Gpio_1);
static GpioPin<decltype(Gpio_1), 9>  PIN_1_9 (Gpio_1);
static GpioPin<decltype(Gpio_1), 10> PIN_1_10(Gpio_1);

// Пины порта №2
static GpioPin<decltype(Gpio_2), 0>  PIN_2_0 (Gpio_2);
static GpioPin<decltype(Gpio_2), 1>  PIN_2_1 (Gpio_2);
static GpioPin<decltype(Gpio_2), 2>  PIN_2_2 (Gpio_2);
static GpioPin<decltype(Gpio_2), 3>  PIN_2_3 (Gpio_2);
static GpioPin<decltype(Gpio_2), 4>  PIN_2_4 (Gpio_2);
static GpioPin<decltype(Gpio_2), 5>  PIN_2_5 (Gpio_2);
static GpioPin<decltype(Gpio_2), 6>  PIN_2_6 (Gpio_2);
static GpioPin<decltype(Gpio_2), 7>  PIN_2_7 (Gpio_2);


#endif /* _PIN_HPP_ */