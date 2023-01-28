"""
Program to check which button is pressed and display it on the ILI9341 screen.

Author: Sean Price
"""
from ili934xnew import ILI9341, color565
from machine import Pin, SPI
from micropython import const
import os
import glcdfont
import tt14
import tt24
import tt32
import time

# ------------------------------------------- D I S P L A Y   V A R I A B L E S -------------------------------------------
SCR_WIDTH = const(240)          # Swapped W and H to fix display rotation bug
SCR_HEIGHT = const(320)
SCR_ROT = const(2)
CENTER_Y = int(SCR_WIDTH/2)
CENTER_X = int(SCR_HEIGHT/2)

TFT_CLK_PIN = const(6)
TFT_MOSI_PIN = const(7)
TFT_MISO_PIN = const(4)
TFT_CS_PIN = const(13)
TFT_RST_PIN = const(14)
TFT_DC_PIN = const(15)

spi = SPI(
    0,
    baudrate=40000000,
    miso=Pin(TFT_MISO_PIN),
    mosi=Pin(TFT_MOSI_PIN),
    sck=Pin(TFT_CLK_PIN))

display = ILI9341(
    spi,
    cs=Pin(TFT_CS_PIN),
    dc=Pin(TFT_DC_PIN),
    rst=Pin(TFT_RST_PIN),
    w=SCR_WIDTH,
    h=SCR_HEIGHT,
    r=SCR_ROT)

display.set_font(tt24)
display.set_color(color565(255, 255, 0), color565(150, 150, 150))

display.erase()

# ----------------------------------------- B U T T O N   D E C L A R A T I O N S -----------------------------------------
upButton = Pin(17, Pin.IN, Pin.PULL_UP)
downButton = Pin(19, Pin.IN, Pin.PULL_UP)
leftButton = Pin(16, Pin.IN, Pin.PULL_UP)
rightButton = Pin(18, Pin.IN, Pin.PULL_UP)
aButton = Pin(21, Pin.IN, Pin.PULL_UP)
bButton = Pin(20, Pin.IN, Pin.PULL_UP)


# --------------------------------------------------- M A I N   L O O P ---------------------------------------------------
while(1):
    display.erase()
    display.set_pos(0,0)

    if (upButton.value() == 0):
        display.print("Up Button Pressed")
    elif (downButton.value() == 0):
        display.print("Down Button Pressed")
    elif (leftButton.value() == 0):
        display.print("Left Button Pressed")
    elif (rightButton.value() == 0):
        display.print("Right Button Pressed")
    elif (aButton.value() == 0):
        display.print("A Button Pressed")
    elif (bButton.value() == 0):
        display.print("B Button Pressed")
    else:
        display.print("No Button Pressed")
        
    time.sleep(0.5)