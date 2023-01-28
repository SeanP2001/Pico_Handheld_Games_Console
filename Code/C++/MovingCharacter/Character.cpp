
#include "Character.h"

Character::Character(int _colour, int _width, int _height, int _xPos, int _yPos, int _jumpHeight, int _jumpDuration)
{
  this->colour = _colour;
  this->width = _width;
  this->height = _height;
  this->xPos = _xPos;
  this->yPos = _yPos;
  this->jumpHeight = _jumpHeight;
  this->jumpDuration = _jumpDuration;

  currentTime = 0;
  jumpStartTime = 0;
  initialHeight = yPos;

  jumping = false;
}

void Character::draw()
{
  tft.fillRect(xPos, yPos, width, height, colour);
}

void Character::drawBlank()
{
  tft.fillRect(xPos, yPos, width, height, BLACK);
}

void Character::moveLeft()
{
  tft.fillRect((xPos + width - 2), yPos, 2, height, BLACK);
  xPos = xPos - 2;
  //draw();
}

void Character::moveRight()
{
  tft.fillRect(xPos, yPos, 2, height, BLACK);
  xPos = xPos + 2;
  //draw();
}

void Character::moveYPos(int dy, enum direction dir)
{
  if(dir == Up)
  {
    tft.fillRect(xPos, (yPos + height - dy), width, dy, BLACK);
    yPos = yPos - dy;
  }
  if(dir == Down)
  {
    tft.fillRect(xPos, yPos, width, dy, BLACK);
    yPos = yPos + dy;
  }
  
}

void Character::jump()
{
  initialHeight = yPos;
  jumpStartTime = millis();

  jumping = true;
}

void Character:: updatePos()
{
    if (jumping)
    {
      timeSinceJump = millis() - jumpStartTime;
      
      if (timeSinceJump <= jumpDuration*0.25)
      {
        if (yPos > ((initialHeight - jumpHeight)*0.6))
        {
          moveYPos(2, Up);
        }     
      }
      else if((timeSinceJump > jumpDuration*0.25) && (timeSinceJump <= jumpDuration*0.5))
      {
        if (yPos > (initialHeight - jumpHeight))
        {
          moveYPos(1, Up);
        }
      }
      else if((timeSinceJump > jumpDuration*0.5) && (timeSinceJump <= jumpDuration*0.75))
      {
        if(yPos < (initialHeight - jumpHeight*0.6))
        {
          moveYPos(1, Down);
        }    
      }
      else if((timeSinceJump > jumpDuration*0.75) && (timeSinceJump <= jumpDuration*1))
      {
        if(yPos < (initialHeight))
        {
          moveYPos(2, Down);
        }    
      }
      else if(yPos < initialHeight)
      {
        moveYPos(1, Down);
      }
      if (yPos == initialHeight)
      {
        jumping = false;
      }    
    }
}
