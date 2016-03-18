/*
  Button

Turns on and off a light emitting diode(LED) connected to digital  
pin 13, when pressing a pushbutton attached to pin 7. 


The circuit:
* LED attached from pin 13 to ground 
* pushbutton attached to pin 2 from +5V
* 10K resistor attached to pin 2 from ground

* Note: on most Arduinos there is already an LED on the board
attached to pin 13.


created 2005
by DojoDave <http://www.0j0.org>
modified 17 Jun 2009
by Tom Igoe

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPinTwo = 2;     // the number of the pushbutton pin
const int buttonPinFour = 4;    // the number of the pushbutton pin
int Buzzer1 = 9;

// variables will change:
int buttonStateTwo = 0;         // variable for reading the pushbutton status
int buttonStateFour = 0;        // variable for reading the pushbutton status

void setup() {
  // initialize the piezo as output:
  pinMode(Buzzer1, OUTPUT);  
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinTwo, INPUT);     
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinFour, INPUT);     
}

void loop(){
  // read the state of the first pushbutton value:
  buttonStateTwo = digitalRead(buttonPinTwo);

  // check if the first pushbutton is pressed.
  // if it is, then buttonStateTwo is set to HIGH:
  if (buttonStateTwo == HIGH) {     
    // play the Music
      tone(Buzzer1,1600,200);
      delay(500);
  } 

  
  // read the state of the second pushbutton value:
  buttonStateFour = digitalRead(buttonPinFour);
  
  // check if the second pushbutton is pressed.
  // if it is, then buttonStateFour is set to HIGH:
  if (buttonStateFour == HIGH) {     
    // play the Music
      tone(Buzzer1,200,200);
      delay(500);
}
}
