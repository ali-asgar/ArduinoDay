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
  Serial.begin(9600);
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
}


void loop() {
  // put your main code here, to run repeatedly:

  byte btn = MFS.getButton(); // Normally it is sufficient to compare the return
                              // value to predefined macros, e.g. BUTTON_1_PRESSED,
                              // BUTTON_1_LONG_PRESSED etc.
  
  if (btn)
  {
    byte buttonNumber = btn & B00111111;
    byte buttonAction = btn & B11000000;
    
    Serial.print("BUTTON_");
    Serial.write(buttonNumber + '0');
    Serial.print("_");

    if (buttonNumber == 1) { MFS.writeLeds(LED_1, ON); }
    if (buttonNumber == 2) { MFS.writeLeds(LED_2, ON); }
    if (buttonNumber == 3) { MFS.writeLeds(LED_3, ON); }
    
    if (buttonAction == BUTTON_PRESSED_IND) { 
      Serial.println("PRESSED");
    }
    else if (buttonAction == BUTTON_SHORT_RELEASE_IND) {
      Serial.println("SHORT_RELEASE");
      MFS.writeLeds(LED_ALL, OFF);
    }
    else if (buttonAction == BUTTON_LONG_PRESSED_IND) { 
      Serial.println("LONG_PRESSED");
    }
    else if (buttonAction == BUTTON_LONG_RELEASE_IND) {
      Serial.println("LONG_RELEASE");
      MFS.writeLeds(LED_ALL, OFF);
    }
  }
}
