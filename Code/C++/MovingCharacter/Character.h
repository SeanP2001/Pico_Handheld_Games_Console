
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "Colours.h"
extern Adafruit_ILI9341 tft;

class Character{
  private:
    int colour;
    int width;
    int height;
    int xPos;
    int yPos;
    int jumpHeight;
    int moveSpeed;
    
  public:
    Character(int _colour, int _width, int _height, int _xPos, int _yPos, int _jumpHeight, int _moveSpeed);

    void draw();

    void drawBlank();

    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void jump();

    void jumpLeft();

    void jumpRight();
};


#endif // _COLOURS_H_
