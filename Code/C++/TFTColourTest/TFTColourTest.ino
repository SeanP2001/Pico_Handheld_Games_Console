/*
 * Program to cycle through all of the colours in "Colours.h"
 * If the colour does not match what the text says, 
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
int colours[16] = {BLACK, WHITE, MAROON, RED, MAGENTA, PURPLE, NAVY, 
                  BLUE, CYAN, TEAL, LIME, GREEN, DARK_GREEN, OLIVE, YELLOW, ORANGE};

String colourNames[16] = {"BLACK", "WHITE", "MAROON", "RED", "MAGENTA", "PURPLE", "NAVY", "BLUE",
                        "CYAN", "TEAL", "LIME", "GREEN", "DARK GREEN", "OLIVE", "YELLOW", "ORANGE"};

// -------------------------------------------- S E T U P --------------------------------------------
void setup() 
{
  Serial.begin(9600);
 
  tft.begin();
  tft.setRotation(2);
  tft.fillScreen(GREY);
  tft.setTextColor(GREY);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
}

// --------------------------------------------- M A I N ---------------------------------------------
void loop(void) 
{  
  for(int i = 0; i < 16; i++)         // Cycle through all of the colours
  {
    tft.fillScreen(colours[i]);       // Fill the screen with the current colour

    tft.setCursor(5, 5);
    tft.println(colourNames[i]);      // Print the name of the current colour 

    delay(1000);
  } 
}
