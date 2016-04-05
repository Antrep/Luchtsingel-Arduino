#include <Wire.h>


// set pin numbers:
const int buttonPinOne = 4;     // the number of the first pushbutton pin
const int buttonPinTwo = 5;     // the number of the second pushbutton pin

int Buzzer1 = 9;

// variables that will change:
int buttonStateOne = 0;         // variable for reading the first pushbutton status
int buttonStateTwo = 0;         // variable for reading the second pushbutton status


void setup() {
  Wire.begin(); // join i2c bus (address optional for master)

  // initialize the piezo as output:
  pinMode(Buzzer1, OUTPUT);  
  
  // initialize the first pushbutton pin as an input:
  pinMode(buttonPinOne, INPUT);  
  
  // initialize the first pushbutton pin as an input:
  pinMode(buttonPinTwo, INPUT);     
}


void loop() {
  Wire.beginTransmission(8); // transmit to device #8

  // read the state of button1:
  buttonStateOne = digitalRead(buttonPinOne);

  // read the state of button2:
  buttonStateTwo = digitalRead(buttonPinTwo);
  
  // check if button1 is pressed
  // if button1 is pressed, buttonStateOne is set to HIGH:
  if (buttonStateOne == HIGH) {     
    byte x = 3;
    Wire.write(x);
  }   


  // check if button2 is pressed
  // if button2 is pressed, buttonStateTwo is set to HIGH
  if (buttonStateTwo == HIGH) {
    byte x = 55;
    Wire.write(x);              // sends the variable through bytes
  }


  Wire.endTransmission();    // stop transmitting
  delay(50);                 // delay to avoid bouncing
}
