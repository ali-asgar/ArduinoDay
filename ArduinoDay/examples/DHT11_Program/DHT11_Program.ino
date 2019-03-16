/*
 * Arduino Day 2019
 * 
 * March 16th, 2019 at New Jersey Institute of Technology
 * Organized By IEEE, ACM, ASME, GSA, Student Senate, and IEEE North Jersey Section
 *---------------------------------------------------------------------------------
 * Program Name: DHT11_Program.ino
 * Program 3
 * Purpose of this file: To blink LEDs in different ways
 * --------------------------------------------------------------------------------
 * Author: Ali Asgar Tashrifwala
 * Date: 03/15/2019
 *---------------------------------------------------------------------------------
 * Reference 1: www.brainy-bits.com/dht11-tutorial/
 * Reference 2: Kashif Baig, 2015 cohesivecomputing.co.uk
 * Document: https://www.mpja.com/download/hackatronics-arduino-multi-function-shield.pdf
 * Libraries: http://files.cohesivecomputing.co.uk/Multi-function-shield-library-bundle.zip
 * Programs: http://files.cohesivecomputing.co.uk/Hackatronics-Using-Arduino-Multi-function-Shield.zip
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

#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
#include "dht.h"
 
dht DHT;
 
void setup(){
  
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
 
  Serial.begin(9600);
  delay(500);     //Delay to let system boot
  Serial.println("Temperature & Humidity Values\n\n");
  delay(1000);    //Wait before accessing Sensor
}
 
void loop(){
 
    DHT.read11(A5); // Analog Pin sensor is connected to A5
    
    Serial.print("Current Humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("°C  ");
    
    MFS.write("Temp");
    delay(1000);
    MFS.write(DHT.temperature, 2);  // display to 2 decimal places.
    delay(1000);
    MFS.write("Humi");
    delay(1000);
    MFS.write(DHT.humidity, 2);  // display to 2 decimal places.
    delay(1000);
}
