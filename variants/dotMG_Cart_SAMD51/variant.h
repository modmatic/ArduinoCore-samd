/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_DOTMG_CART_SAMD51_
#define _VARIANT_DOTMG_CART_SAMD51_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK        (F_CPU)

#define VARIANT_GCLK0_FREQ (F_CPU)
#define VARIANT_GCLK1_FREQ (48000000ul)
#define VARIANT_GCLK2_FREQ (100000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (37ul)
#define NUM_DIGITAL_PINS     (22ul)
#define NUM_ANALOG_INPUTS    (9ul)
#define NUM_ANALOG_OUTPUTS   (2ul)
#define analogInputToDigitalPin(p)  (((p) >= 0 && (p) < NUM_ANALOG_INPUTS) ? PIN_A0 + (p) : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LEDs
#define PIN_LED_13           (13ul)
#define PIN_LED              PIN_LED_13
#define LED_BUILTIN          PIN_LED_13

// Non-pin
#define PIN_NONE             (37)

/*
 * Analog pins
 */
#define PIN_A0               (0ul)
#define PIN_A1               (1ul)
#define PIN_A2               (2ul)
#define PIN_A3               (3ul)
#define PIN_A4               (4ul)
#define PIN_A5               (5ul)
#define PIN_A6               (6ul)
#define PIN_A7               (7ul)
#define PIN_A8               (8ul)
#define PIN_DAC0             PIN_A2
#define PIN_DAC1             PIN_A3

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6 ;
static const uint8_t A7 = PIN_A7 ;
static const uint8_t A8 = PIN_A8 ;

static const uint8_t DAC0 = PIN_DAC0;
static const uint8_t DAC1 = PIN_DAC1;

#define ADC_RESOLUTION 12

/*
 * Extension pins
 */
#define PIN_X0               (2ul)
#define PIN_X1               (8ul)
#define PIN_X2               (9ul)
#define PIN_X3               (10ul)
#define PIN_X4               (11ul)
#define PIN_X5               (12ul)
#define PIN_X6               (14ul)
#define PIN_X7               (15ul)

static const uint8_t X0 = PIN_X0;
static const uint8_t X1 = PIN_X1;
static const uint8_t X2 = PIN_X2;
static const uint8_t X3 = PIN_X3;
static const uint8_t X4 = PIN_X4;
static const uint8_t X5 = PIN_X5;
static const uint8_t X6 = PIN_X6;
static const uint8_t X7 = PIN_X7;

/*
 * Serial interfaces
 */

// Serial1
#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_2)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)

/*
 * ATN represents the slave/chip select pin for the first SPI module.
 *
 * https://forum.arduino.cc/index.php?topic=330088.msg2280038#msg2280038
 */
#define PIN_ATN              (8ul)
static const uint8_t ATN = PIN_ATN;

/*
 * SPI Interfaces
 */

#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MOSI         (10ul)
#define PIN_SPI_MISO         (11ul)
#define PIN_SPI_SCK          (12ul)
#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_0_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_2

static const uint8_t SS   = PIN_ATN ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */

#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (14ul)
#define PIN_WIRE_SCL         (15ul)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler
#define WIRE_IT_HANDLER_0    SERCOM3_0_Handler
#define WIRE_IT_HANDLER_1    SERCOM3_1_Handler
#define WIRE_IT_HANDLER_2    SERCOM3_2_Handler
#define WIRE_IT_HANDLER_3    SERCOM3_3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */

#define PIN_USB_HOST_ENABLE PIN_NONE  // Not implemented on board
#define PIN_USB_DM          (23ul)
#define PIN_USB_DP          (24ul)

/*
 * I2S Interfaces
 */

#define I2S_INTERFACES_COUNT 0
#define I2S_DEVICE           0
// no I2S on SAMD51G

/*
 * QSPI Flash
 */

#define EXTERNAL_FLASH_DEVICES  W25Q16JV_IQ
#define EXTERNAL_FLASH_USE_QSPI

#define PIN_QSPI_SCK (27ul)
#define PIN_QSPI_CS  (28ul)
#define PIN_QSPI_IO0 (29ul)
#define PIN_QSPI_IO1 (30ul)
#define PIN_QSPI_IO2 (31ul)
#define PIN_QSPI_IO3 (32ul)

#if !defined(VARIANT_QSPI_BAUD_DEFAULT)
  #define VARIANT_QSPI_BAUD_DEFAULT 5000000
#endif

/*
 * SPI EEPROM
 */

#define PIN_SPI_EEPROM_MOSI  (33ul)
#define PIN_SPI_EEPROM_MISO  (34ul)
#define PIN_SPI_EEPROM_SCK   (35ul)
#define PIN_SPI_EEPROM_SS    (36ul)
#define PERIPH_SPI_EEPROM    sercom2
#define PAD_SPI_EEPROM_TX    SPI_PAD_0_SCK_1
#define PAD_SPI_EEPROM_RX    SERCOM_RX_PAD_2
#define SPI_SETTINGS_EEPROM  SPISettings(20000000, MSBFIRST, SPI_MODE0)

/*
 * SPI Display
 *
 * NOTE: The physical pin attached to MOSI is actually being used for the
 * QSPI flash, but it is not needed for this SERCOM, since the display only
 * needs to do output. We still specify PAD_SPI_DISP_RX only to satisfy
 * SPIClass constructors.
 */

#define PIN_SPI_DISP_MOSI    (6ul)
#define PIN_SPI_DISP_MISO    PIN_NONE  // Not used - output-only
#define PIN_SPI_DISP_SCK     (7ul)
#define PIN_SPI_DISP_SS      (16ul)
#define PIN_DISP_DC          (17ul)
#define PIN_DISP_RST         (-1)
#define PIN_DISP_LED         PIN_LED
#define PERIPH_SPI_DISP      sercom4
#define PAD_SPI_DISP_TX      SPI_PAD_0_SCK_1
#define PAD_SPI_DISP_RX      SERCOM_RX_PAD_2  // Not used - output-only
#define SPI_SETTINGS_DISP    SPISettings(15000000, MSBFIRST, SPI_MODE0)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial1;

#endif

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
#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_DOTMG_CART_SAMD51_ */
