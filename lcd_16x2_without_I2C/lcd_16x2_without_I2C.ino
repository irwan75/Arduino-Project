//  The circuit:
// * LCD RS pin to digital pin 12
// * LCD Enable pin to digital pin 11
// * LCD D4 pin to digital pin 5
// * LCD D5 pin to digital pin 4
// * LCD D6 pin to digital pin 3
// * LCD D7 pin to digital pin 2
// * LCD R/W pin to ground

// include the library code:
#include <LiquidCrystal.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};
 
void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  // create a new character
  lcd.createChar(1, smiley);
 
  // Print a message to the LCD.
  lcd.write(1); //Print custom character smiley
  lcd.print("hello, world!");
  lcd.write(1); //Print custom character smiley
}
 
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Tngi Air : ");
  lcd.setCursor(0, 1);
  // print the message at line 2
  lcd.print("Volume : ");
}
