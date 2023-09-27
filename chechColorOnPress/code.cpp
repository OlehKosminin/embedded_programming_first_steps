#include <Adafruit_NeoPixel.h>

#define PIN 7
#define BUTTON_PIN 4 // кнопка
#define NUM_LEDS 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int currentLED = 0;
int clickCounter = 0;
uint32_t currentColor =  strip.Color(255, 0, 0); 
int buttonState = HIGH; 

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.clear();
  strip.show();
  
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
}

void setColor(int count)
{
  const int RED   = 0;
  const int GREEN = 1;
  const int BLUE  = 2;
  
  switch(count)
  {
    case RED:
      currentColor = strip.Color(255, 0, 0);
      break;
    case GREEN:
      currentColor = strip.Color(0, 255, 0);
      break;
    case BLUE:
      currentColor = strip.Color(0, 0, 255);
      break;
    default:
      currentColor = strip.Color(255, 0, 0);
      break;
  }
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);


  if (buttonState == HIGH) {
    if (clickCounter < 2)
      clickCounter++;
    else
      clickCounter = 0;
    
    setColor(clickCounter);
    

   delay(100);
  }

  strip.setPixelColor(currentLED, 0);
  strip.show();

  currentLED = (currentLED + 1) % NUM_LEDS;

  strip.setPixelColor(currentLED, currentColor);
  strip.show();

  delay(800);
}
