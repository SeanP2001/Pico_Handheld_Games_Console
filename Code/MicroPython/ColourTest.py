"""
Program to cycle through all of the colours in "Colours.py"
If the colour does not match what the text says, 
change the Hex value for that colour in "Colours.py"

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

# ----------------------------------------------- C O L O U R   A R R A Y S -----------------------------------------------

colours = [Colours.BLACK, Colours.WHITE, Colours.MAROON, Colours.RED, Colours.MAGENTA,
            Colours.PURPLE, Colours.NAVY, Colours.BLUE, Colours.CYAN, Colours.TEAL,
            Colours.LIME, Colours.GREEN, Colours.DARK_GREEN, Colours.OLIVE, Colours.YELLOW, Colours.ORANGE]

colourNames = ["BLACK", "WHITE", "MAROON", "RED", "MAGENTA", "PURPLE", "NAVY", "BLUE",
               "CYAN", "TEAL", "LIME", "GREEN", "DARK GREEN", "OLIVE", "YELLOW", "ORANGE"]
 
# --------------------------------------------------- M A I N   L O O P ---------------------------------------------------
while(1):
    i = 0
    for colour in colours:   
        fbuf.fill(colour)
        fbuf.text(colourNames[i], 5, 5, Colours.GREY)
        renderBuffer()
        time.sleep(8)
        i = i + 1

