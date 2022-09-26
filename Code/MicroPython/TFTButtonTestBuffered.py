"""
Program to check which button is pressed and display it on the ILI9341 screen.

Author: Sean Price

I have added a framebuffer to prevent the screen flickering whenever it refreshes.

Issue 1 - Too much memory taken up by the frame buffer:
Potential Slutions:
    - Make the frame buffer dimensions smaller (as memory fills up the screen will need to be smaller)
    - Reduce the colour to 8-bit (preferred solution but not supported by framebuf)
    - Remove the frame buffer (will cause the screen to flicker and lag)
    
Issue 2 - Frame buffer text is too small and can't be resized (not supported by framebuf)
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
import framebuf

# ------------------------------------------- D I S P L A Y   V A R I A B L E S -------------------------------------------
SCR_WIDTH = const(240)              # Swapped W and H to fix display rotation bug
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

display.erase()

# -------------------------------------------- B U F F E R   V A R I A B L E S --------------------------------------------
BUFFER_WIDTH = const(300)                # Created a slightly smaller buffer to prevent running out of memory
BUFFER_HEIGHT = const(225)
BUFFER_X_OFFSET = const(10)
BUFFER_Y_OFFSET = const(7)

buffer = bytearray(BUFFER_WIDTH * BUFFER_HEIGHT * 2)
fbuf = framebuf.FrameBuffer(buffer, BUFFER_WIDTH, BUFFER_HEIGHT, framebuf.RGB565)

def renderBuffer():                      # Writes the contents of the buffer to the display
    display._writeblock(BUFFER_X_OFFSET, BUFFER_Y_OFFSET,
                        BUFFER_X_OFFSET+BUFFER_WIDTH-1, BUFFER_Y_OFFSET+BUFFER_HEIGHT-1, fbuf)

# ----------------------------------------- B U T T O N   D E C L A R A T I O N S -----------------------------------------
upButton = Pin(17, Pin.IN, Pin.PULL_UP)
downButton = Pin(19, Pin.IN, Pin.PULL_UP)
leftButton = Pin(16, Pin.IN, Pin.PULL_UP)
rightButton = Pin(18, Pin.IN, Pin.PULL_UP)
aButton = Pin(21, Pin.IN, Pin.PULL_UP)
bButton = Pin(20, Pin.IN, Pin.PULL_UP)


# --------------------------------------------------- M A I N   L O O P ---------------------------------------------------
while(1):
    fbuf.fill(color565(150, 150, 150))

    if (upButton.value() == 0):
        fbuf.text("Up Button Pressed", 5, 5, color565(0, 255, 255))
    elif (downButton.value() == 0):
        fbuf.text("Down Button Pressed", 5, 5, color565(0, 255, 255))
    elif (leftButton.value() == 0):
        fbuf.text("Left Button Pressed", 5, 5, color565(0, 255, 255))
    elif (rightButton.value() == 0):
        fbuf.text("Right Button Pressed", 5, 5, color565(0, 255, 255))
    elif (aButton.value() == 0):
        fbuf.text("A Button Pressed", 5, 5, color565(0, 255, 255))
    elif (bButton.value() == 0):
        fbuf.text("B Button Pressed", 5, 5, color565(0, 255, 255))
    else:
        fbuf.text("No Button Pressed", 5, 5, color565(0, 255, 255))


    renderBuffer()              

