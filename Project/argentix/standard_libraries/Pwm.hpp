#ifndef _PWM_HPP_
#define _PWM_HPP_

#include <MIK32_TIMER_32.hpp>
#include <MIK32_GPIO.hpp>

#define PWM1 Timer32_1
#define PWM2 Timer32_2

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
  inline Pwm(Timer& timer) : _timer(timer) {
    _timer.setClocking(true);
    _timer.setTop(1000);
    _timer.setPrescaler(0);
    _timer.enable();
  }

  inline void generate(const uint8_t channel, const uint32_t value) {
    _timer.setupGpio(channel);
    _timer.setupChannelPWM(channel);
    _timer.setOCR(channel, value);
  }

  inline void setFill(const uint8_t channel, const uint32_t value) {
    _timer.setOCR(channel, value);
  }

private:
  Timer& _timer;
};


#endif /* _PWM_HPP_ */
