import time
from machine import Pin, I2C, PWM
from ssd1306 import SSD1306_I2C

#-----------------------------------------------------------------
class Button:
    def __init__(self, pinNo):
        self.button = Pin(pinNo, Pin.IN, Pin.PULL_UP)       
        
    def isPressed(self):
        if (self.button.value() == 0):
            return True
        else:
            return False
#-----------------------------------------------------------------
        
upButton = Button(12)
downButton = Button(10)
leftButton = Button(13)
rightButton = Button(11)
aButton = Button(17)
bButton = Button(16)

#-----------------------------------------------------------------

i2c = I2C(1, sda=Pin(26), scl=Pin(27), freq=400000) # get the I2C address

oled = SSD1306_I2C(128, 64, i2c)

#-----------------------------------------------------------------

buzzer = PWM(Pin(22))
buzzer.freq(2000)
buzzer.duty_u16(0)     # turned off to start

#-----------------------------------------------------------------

oled.fill(0)
oled.show()

while(1):
    if (upButton.isPressed()):
        oled.text("Up Button", 0, 0)
        buzzer.duty_u16(1000)            # turn the buzzer on at max volume
    elif (downButton.isPressed()):
        oled.text("Down Button", 0, 0)
        buzzer.duty_u16(1000)            # turn the buzzer on at max volume
    elif (leftButton.isPressed()):
        oled.text("Left Button", 0, 0)
        buzzer.duty_u16(1000)            # turn the buzzer on at max volume
    elif (rightButton.isPressed()):
        oled.text("Right Button", 0, 0)
        buzzer.duty_u16(1000)            # turn the buzzer on at max volume
    elif (aButton.isPressed()):
        oled.text("A Button", 0, 0)
        buzzer.duty_u16(1000)            # turn the buzzer on at max volume
    elif (bButton.isPressed()):
        oled.text("B Button", 0, 0)
        buzzer.duty_u16(1000)            # turn the buzzer on at max volume
    else:
        oled.text("No Button", 0, 0)
        
    oled.show()        
    time.sleep(1)
    buzzer.duty_u16(0)  # turn the buzzer off
    oled.fill(0)        # clear the screen
    oled.show()