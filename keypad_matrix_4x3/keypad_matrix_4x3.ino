#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  // Robojax 4x3 keypad test
  Serial.begin(9600);
  Serial.println("Robojax 4x3 keypad");
}
  
void loop(){
  // Robojax 4x3 keypad test
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
    Serial.println(key);
  } 
   // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.
  if (key =='4'){
    // if key matches what you are looking for
    Serial.println("Key 4 is pressed");
  } 

}
