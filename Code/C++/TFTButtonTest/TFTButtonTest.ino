/*
 * Program to check which button is pressed and display it on the ILI9341 screen.
 * 
 * Author: Sean Price
 */


#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "Colours.h"

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
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
}


// --------------------------------------------- M A I N ---------------------------------------------
void loop(void) 
{
  tft.setCursor(5, 5);
  
  if(digitalRead(upButton) == 0)            // If the up button has been pressed
  {
    tft.println("Up Button Pressed");      
  }
  else if(digitalRead(downButton) == 0)
  {
    tft.println("Down Button Pressed");
  }
  else if(digitalRead(leftButton) == 0)
  {
    tft.println("Left Button Pressed");
  }
  else if(digitalRead(rightButton) == 0)
  {
    tft.println("Right Button Pressed");
  }
  else if(digitalRead(aButton) == 0)
  {
    tft.println("A Button Pressed");
  }
  else if(digitalRead(bButton) == 0)
  {
    tft.println("B Button Pressed");
  }
  else
  {
    tft.println("No Button Pressed");
  }

  delay(500);
  tft.fillScreen(BLACK);                   // Clear the display
}
