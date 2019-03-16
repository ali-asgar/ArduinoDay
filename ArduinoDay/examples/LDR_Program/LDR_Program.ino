/*
 * Arduino Day 2019
 * 
 * March 16th, 2019 at New Jersey Institute of Technology
 * Organized By IEEE, ACM, ASME, GSA, Student Senate, and IEEE North Jersey Section
 *---------------------------------------------------------------------------------
 * Program Name: LDR_Program.ino
 * Program 4
 * Purpose of this file: To blink LEDs in different ways
 * --------------------------------------------------------------------------------
 * Author: Ali Asgar Tashrifwala
 * Date: 03/15/2019
 *---------------------------------------------------------------------------------
 *
 * Things to note:
 *
 * In Arduino IDE
 *   - Make sure to go to Go to Tools -> Board -> “Arduino/Genuino Uno”
 *   - Make sure to go to Tools -> Port: -> Select port with Arduino/Genuino Uno
 * Connections
 *   - Connect Arduino Uno with the computer using USB A to B cable.
 *   - Attach Multipurpose Shield on top of Arduino Uno
 * ---------------------------------------------------------------------------------
 */

int LDRPin = A0;   // select the input pin for LDR
int LDRValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);   //Serial port baudrate for communication
  Serial.println("Dark is near to 0 and Bright is near to 1024");
  Serial.println("LDR Values\n\n");

}
void loop() {
  LDRValue = analogRead(LDRPin);  // read the value from the sensor
  Serial.print("LDR Value = ");
  Serial.println(LDRValue);  //prints the values coming from the sensor on the screen
  delay(1000);

}
