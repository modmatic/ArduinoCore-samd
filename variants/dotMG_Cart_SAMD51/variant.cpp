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

#include "variant.h"

/*
 * Pins descriptions
 */

const PinDescription g_APinDescription[]=
{
/* ~      D0  / A0 / RX / START_BTN  */ {PORTA, 6, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG | PIN_ATTR_PWM_E | PIN_ATTR_TIMER, ADC_Channel6, TC1_CH0, TC1_CH0, EXTERNAL_INT_6},  // SERCOM0/PAD[2]
/* ~      D1  / A1 / TX / SELECT_BTN */ {PORTA, 4, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG | PIN_ATTR_PWM_E | PIN_ATTR_TIMER, ADC_Channel4, TC0_CH0, TC0_CH0, EXTERNAL_INT_4},  // SERCOM0/PAD[0]
/*   X0 / D2  / A2 / DAC 0           */ {PORTA, 2, PIO_ANALOG, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2},
/* ~      D3  / A3 / DAC 1 / SPK     */ {PORTA, 5, PIO_ANALOG, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG | PIN_ATTR_PWM_E | PIN_ATTR_TIMER, ADC_Channel5, TC0_CH1, TC0_CH1, EXTERNAL_INT_5},
/*        D4  / A4 / DOWN_BTN        */ {PORTB, 2, PIO_ANALOG, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG, ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2},
/*        D5  / A5 / LEFT_BTN        */ {PORTB, 3, PIO_ANALOG, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG, ADC_Channel15, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3},
/*        D6  / A6 / DISP_MOSI       */ {PORTB, 8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG, ADC_Channel2, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8},  // SERCOM4/PAD[0]
/*        D7  / A7 / DISP_SCK        */ {PORTB, 9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG, ADC_Channel3, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9},  // SERCOM4/PAD[1]
/* ~ X1 / D8  / A8 / SS              */ {PORTA, 7, PIO_ANALOG, PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG | PIN_ATTR_PWM_E | PIN_ATTR_TIMER, ADC_Channel7, TC1_CH1, TC1_CH1, EXTERNAL_INT_7},
/* ~ X2 / D9                         */ {PORTA, 0, PIO_DIGITAL, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_E | PIN_ATTR_TIMER, No_ADC_Channel, TC2_CH0, TC2_CH0, EXTERNAL_INT_0},
/* ~ X3 / D10 /      MOSI            */ {PORTA, 16, PIO_SERCOM, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F | PIN_ATTR_TIMER_ALT, No_ADC_Channel, TCC1_CH0, TCC1_CH0, EXTERNAL_INT_0},  // SERCOM1/PAD[0]
/* ~ X4 / D11 /      MISO            */ {PORTA, 18, PIO_SERCOM, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F | PIN_ATTR_TIMER_ALT, No_ADC_Channel, TCC1_CH2, TCC1_CH2, EXTERNAL_INT_2},  // SERCOM1/PAD[2]
/* ~ X5 / D12 /      SCK             */ {PORTA, 17, PIO_SERCOM, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F | PIN_ATTR_TIMER_ALT, No_ADC_Channel, TCC1_CH1, TCC1_CH1, EXTERNAL_INT_1},  // SERCOM1/PAD[1]
/* ~      D13 /      LED / DISP_LED  */ {PORTA, 15, PIO_PWM, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F | PIN_ATTR_TIMER_ALT, No_ADC_Channel, TCC2_CH1, TCC2_CH1, EXTERNAL_INT_15},
/* ~ X6 / D14 /      SDA             */ {PORTA, 22, PIO_SERCOM, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F | PIN_ATTR_TIMER_ALT, No_ADC_Channel, TCC1_CH6, TCC1_CH6, EXTERNAL_INT_6},  // SERCOM3/PAD[0]
/* ~ X7 / D15 /      SCL             */ {PORTA, 23, PIO_SERCOM, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F | PIN_ATTR_TIMER_ALT, No_ADC_Channel, TCC1_CH7, TCC1_CH7, EXTERNAL_INT_7},  // SERCOM3/PAD[1]
/* ~      D16 /      DISP_SS         */ {PORTA, 1, PIO_DIGITAL, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_E | PIN_ATTR_TIMER, No_ADC_Channel, TC2_CH1, TC2_CH1, EXTERNAL_INT_1},
/*        D17 /      DISP_DC         */ {PORTA, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11},
/* ~      D18 /      UP_BTN          */ {PORTA, 20, PIO_DIGITAL, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F | PIN_ATTR_TIMER_ALT, No_ADC_Channel, TCC1_CH4, TCC1_CH4, EXTERNAL_INT_4},
/* ~      D19 /      RIGHT_BTN       */ {PORTA, 21, PIO_DIGITAL, PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F | PIN_ATTR_TIMER_ALT, No_ADC_Channel, TCC1_CH5, TCC1_CH5, EXTERNAL_INT_5},
/*        D20 /      A_BTN           */ {PORTB, 22, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*        D21 /      B_BTN           */ {PORTB, 23, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (22) AREF                       */ {PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (23) USBDM                      */ {PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (24) USBDP                      */ {PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (25) SWDCLK                     */ {PORTA, 30, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (26) SWDIO                      */ {PORTA, 31, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (27) QSPI: SCK                  */ {PORTB, 10, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (28) QSPI: SS                   */ {PORTB, 11, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (29) QSPI: IO0                  */ {PORTA, 8, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (30) QSPI: IO1                  */ {PORTA, 9, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (31) QSPI: IO2                  */ {PORTA, 10, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (32) QSPI: IO3                  */ {PORTA, 11, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (33) EEPROM: MOSI               */ {PORTA, 12, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},  // SERCOM2/PAD[0]
/*   (34) EEPROM: MISO               */ {PORTA, 14, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},  // SERCOM2/PAD[2]
/*   (35) EEPROM: SCK                */ {PORTA, 13, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},  // SERCOM2/PAD[1]
/*   (36) EEPROM: SS                 */ {PORTA, 19, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
/*   (37) Non-pin                    */ {NOT_A_PORT, -1, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC0, TC1, TC2, TC3 } ;
const uint32_t GCLK_CLKCTRL_IDs[TCC_INST_NUM+TC_INST_NUM] = { TCC0_GCLK_ID, TCC1_GCLK_ID, TCC2_GCLK_ID, TC0_GCLK_ID, TC1_GCLK_ID, TC2_GCLK_ID, TC3_GCLK_ID } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM0_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM0_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM0_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM0_3_Handler()
{
  Serial1.IrqHandler();
}
