#include <Arduino.h>
#include<Keyboard.h>
#include<Mouse.h>
#include "Adafruit_FreeTouch.h"

Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A1, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_3 = Adafruit_FreeTouch(A10, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_4 = Adafruit_FreeTouch(A7, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_5  = Adafruit_FreeTouch(A8, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_6 = Adafruit_FreeTouch(A9, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);

#define KEY_UP_ARROW      0xDA
#define KEY_DOWN_ARROW    0xD9
#define KEY_LEFT_ARROW    0xD8
#define KEY_RIGHT_ARROW   0xD7

void setup() {
  Serial.begin(115200);
  

  //  while (!Serial);
  Serial.println("FreeTouch test");
  // initialize digital pin LED_BUILTIN as an output.
 

  if (! qt_1.begin())
    Serial.println("Failed to begin qt");
  if (! qt_2.begin())
    Serial.println("Failed to begin qt");
  if (! qt_3.begin())
    Serial.println("Failed to begin qt");
  if (! qt_4.begin())
    Serial.println("Failed to begin qt");
  if (! qt_5.begin())
    Serial.println("Failed to begin qt");
  if (! qt_6.begin())
    Serial.println("Failed to begin qt");

    Keyboard.begin();
    Mouse.begin();

}

int qt_Threshold = 850;

void loop() {
  int qt1 = 0;
  int qt2 = 0;
  int qt3 = 0;
  int qt4 = 0;
  int qt5 = 0;
  int qt6 = 0;
  int qt7 = 0;

  qt1 = qt_1.measure();
  Serial.print(qt1);
  Serial.print(",");

  qt2 = qt_2.measure();
  Serial.print(qt2);
  Serial.print(",");

  qt3 = qt_3.measure();
  Serial.print(qt3);
  Serial.print(",");

  qt4 = qt_4.measure();
  Serial.print(qt4);
  Serial.print(",");

  qt5 = qt_5.measure();
  Serial.print(qt5);
  Serial.println();

  qt6 = qt_6.measure();
  Serial.print(qt6);
  Serial.println();


  if (qt1 >= qt_Threshold) {
    Keyboard.write(KEY_UP_ARROW);
    delay(100);
    
  }
  if (qt2 >= qt_Threshold) {
    Keyboard.write(KEY_DOWN_ARROW);
    delay(100);
   
  }
  if (qt3 >= qt_Threshold) {
    Keyboard.write(KEY_RIGHT_ARROW);
    delay(100);
    
  }
  if (qt4 >= qt_Threshold) {
    Keyboard.write(KEY_LEFT_ARROW);
    delay(100);
    
  }
  if (qt5 >= qt_Threshold) {
    Keyboard.write(' ');
    delay(100);
    
  }
  if (qt6 >= qt_Threshold) {
    Mouse.click(MOUSE_LEFT);
    delay(100);
    
  }
  
}
