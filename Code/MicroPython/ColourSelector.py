"""
Program to adjust the RGB values of the background and preview how the colour appears on your display

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
import framebuf

import Colours

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
BUFFER_WIDTH = const(280)                # Created a slightly smaller buffer to prevent running out of memory
BUFFER_HEIGHT = const(210)
BUFFER_X_OFFSET = const(20)
BUFFER_Y_OFFSET = const(15)

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

colourVals = [0,0,0]
selectedVal = 0
 
# --------------------------------------------------- M A I N   L O O P ---------------------------------------------------
while(1):
        
    fbuf.fill(color565(colourVals[0], colourVals[1], colourVals[2]))  # Fill the screen with the colour indicated by the colour values

    if (upButton.value() == 0):                                       # Pressing the up button increases the colour value currently selected 
        colourVals[selectedVal] = colourVals[selectedVal] + 5
        if colourVals[selectedVal] > 255:
            colourVals[selectedVal] = 255
        time.sleep(0.1)
    if (downButton.value() == 0):                                     # Pressing the down button decreases the colour value currently selected 
        colourVals[selectedVal] = colourVals[selectedVal] - 5
        if colourVals[selectedVal] < 0:
            colourVals[selectedVal] = 0
        time.sleep(0.1)
    
    if (rightButton.value() == 0) and (selectedVal < 2):              # Pressing the right button selects the value to the right
        selectedVal = selectedVal + 1
        time.sleep(1)
    if (leftButton.value() == 0) and (selectedVal > 0):               # Pressing the left button selects the value to the left
        selectedVal = selectedVal - 1
        time.sleep(1)
        
    fbuf.text(str(colourVals[0]) + "  " + str(colourVals[1]) + "  " + str(colourVals[2]), 5, 5, Colours.GREY) # Print the colour values
    
    renderBuffer()                                                    # display the contents of the buffer on the LCD
            

