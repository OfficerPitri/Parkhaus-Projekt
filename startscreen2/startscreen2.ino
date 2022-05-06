#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3C for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

static const unsigned char PROGMEM startscreen[] ={

  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b01000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b01000000,  0b00000000,  0b00111111,  0b00000011,  0b11000011,  0b11110000,  0b11000011,
  0b00110000,  0b11000011,  0b11000011,  0b00001100,  0b00111111,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b01000000,  0b00000000,  0b00111111,  0b10000111,  0b11100011,  0b11111000,  0b11000111,
  0b00110000,  0b11000111,  0b11100011,  0b00001100,  0b01111111,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b10100000,  0b00000000,  0b00110000,  0b11001110,  0b01110011,  0b00001100,  0b11001110,
  0b00110000,  0b11001110,  0b01110011,  0b00001100,  0b11100000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b10100000,  0b00000000,  0b00110000,  0b11001100,  0b00110011,  0b00001100,  0b11011100,
  0b00110000,  0b11001100,  0b00110011,  0b00001100,  0b11100000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b10100000,  0b00000000,  0b00111111,  0b10001111,  0b11110011,  0b11111000,  0b11111000,
  0b00111111,  0b11001111,  0b11110011,  0b00001100,  0b01111100,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b10100000,  0b00000000,  0b00111111,  0b00001111,  0b11110011,  0b11110000,  0b11111000,
  0b00111111,  0b11001111,  0b11110011,  0b00001100,  0b00111110,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b10100000,  0b00000000,  0b00110000,  0b00001100,  0b00110011,  0b01110000,  0b11011100,
  0b00110000,  0b11001100,  0b00110011,  0b00001100,  0b00000111,  0b00000000,  0b00000000,  0b00000000,
  0b00000001,  0b00010000,  0b00000000,  0b00110000,  0b00001100,  0b00110011,  0b00111000,  0b11001110,
  0b00110000,  0b11001100,  0b00110011,  0b10011100,  0b00000111,  0b00000000,  0b00000000,  0b00000000,
  0b00000001,  0b11110000,  0b00000000,  0b00110000,  0b00001100,  0b00110011,  0b00011100,  0b11000111,
  0b00110000,  0b11001100,  0b00110001,  0b11111000,  0b11111110,  0b00000000,  0b00000000,  0b00000000,
  0b00000001,  0b00010000,  0b00000000,  0b00110000,  0b00001100,  0b00110011,  0b00001100,  0b11000011,
  0b00110000,  0b11001100,  0b00110000,  0b11110000,  0b11111100,  0b00000000,  0b00000000,  0b00000000,
  0b00000010,  0b00001000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000010,  0b00001000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000100,  0b00000100,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000100,  0b11100100,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00001111,  0b11111111,  0b11111111,  0b10000000,
  0b00000101,  0b00010100,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00010000,  0b00000000,  0b00000000,  0b10000000,
  0b00001001,  0b00010010,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00000000,
  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00100000,  0b00000000,  0b00000000,  0b10000000,
  0b00001001,  0b00010010,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00011111,  0b11111111,
  0b11100000,  0b00000000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00000000,  0b10000000,
  0b00001000,  0b11100010,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00100000,  0b00000000,
  0b00100000,  0b00000000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00000000,  0b10000000,
  0b00001000,  0b00000010,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00100000,  0b00000000,
  0b00100000,  0b00000000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00000000,  0b10000000,
  0b00001000,  0b00000010,  0b00000000,  0b00000000,  0b00000000,  0b00000000,  0b00100000,  0b00000000,
  0b00100000,  0b00000000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00000000,  0b10000000,
  0b00001000,  0b00000010,  0b00000000,  0b00000000,  0b00000000,  0b00111111,  0b11110000,  0b00000000,
  0b00100000,  0b00000000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00011111,  0b11111111,
  0b00001000,  0b00000010,  0b00000000,  0b00000000,  0b00000000,  0b00100000,  0b00010000,  0b00000000,
  0b00100000,  0b00000000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00010000,  0b00000001,
  0b00001000,  0b00011111,  0b11111111,  0b11000000,  0b11111111,  0b11100000,  0b00010000,  0b00000111,
  0b11111111,  0b10000000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00010000,  0b00000001,
  0b00001000,  0b00111111,  0b11111111,  0b11100001,  0b00000000,  0b00100000,  0b00010000,  0b00000100,
  0b00000000,  0b01100000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00010000,  0b00000001,
  0b00001000,  0b00110000,  0b00000000,  0b01100001,  0b00000000,  0b00100000,  0b00111111,  0b11111110,
  0b00000000,  0b00010000,  0b00000000,  0b00000000,  0b01000000,  0b00000000,  0b00010000,  0b00000001,
  0b00001000,  0b00110000,  0b00000000,  0b01111111,  0b11110000,  0b00100000,  0b01111111,  0b11111111,
  0b00000000,  0b00001000,  0b00000000,  0b00001111,  0b11111111,  0b11110000,  0b00010000,  0b00000001,
  0b00001000,  0b00110000,  0b00000000,  0b01100000,  0b00010000,  0b00100000,  0b01110000,  0b00000111,
  0b00111111,  0b00000100,  0b00000000,  0b00001111,  0b11111111,  0b11110000,  0b00010000,  0b00000001,
  0b00010110,  0b00110000,  0b00000000,  0b01100000,  0b00010000,  0b00100000,  0b01110000,  0b00000111,
  0b00111111,  0b10000100,  0b00000000,  0b00001100,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00010001,  0b11110000,  0b00000000,  0b01100000,  0b00111111,  0b11111000,  0b01110000,  0b00000111,
  0b00110000,  0b11000010,  0b00000000,  0b00001100,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00010000,  0b00110000,  0b00000000,  0b01100000,  0b01111111,  0b11111100,  0b01110000,  0b00000111,
  0b00110000,  0b11000010,  0b00000000,  0b00001100,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00101100,  0b00110000,  0b00000000,  0b01100000,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00111111,  0b10000010,  0b00000000,  0b00001100,  0b00000000,  0b00111111,  0b11110000,  0b00000001,
  0b00100011,  0b11110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00111111,  0b00000010,  0b00000000,  0b00001100,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00110000,  0b00000010,  0b00000000,  0b00001100,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00110000,  0b00000011,  0b11111111,  0b11111100,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00110000,  0b00000011,  0b00010001,  0b00011110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00110000,  0b00000010,  0b10101010,  0b10101110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b00000010,  0b01000100,  0b01001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b00000111,  0b11111111,  0b11111110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b00001000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b00010000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b00010000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b00100000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b00100000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01011100,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b01000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000011,  0b11110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b10000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000000,  0b10000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000001,  0b00000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000010,  0b00000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00000100,  0b00000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00001000,  0b00000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00001000,  0b00000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00010000,  0b00000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b00100000,  0b00000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b01000000,  0b00000000,  0b00000000,  0b00001110,  0b00000000,  0b00110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b01000000,  0b00000000,  0b00000000,  0b00001111,  0b11111111,  0b11110000,  0b00010000,  0b00000001,
  0b01000000,  0b00110000,  0b00000000,  0b01100001,  0b10000000,  0b00000110,  0b01110000,  0b00000111,
  0b10000000,  0b00000000,  0b00000000,  0b00001111,  0b11111111,  0b11111111,  0b11111111,  0b11111111,
  };

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();


  display.drawBitmap(0,0,startscreen, 128, 64, 1);
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}