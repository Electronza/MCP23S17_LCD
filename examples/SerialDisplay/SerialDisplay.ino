/*
  MCP23S17 LCD Library - Serial input

 Demonstrates the use a 16x2 LCD display.  The MCP23S17
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch displays text sent over the serial port
 (e.g. from the Serial Monitor) on an attached LCD.

 The LCD can be connected either to GPIO port A or B of MCP23S17
 NOTE: LCD works in 4-bit mode only and it requires 
 the following connections:

 * LCD D7 pin  to GPx7
 * LCD D6 pin  to GPx6
 * LCD D5 pin  to GPx5
 * LCD D4 pin  to GPx4
 * LCD EN pin  to GPx3
 * LCD RS pin  to GPx2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Where GPx is either GPA or GPB of MCP23S17

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi
 modified 7 Feb 2019
 by Teodor Costachioiu (https://electronza.com)

 This example code is in the public domain.

 http://electronza.com/mcp23s17-lcd-library

*/

// include the library code:
#include <MCP23S17_LCD.h>

/* The LCD library is initialized as follows:
 * MCP23S17_LCD(uint8_t rst, uint8_t cs, uint8_t PORT);
 * rst  - RST pin for MCP23S17
 * cs   - CS pin for MCP23S17 
 * PORT - GPIO port of MCP23S17, where the LCD is connected
 * PORT can be either PORT A or PORTB 
 * 
 * Example for MikroElektronika Expand click, connected via
 * Arduino Uno Click shield, in mikroBUS socket #1
 * and configured via J3 for 5V operation:
 * https://www.mikroe.com/expand-click
 * https://www.mikroe.com/arduino-uno-click-shield
 * 
 * MCP23S17_LCD lcd(A3, 10, PORTB);
*/

MCP23S17_LCD lcd(A3, 10, PORTB);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop() {
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}
