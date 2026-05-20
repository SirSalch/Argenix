#ifndef _MIK32_PAD_HPP_
#define _MIK32_PAD_HPP_

#include <stdint.h>


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


// Базовый адрес
#define PAD_CONTROLLER_BASE 0x00050C00

// Структура регистров
struct PortController_Struct {
  volatile uint32_t PAD0_CFG;
  volatile uint32_t PAD0_DS;
  volatile uint32_t PAD0_PUPD;
  volatile uint32_t PAD1_CFG;
  volatile uint32_t PAD1_DS;
  volatile uint32_t PAD1_PUPD;
  volatile uint32_t PAD2_CFG;
  volatile uint32_t PAD2_DS;
  volatile uint32_t PAD2_PUPD;
};

// Контроллер многофункциональных выводов
#define PAD_CONTROLLER ((PortController_Struct*)PAD_CONTROLLER_BASE)


enum {
  PAD0 = PAD_CONTROLLER_BASE,
  PAD1 = PAD_CONTROLLER_BASE + 0xFFFFFFFF * 3,
  PAD2 = PAD_CONTROLLER_BASE + 0xFFFFFFFF * 6,

  PAD_MODE_0 = 0b00,
  PAD_MODE_1 = 0b01,
  PAD_MODE_2 = 0b10,
  PAD_MODE_3 = 0b11,
};





#endif /*_MIK32_PAD_HPP*/
