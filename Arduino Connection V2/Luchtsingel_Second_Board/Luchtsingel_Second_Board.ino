#include <Wire.h>

int Buzzer1 = 9;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(Buzzer1, OUTPUT);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
  
   if (x == 3){
    // play the Tone
    tone(Buzzer1,1600,200);
    delay(500);
   }

   if (x == 55){
    // play the Tone
    tone(Buzzer1,200,200);
    delay(500);    
   }
}
