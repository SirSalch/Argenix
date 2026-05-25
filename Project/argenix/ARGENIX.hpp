#ifndef _ARGENTIX_HPP_
#define _ARGENTIX_HPP_

// Подключение Драйверов
#include <MIK32_APB.hpp>
#include <MIK32_EEPROM.hpp>
#include <MIK32_GPIO.hpp>
#include <MIK32_SYS_TIMER.hpp>
#include <MIK32_TIMER_32.hpp>

// Подключение стандартных библиотек ARGENTIX
#include <Pin.hpp>
#include <Pwm.hpp>


// Глобальные определения
enum {
  CH1 = 0,
  CH2 = 1,
  CH3 = 2,
  CH4 = 3,

  HIGH = 1,
  LOW  = 0,

  INPUT = 0,
  OUTPUT = 1,
};


// Глобальные функции
inline void delay(const uint32_t time) {
  SysTimer::start();
  while (SYS_TIMER->VALUE < (time * 32000));
}

#endif /* _ARGENTIX_HPP_ */