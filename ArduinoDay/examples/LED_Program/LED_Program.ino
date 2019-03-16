/*
 * Arduino Day 2019
 * 
 * March 16th, 2019 at New Jersey Institute of Technology
 * Organized By IEEE, ACM, ASME, GSA, Student Senate, and IEEE North Jersey Section
 *---------------------------------------------------------------------------------
 * Program Name: LED_Program.ino
 * Program 1
 * Purpose of this file: To blink LEDs in different ways
 * --------------------------------------------------------------------------------
 * Author: Ali Asgar Tashrifwala
 * Date: 03/15/2019
 *---------------------------------------------------------------------------------
 * Reference: Kashif Baig, 2015 cohesivecomputing.co.uk
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

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
}

// LED_1 is pin 13,  LED_2 is pin 12, LED_3 is pin 11, LED_4 is pin 10,  LED_ALL is all 4 pins.

void loop() {
  // put your main code here, to run repeatedly:
    MFS.writeLeds(LED_1, ON);
    //MFS.blinkLeds(LED_1, ON);
    delay(2000);
    //MFS.blinkLeds(LED_1, OFF);
    MFS.writeLeds(LED_1, OFF);
    delay(2000);
}
