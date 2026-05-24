#ifndef _PWM_HPP_
#define _PWM_HPP_

#include <MIK32_TIMER_32.hpp>
#include <MIK32_GPIO.hpp>

#define PWM1 TIMER_32_1
#define PWM2 TIMER_32_1

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
 > Библиотека управлеия ШИМ
*/


template <typename Timer>
class Pwm {
public:
  constexpr Pwm(Timer){ }

  static void setup() {
    Timer::setClocking(true);
    Timer::setTop(1000);
    Timer::setPrescaler(0);
    Timer::enable();
  }

  static void generate(uint8_t channel, uint32_t fill) {
    Timer::setupPin(channel);
    Timer::setupPwmChannel(channel);
    Timer::setCompare(channel, fill);
  }
};


#endif /* _PWM_HPP_ */
