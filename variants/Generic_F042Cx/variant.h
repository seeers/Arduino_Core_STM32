/*
 *******************************************************************************
 * Copyright (c) 2019, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

#define PC13 0
#define PF0 1
#define PF1 2
#define PA0	A0
#define PA1	A1
#define PA2	A2
#define PA3	A3
#define PA4	A4
#define PA5	A5
#define PA6	A6
#define PA7	A7
#define PB0	11
#define PB1	12
#define PB2	13
#define PB10 14
#define PB11 15
#define PB12 16
#define PB13 17
#define PB14 18
#define PB15 19
#define PA8	20
#define PA9	 21
#define PA10 22
#define PA11 23
#define PA12 24
#define PA13 25
#define PA14 26
#define PA15 27
#define PB3	 28
#define PB4	 29
#define PB5	 30
#define PB6	 31
#define PB7	 32
#define PF11 33
#define PB8	 34
#define PB9  35

// This must be a literal
// It is used with preprocessor tests (e.g. #if NUM_DIGITAL_PINS > 3)
// so an enum will not work.
#define NUM_DIGITAL_PINS        36

// Allow to define Arduino style alias for analog input pin number --> Ax
// If no analog pin required then NUM_ANALOG_INPUTS could not be defined
// or set to `0`
// All pins are digital, analog inputs are a subset of digital pins.
// This must be a literal
// It is used with preprocessor tests (e.g. #if NUM_ANALOG_INPUTS > 3)
// so an enum will not work.
// !!!
// !!! It must be aligned with the number of analog PinName
// !!! defined in digitalPin[] array in variant.cpp
// !!!
#define NUM_ANALOG_INPUTS       8

// They are 2 possibles way to define analog pins:
//-------------------------------------------------------------------------------------------
//   - If they are contiguous in the digitalPin array:
//     Simply defined `NUM_ANALOG_FIRST` and all pins Ax will be automatically defined.
//     It define the digital pin number of the first analog input  (i.e. which digital pin is A0)
//     First analog pin value (A0) must be greater than or equal to NUM_ANALOG_INPUTS
//     This must be a literal with a value less than or equal to MAX_ANALOG_INPUTS
//     defined in pin_arduino.h
// #define NUM_ANALOG_FIRST        0
//------------------------------------OR------------------------------------------------------
//   - If they are not contiguous in the digitalPin array:
//     Add an analogInputPin array in the variant.cpp without defining NUM_ANALOG_FIRST
//     In that case the defined PYn for analog pin have to define the Ax definition instead of
//     index in digitalPin[] array:
//     #define PA4  A14
//-------------------------------------------------------------------------------------------


// Below ADC and PWM definitions already done in the core
// Could be redefined here if needed
// ADC resolution is 10 bits
//#define ADC_RESOLUTION          10

// PWM resolution
//#define PWM_RESOLUTION          8
//#define PWM_FREQUENCY           1000
//#define PWM_MAX_DUTY_CYCLE      255

// On-board LED pin number
//#define LED_BUILTIN             x
//#define LED_GREEN               LED_BUILTIN

// On-board user button
//#define USER_BTN                x

// Below SPI and I2C definitions already done in the core
// Could be redefined here if differs from the default one
// SPI Definitions
//#define PIN_SPI_SS              10 // Default for Arduino connector compatibility
//#define PIN_SPI_MOSI            11 // Default for Arduino connector compatibility
//#define PIN_SPI_MISO            12 // Default for Arduino connector compatibility
//#define PIN_SPI_SCK             13 // Default for Arduino connector compatibility

// I2C Definitions
//#define PIN_WIRE_SDA            14 // Default for Arduino connector compatibility
//#define PIN_WIRE_SCL            15 // Default for Arduino connector compatibility

// I2C timing definitions (optional), avoid time spent to compute if defined
// * I2C_TIMING_SM for Standard Mode (100kHz)
// * I2C_TIMING_FM for Fast Mode (400kHz)
// * I2C_TIMING_FMP for Fast Mode Plus (1000kHz)
//#define I2C_TIMING_SM           0x00000000
//#define I2C_TIMING_FM           0x00000000
//#define I2C_TIMING_FMP          0x00000000

// Timer Definitions (optional)
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
//#define TIMER_TONE              TIM6
//#define TIMER_SERVO             TIM7

// UART Definitions
// Define here Serial instance number to map on Serial generic name
#define SERIAL_UART_INSTANCE    2 //ex: 2 for Serial2 (USART2)
// DEBUG_UART could be redefined to print on another instance than 'Serial'
//#define DEBUG_UART              ((USART_TypeDef *) U(S)ARTX) // ex: USART3
// DEBUG_UART baudrate, default: 9600 if not defined
//#define DEBUG_UART_BAUDRATE     x
// DEBUG_UART Tx pin name, default: the first one found in PinMap_UART_TX for DEBUG_UART
//#define DEBUG_PINNAME_TX        PX_n // PinName used for TX

// Default pin used for 'Serial' instance (ex: ST-Link)
// Mandatory for Firmata
#define PIN_SERIAL_RX           PA3
#define PIN_SERIAL_TX           PA2

// Optional PIN_SERIALn_RX and PIN_SERIALn_TX where 'n' is the U(S)ART number
// Used when user instanciate a hardware Serial using its peripheral name.
// Example: HardwareSerial mySerial(USART3);
// will use PIN_SERIAL3_RX and PIN_SERIAL3_TX if defined.
//#define PIN_SERIALn_RX          x // For U(S)ARTn RX
//#define PIN_SERIALn_TX          x // For U(S)ARTn TX
//#define PIN_SERIALLP1_RX        x // For LPUART1 RX
//#define PIN_SERIALLP1_TX        x // For LPUART1 TX

// SD card slot Definitions
// SD detect signal can be defined if required
//#define SD_DETECT_PIN           x
// SD Read/Write timeout, default value defined in STM32SD library
//#define SD_DATATIMEOUT          x

// USB Vbus sensing. Require to have Vbus pin connected to Vbus signal.
// Warning, pin is different depending on FullSpeed or High Speed mode used
// See AN4879 https://www.st.com/content/st_com/en/search.html#q=AN4879-t=resources-page=1
//#define USBD_VBUS_DETECTION_ENABLE

// If the board has external USB pullup (on DP/DM depending on speed)
// that can be controlled using a GPIO pin, define these:
//  - If the the pullup is disabled (USB detached) by default, define
//    USBD_ATTACH_PIN to the pin that, when written to
//    USBD_ATTACH_LEVEL, attaches the pullup.
//  - If the the pullup is enabled (attached) by default, define
//    USBD_DETACH_PIN to the pin that, when written to
//    USBD_DETACH_LEVEL, detaches the pullup.
//#define USBD_ATTACH_PIN x
//#define USBD_ATTACH_LEVEL LOW
//#define USBD_DETACH_PIN x
//#define USBD_DETACH_LEVEL LOW
//
// This indicates that there is an external and fixed 1.5k pullup
// on the D+ line. This define is not normally needed, since a
// fixed pullup is assumed by default. It is only required when
// the USB peripheral has an internal pullup *and* an external
// fixed pullup is present (which is actually a hardware bug, since just
// the internal pullup is sufficient and having two pullups violates the
// USB specification). In this case, defining this forces
// the "write D+ LOW"-trick to be used. In the future, it might also
// disable the internal pullups, but this is not currently implemented.
// #define USBD_FIXED_PULLUP
#ifdef __cplusplus
} // extern "C"
#endif
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #define SERIAL_PORT_MONITOR     Serial
  #define SERIAL_PORT_HARDWARE    Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
