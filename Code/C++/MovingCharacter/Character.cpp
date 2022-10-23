
#include "Character.h"

Character::Character(int _colour, int _width, int _height, int _xPos, int _yPos, int _jumpHeight, int _moveSpeed)
{
  this->colour = _colour;
  this->width = _width;
  this->height = _height;
  this->xPos = _xPos;
  this->yPos = _yPos;
  this->jumpHeight = _jumpHeight;
  this->moveSpeed = _moveSpeed;
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
  tft.fillRect((xPos + width - 1), yPos, 1, height, BLACK);
  xPos = xPos - 1;
  draw();
  delay(10/moveSpeed);
}

void Character::moveRight()
{
  tft.fillRect(xPos, yPos, 1, height, BLACK);
  xPos = xPos + 1;
  draw();
  delay(10/moveSpeed);
}

void Character::moveUp()
{
  tft.fillRect(xPos, (yPos + height - 1), width, 1, BLACK);
  yPos = yPos - 1;
  draw();
}

void Character::moveDown()
{
  tft.fillRect(xPos, yPos, width, 1, BLACK);
  yPos = yPos + 1;
  draw();
}

void Character::jump()
{
  int groundHeight = yPos;
  while(yPos > (groundHeight - jumpHeight))
  {
    moveUp();
    delay(10/moveSpeed);
  }
  while(yPos < groundHeight)
  {
    moveDown();
    delay(10/moveSpeed);
  }
}

void Character::jumpLeft()
{
  int groundHeight = yPos;
  while(yPos > (groundHeight - jumpHeight))
  {
    moveUp();
    moveLeft();
  }
  while(yPos < groundHeight)
  {
    moveDown();
    moveLeft();
  }
}

void Character::jumpRight()
{
  int groundHeight = yPos;
  while(yPos > (groundHeight - jumpHeight))
  {
    moveUp();
    moveRight();
  }
  while(yPos < groundHeight)
  {
    moveDown();
    moveRight();
  }
}
