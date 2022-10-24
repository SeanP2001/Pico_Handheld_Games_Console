
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
    int jumpHeight;
    int jumpDuration;     // in ms
    //int moveSpeed;
    int currentTime;
    int jumpStartTime;
    int timeSinceJump;
    int initialHeight;   

    enum direction {Up, Down, Left, Right};
    
  public:
    int xPos;
    int yPos;

    bool jumping;
  
    Character(int _colour, int _width, int _height, int _xPos, int _yPos, int _jumpHeight, int _jumpDuration);

    void draw();

    void drawBlank();

    void moveLeft();

    void moveRight();

    void moveYPos(int dy, enum direction dir);

    void jump();

    void updatePos();
};


#endif // _COLOURS_H_
