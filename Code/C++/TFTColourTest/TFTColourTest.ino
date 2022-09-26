/*
 * Program to cycle through all of the colours in "Colours.h"
 * If the colour of the text does not match what the text says, 
 * change the Hex value for that colour in "Colours.h"
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

// ---------------------------------- O T H E R   V A R I A B L E S ----------------------------------
int colours[15] = {BLACK, WHITE, MAROON, RED, MAGENTA, PURPLE, NAVY, 
                  BLUE, CYAN, TEAL, LIME, GREEN, OLIVE, YELLOW, ORANGE};

// -------------------------------------------- S E T U P --------------------------------------------
void setup() 
{
  Serial.begin(9600);
 
  tft.begin();
  tft.setRotation(2);
  tft.fillScreen(GREY);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
}

// --------------------------------------------- M A I N ---------------------------------------------
void loop(void) 
{  
  for(int i = 0; i < 15; i++)         // Cycle through all of the colours
  {
    tft.setCursor(5, 5);
    
    tft.setTextColor(colours[i]);     // Set the text to the selected colour                    

    switch(i)                         // and print the name of that colour
    {
      case 0:
        tft.println("BLACK");
        break;
      case 1:
        tft.println("WHITE");
        break;
      case 2:
        tft.println("MAROON");
        break;
      case 3:
        tft.println("RED");
        break;
      case 4:
        tft.println("MAGENTA");
        break;
      case 5:
        tft.println("PURPLE");
        break;
      case 6:
        tft.println("NAVY");
        break;
      case 7:
        tft.println("BLUE");
        break;
      case 8:
        tft.println("CYAN");
        break;
      case 9:
        tft.println("TEAL");
        break;
      case 10:
        tft.println("LIME");
        break;
      case 11:
        tft.println("GREEN");
        break;
      case 12:
        tft.println("OLIVE");
        break;
      case 13:
        tft.println("YELLOW");
        break;
      case 14:
        tft.println("ORANGE");
        break;
    }   

    delay(500);
    tft.fillScreen(GREY);              // Clear the display
  } 
}
