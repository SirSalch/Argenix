![image alt](https://github.com/SirSalch/Argenix/blob/main/Repository%20content/Header.png?raw=true) <br> <br>

**( 🛠 В разработке ) Аргеникс** — это открытая программно-аппаратная экосистема для разработки электронных устройств на базе микроконтроллеров с архитектурой RISC-V, предоставляющая линейку фирменных отладочных плат. Экосистема предлагает лаконичный, интуитивно понятный синтаксис, скрывая сложную рутину работы с периферией под капотом и позволяя полностью сосредоточиться на логике приложения. <br>

Проект построен на принципах шаблонного метапрограммирования и Zero-Cost Abstractions используя современный инструментарий C++. Такой подход позволяет перенести до 80% вычислений с вычислительных мощностей микроконтроллера на этап компиляции (ПК разработчика).

Все параметры обрабатываются еще до генерации бинарного файла, поэтому на самом контроллере код схлопывается в прямую запись заранее рассчитанных констант в регистры. Такой подход обеспечивает максимальное быстродействие и радикально экономит FLASH/EEPROM память и RAM по сравнению с классическими тяжеловесными SDK на чистом Си.

 
## Бенчмарк
| Платформа  | Чип                       | Прошивка          | Занимаемая ПЗУ | Занимаемая ОЗУ |
| :---:      | :---:                     | :---:             | :---:          | :---:          |
| ARGENIX    | МИК32 (К1948ВК015)        | Led Blink         | 104 Байт       | 0 Байт         |
| Arduino    | ATmega328P                | Led Blink         | 924 Байт       | 9 Байт         |
| STM32 Cube | STM32F103C8T6 (Blue Pill) | Led Blink         | 1240 Байт      | 34 Байт        |

## Пример Blink
```c++
#include <ARGENIX.hpp>
Pin led(PIN_1_5);

int main() {
  led.setup(OUTPUT);

  while (1) {
    led.set(HIGH);
    delay(300);
    led.set(LOW);
    delay(300);
  }
}
```
```
Вес прошивки ЕЕПРОМ:104 байт,  ОЗУ:0 байт
```
### или
```c++
#include <ARGENIX.hpp>

int main() {
  PIN_1_5.setup(OUTPUT);

  while (1) {
    PIN_1_5.set(HIGH);
    delay(300);
    PIN_1_5.set(LOW);
    delay(300);
  }
}
```
```
Вес прошивки ЕЕПРОМ:104 байт,  ОЗУ:0 байт
```

## Пример генерации ШИМ
![image alt](https://github.com/SirSalch/Argenix/blob/main/Repository%20content/PWM.png?raw=true) <br>
```c++
#include <ARGENIX.hpp>
Pwm motor(PWM1);

int main() {
  motor.setup();
  motor.generate(CH1, 500/*50% Заполнения ШИМ*/);

  while (1) { }
}
```
```
Вес прошивки ЕЕПРОМ:100 байт,  ОЗУ:0 байт
```

## Пример передачи данных по I2C
![image alt](https://github.com/SirSalch/Argenix/blob/main/Repository%20content/I2C.png?raw=true) <br>
```c++
#include <ARGENIX.hpp>

int main() {
  I2C_0.init();
  I2C_0.send(0x27/*Адрес устройства*/, 0x05/*Данные*/);

  while(1) {

  }
}
```
```
Вес прошивки ЕЕПРОМ:120 байт,  ОЗУ:0 байт
```

## Начало работы (Ubuntu)
> [!NOTE]
> На текущий момент разработки установка тулчейнов, сборка проекта и прошивка выполняются в ручную под ubuntu.
> В будущем будет реализовано удобное графическое окружение для vsCode, с автоматической установкой и настройками под различные ОС

 

### Установка тулчейна 
Скачайте openOCD для связи с JTAG отладчиком
``` bash
sudo apt install openocd
```
Установите gcc компилятор под микроконтроллеры на RISC-V архитектуре
``` bash
sudo apt install gcc-riscv64-unknown-elf
```
Скачайте python3 и библиотеки для него
``` bash
sudo apt install python3
sudo apt install python3-usb
sudo apt install libusb-1.0-0
```
Устновите cMake
``` bash
sudo apt install cmake build-essential
```
 
### Установка ARGENIX
Перейдите в директорию куда хотите клонировать реаозиторий
``` bash
cd <Ваш путь к желаемой директории>
```
Клонируйте репозиторий ARGENIX
``` bash
git clone https://github.com/SirSalch/Argenix.git
```
 

### Сборка проекта
Перейдите в директорию build
``` bash
cd Project/build
```
Запустите сборку проекта выполнив
``` bash
cmake ..
```
 

### Компиляция 
Перейдите в директорию build
``` bash
cd Project/build
```
Выполните компиляцию
``` bash
make
```
 

### Загрузка прошивки
Подключите плату к компьютеру  

Нажмите кнопку "MODE" на плате для перехода в JTAG режим (Для отладочной платы "Микрон Старт") 

Перейдите в директорию eeprom загрузчика
``` bash
cd Project/argentix/loaders/eeprom_loader
```
Запустите скрипт загрузчика
``` bash
python3 eeprom-loader.py
```
