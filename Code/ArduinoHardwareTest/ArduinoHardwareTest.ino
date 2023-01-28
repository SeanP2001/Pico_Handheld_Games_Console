#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3c ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int upButton = 12;
int downButton = 10;
int leftButton = 13;
int rightButton = 11;
int aButton = 17;
int bButton = 16;

int buzzer = 22;

void setup() {

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(aButton, INPUT_PULLUP);
  pinMode(bButton, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  display.clearDisplay();
  display.display();

  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  display.clearDisplay(); 
  noTone(buzzer);
  display.setCursor(0,16);

  if (digitalRead(upButton) == HIGH)
  {
    display.println("Up Button");
    tone(buzzer, 2000);
  }
  else if (digitalRead(downButton) == HIGH)
  {
    display.println("Down Button");
    tone(buzzer, 2000);
  }
  else if (digitalRead(leftButton) == HIGH)
  {
    display.println("Left Button");
    tone(buzzer, 2000);
  }
  else if (digitalRead(rightButton) == HIGH)
  {
    display.println("Right Button");
    tone(buzzer, 2000);
  }
  else if (digitalRead(aButton) == HIGH)
  {
    display.println("A Button");
    tone(buzzer, 2000);
  }
  else if (digitalRead(bButton) == HIGH)
  {
    display.println("B Button");
    tone(buzzer, 2000);
  }
  else
  {
    display.println("No Button");
  }

  display.display();
  delay(1000);

}
