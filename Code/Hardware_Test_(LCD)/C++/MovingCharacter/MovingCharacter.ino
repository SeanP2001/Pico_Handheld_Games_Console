/*
 * Program to move a box character around the screen
 * 
 * Controls:
 *  A     - Jump
 *  Left  - Move Left
 *  Right - Move Right
 * 
 * Author: Sean Price
 */


#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "Colours.h"
#include "Character.h"

// -------------------------------- D I S P L A Y   V A R I A B L E S --------------------------------
#define TFT_DC 15
#define TFT_CS 13
#define TFT_MOSI 7
#define TFT_CLK 6
#define TFT_RST 14
#define TFT_MISO 4

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// --------------------------------- B U T T O N   V A R I A B L E S ---------------------------------
#define upButton 17
#define downButton 19
#define leftButton 16
#define rightButton 18
#define aButton 21
#define bButton 20

// ---------------------------------  O T H E R   V A R I A B L E S  ---------------------------------
// Character(int _colour, int _width, int _height, int _xPos, int _yPos, int _jumpHeight, int _jumpDuration)
Character character(RED, 10, 20, 155, 175, 30, 1500);

// -------------------------------------------- S E T U P --------------------------------------------
void setup() 
{
  Serial.begin(9600);

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(aButton, INPUT_PULLUP);
  pinMode(bButton, INPUT_PULLUP);
 
  tft.begin();
  tft.setRotation(2);
  tft.fillScreen(BLACK);
  character.draw();

  delay(1000);
}


// --------------------------------------------- M A I N ---------------------------------------------
void loop(void) 
{
  //character.drawBlank();
  
  if(digitalRead(aButton) == 0)                                         // If the a button is being pressed
  {
    while (digitalRead(aButton) == 0)
    {
      
    }
    if (!character.jumping)
    {
      character.jump();
    } 
  }
  else if(digitalRead(leftButton) == 0)                                      // If the left button is being pressed
  {
    character.moveLeft();
  }
  else if(digitalRead(rightButton) == 0)                                     // If the right button is being pressed
  {
    character.moveRight();
  }

  character.updatePos();
  
  character.draw();
  
  Serial.println(character.yPos);

  delay(30);
}
