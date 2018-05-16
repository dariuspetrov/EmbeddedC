
/*
1602a LiquidCrystal Library

Demonstrates the use a 16x2 LCD display. The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver. There are many of them out there, and you can usually tell them by the 16-pin interface. This sketch prints "Hello World!" to the LCD and shows the time since the sketch started, in seconds.

The circuit:

* LCD RS pin to digital pin 12
* LCD Enable pin to digital pin 11
* LCD D4 pin to digital pin 5
* LCD D5 pin to digital pin 4
* LCD D6 pin to digital pin 3
* LCD D7 pin to digital pin 2
* LCD R/W pin to ground
* 10K variable resistor:
* ends to +5V and ground
* wiper to LCD VO pin (pin 3)
*/

// include the library code:
#include <LiquidCrystal.h>

// Initialize the library with the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
// set up the LCD's number of columns and rows
lcd.begin(16, 2);
// Print a message to the LCD
lcd.print("I see you :)");
pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
// set the cursor to column 0, line 1
// (line 1 is the second row, since counting begins with 0)
lcd.setCursor(0, 1);
for (int positionCounter = 0; positionCounter < 12; positionCounter++) {
    // scroll one position right:
    digitalWrite(LED_BUILTIN, LOW);
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(900);
    
    
  }
for (int positionCounter = 0; positionCounter < 12; positionCounter++) {
    // scroll one position right:
    digitalWrite(LED_BUILTIN, HIGH);
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(900);
   
}
  
     // turn the LED on (HIGH is the voltage level)
                       // wait for a second
 //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
// print the number of seconds since reset:
}
