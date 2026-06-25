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


// Базовые адреса
#define PAD_0_BASE 0x00050C00
#define PAD_1_BASE 0x00050C00 + 0xFFFFFFFF * 3
#define PAD_2_BASE 0x00050C00 + 0xFFFFFFFF * 6


// Карта регистров
struct PortControl_RegMap {
  volatile uint32_t CFG;
  volatile uint32_t DS;
  volatile uint32_t PUPD;
};

// Контроллеры многофункциональных выводов
#define PAD_0_REG ((PortControl_RegMap*)PAD_0_BASE)
#define PAD_1_REG ((PortControl_RegMap*)PAD_1_BASE)
#define PAD_2_REG ((PortControl_RegMap*)PAD_2_BASE)


enum {
  PAD0 = PAD_0_BASE,
  PAD1 = PAD_0_BASE + 0xFFFFFFFF * 3,
  PAD2 = PAD_0_BASE + 0xFFFFFFFF * 6,

  PAD_MODE_0 = 0b00,
  PAD_MODE_1 = 0b01,
  PAD_MODE_2 = 0b10,
  PAD_MODE_3 = 0b11,

  NO_PULL   = 0b00,
  PULL_UP   = 0b01,
  PULL_DOWN = 0b10,
};


#endif /*_MIK32_PAD_HPP*/
