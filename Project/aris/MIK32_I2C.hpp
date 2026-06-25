#ifndef _MIK32_I2C_HPP_
#define _MIK32_I2C_HPP_

#include <stdint.h>
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


#define I2C_0_BASE 0x00083800

// Карта регистров
struct I2c_RegMap {
  volatile uint32_t CR1;            // Регистр управления 1
  volatile uint32_t CR2;           // Регистр управления 2
  volatile uint32_t OAR1;         // Регистр адреса 1
  volatile uint32_t OAR2;        // Регистр адреса 2
  volatile uint32_t TIMINGR;    // Настройка временных ограничений
  uint32_t reserved_0;         // Зарезервировано
  volatile uint32_t ISR;      // Флаги прерываний
  volatile uint32_t ICR;     // Сброс флагов прерываний
  uint32_t reserved_1;      // Зарезервировано
  volatile uint32_t RXDR;  // Принятые данные
  volatile uint32_t TXDR; // Передаваемые данные
};

#define I2C_0_REG ((I2c_RegMap*)I2C_0_BASE)


// Класс I2C
template<uintptr_t i2cAddress, uintptr_t padAddress, uint8_t padMode, uint8_t sdaPinNumber, uint8_t sclPinNumber, uint32_t clkMask>
class I2c {
public:
  static void setClocking(bool state) {
    (state ? APB->CLK_PERIPHERY_SET : APB->CLK_PERIPHERY_CLEAR) = clkMask; 
  }

  static void enable() {
    i2c()->CR1 |= 1; 
  }

  static void disable() {
    i2c()->CR1 &= ~1;
  }

  static void start() {
    i2c()->CR2 |= 1 << 13;
  }
  
  static void stop() {
    i2c()->CR2 |= 1 << 14;
  }

  static void setupGpio() {
    pad()->CFG  |= (padMode << (9 * 2)) | (padMode << (10 * 2));
    pad()->PUPD |= (PULL_UP << (sdaPinNumber * 2)) | (PULL_UP << (sclPinNumber * 2));
  }

  static void setupTimings(uint8_t prescaler, uint8_t sclDel, uint8_t sdaDel, uint8_t sclH, uint8_t sclL) {
    i2c()->TIMINGR =
      (prescaler << 28) |     // PRESC
      (sclDel << 20)    |    // SCLDEL
      (sdaDel << 16)    |   // SDADEL
      (sclH << 8)       |  // SCLH
      (sclL << 0);        // SCLL
  }

  static void setData(uint8_t data) {
    i2c()->TXDR = data;
  }

  static void init() {
    setClocking(true);
    setupGpio();

    setupTimings(
      5,      // PRESC
      15,    // SCLDEL
      15,   // SDADEL
      15,  // SCLH
      15  // SCLL
    );

    enable();
  }

  static void send(uint8_t address, uint8_t data) {
    i2c()->TXDR = data;
    i2c()->CR2 = (address << 1/*SLAVE_ADDRESS*/) | (1 << 16/*NBYTES*/) | (1 << 25/*AUTOEND*/) | (1 << 13/*START*/);
  }

private:
  static constexpr inline auto i2c() { return reinterpret_cast<I2c_RegMap*> (i2cAddress); }
  static constexpr inline auto pad() { return reinterpret_cast<PortControl_RegMap*> (padAddress); }
};

// I2C модули
static I2c
 <I2C_0_BASE,      // Базовый адрес модуля
  PAD_0_BASE,     // Адрес ПАД контроллера
  PAD_MODE_1,    // Номер режима альтернативной функции
  9,            // Номер GPIO пина для SDA
  10,          // Номер GPIO пина для SCL
  CLK_I2C_0>  // Маска тактирования
I2C_0;

#endif /* _MIK32_I2C_HPP_ */