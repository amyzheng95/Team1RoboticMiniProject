/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
// int servo=3;

int pos = 0;    // variable to store the servo position
 const int input = A1;
 const int input2 = A0;
 double voltage1;
 double voltage2;

void setup() {
 // pinMode(servo,OUTPUT);
  Serial.begin(9600);

  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage1 = sensorValue*(1.0/203.9);
  Serial.println(sensorValue);
  
  int sensorValue2 = analogRead(A1);
  float voltage2 = sensorValue2*(1.0/203.9);
  Serial.println(sensorValue2);
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 10; pos >= 180; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}

