#include <Wire.h>



void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) {  // loop through all but the last
    char c = Wire.read();         // receive byte as a character
    Serial.println(c);              // print the character
    
  int x = Wire.read();            // receive byte as an integer
    if (x){
      Serial.println("X is ");
      Serial.println(x);              // print the integer
      }


  int y = Wire.read();
    if(y){
      Serial.println("Y is ");
      Serial.println(y);              // print the integer
      }


  int z = Wire.read();
    if (z){
      Serial.println("Z is ");
      Serial.println(z);              // print the integer
      }
  }
}
