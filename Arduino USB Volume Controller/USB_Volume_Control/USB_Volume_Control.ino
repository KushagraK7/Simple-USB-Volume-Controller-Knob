/*
 * Arduino code to control the volume of a computer with the help of a rotary encoder connected to an ATMEGA32U4
 * microcontroller.
 * 
 * Made by: KushagraK7: https://www.instructables.com/member/KushagraK7/
 * 
 * An AutoHotkey script runs in the computer which is used to vary the volume using a set of keys.
 * In the example, pressing Ctrl+Alt+Left Arrow reduces the volume and pressing Ctrl+Alt+Right Arrow increases it.
 */
#include<Keyboard.h>

//Input pins for rotary encoder.
#define InA A0
#define InB A1

int c = 0;
int multi = 5;//This variable defines the number of steps the rotary encoder will make to change the volume by 1.

int AS;
int ALS;

void setup() {
  // put your setup code here, to run once:

  pinMode(InA, INPUT_PULLUP);
  pinMode(InB, INPUT_PULLUP);

  Serial.begin(9600);
  
  Keyboard.begin();
            
  ALS = digitalRead(InA);
}

void loop() {
  // put your main code here, to run repeatedly:

  AS = digitalRead(InA);

  if(AS != ALS)
  {
  
  if(digitalRead(InB) != AS) c++;
  
  else c--;
  }

  ALS = AS;

  if(c >= multi)
  {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.releaseAll();
    c = 0;
  }

  if(c <= -multi)
  {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.releaseAll();
    c = 0;
  }
}
