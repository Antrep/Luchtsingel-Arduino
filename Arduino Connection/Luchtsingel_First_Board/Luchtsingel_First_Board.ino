#include <Wire.h>


// set pin numbers:
const int buttonPinFour = 4;     // the number of the first pushbutton pin
const int buttonPinFive = 5;     // the number of the second pushbutton pin

int Buzzer1 = 13;


// variables that will change:
int buttonStateFour = 0;         // variable for reading the first pushbutton status
int buttonStateFive = 0;         // variable for reading the second pushbutton status



void setup() {
  Wire.begin(); // join i2c bus (address optional for master)

  // initialize the piezo as output:
  pinMode(Buzzer1, OUTPUT);  
  
  // initialize the first pushbutton pin as an input:
  pinMode(buttonPinFour, INPUT);  
  
  // initialize the first pushbutton pin as an input:
  pinMode(buttonPinFive, INPUT);     
}


void loop() {
  Wire.beginTransmission(8); // transmit to device #8

  // read the state of the first pushbutton value:
  buttonStateFour = digitalRead(buttonPinFour);

  // read the state of the first pushbutton value:
  buttonStateFive = digitalRead(buttonPinFive);
  
  // check if the first pushbutton is pressed.
  // if it is, then buttonStateFour is set to HIGH:
  if (buttonStateFour == HIGH) {     
    byte x = 3;
    Wire.write("x is ");
    Wire.write(x);
        
    // play the Tone
    tone(Buzzer1,200,200);
    delay(500);
  }   


  
  // check is the second pushbutton is pressed
  // if it is, then buttonStateFive is set to HIGH
  if (buttonStateFive == HIGH) {
    byte y = 55;
    Wire.write("y is ");        // sends a string through bytes
    Wire.write(y);              // sends the variable through bytes

    // play the Tone
    tone(Buzzer1,1600,200);
    delay(500);
  }
  else
  {
    byte x = 0;
    byte y = 0;
    byte z = 0;
    
    Wire.write("x is ");        // sends a string through bytes
    Wire.write(x);              // sends the variable through bytes

    Wire.write("y is ");
    Wire.write(y);
    
    Wire.write("z is ");
    Wire.write(z);

    delay(500);
  }

  Wire.endTransmission();    // stop transmitting
  delay(150);
}
