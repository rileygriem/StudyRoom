#include <Adafruit_NeoPixel.h>

const uint8_t PROGMEM gamma8[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

#define LED_PIN_LOWER 2      // Define the pin where the data line is connected
#define LED_PIN_UPPER 2
#define NUM_LEDS 120   // Total number of LEDs per line

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN_LOWER, NEO_GRB + NEO_KHZ800);

int whiteLEDPin = 4;
int deskPin = 6;
int matPin = 8;


void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.show();  // Initialize all pixels to 'off'

  pinMode(deskPin, INPUT_PULLUP);
  pinMode(matPin, INPUT_PULLUP);

  pinMode(whiteLEDPin, OUTPUT);
  digitalWrite(whiteLEDPin, LOW);
}

void loop() {
  int matState = digitalRead(matPin);
  int deskState = digitalRead(deskPin);

  // Serial.print("Mat: ");
  // Serial.print(matState);
  // Serial.print(" Desk: ");
  // Serial.println(deskState);

  uint32_t orange = strip.Color(pgm_read_byte(&gamma8[175]), pgm_read_byte(&gamma8[128]), pgm_read_byte(&gamma8[0]));
  uint32_t warmWhite = strip.Color(pgm_read_byte(&gamma8[255]), pgm_read_byte(&gamma8[255]), pgm_read_byte(&gamma8[170]));
  uint32_t off = strip.Color(pgm_read_byte(&gamma8[0]), pgm_read_byte(&gamma8[0]), pgm_read_byte(&gamma8[0]));



  if (matState == LOW) { // IF MEDITATION MAT IS BEING SAT ON
    digitalWrite(whiteLEDPin, LOW);
    strip.fill(orange, 0, 120);
    strip.show();

    Serial.println("Meditation");
    
  } else if (deskState == LOW){ // IF DESK IS LEANED ON
    strip.fill(off, 0, 120);
    strip.show();
    digitalWrite(whiteLEDPin, HIGH);

    Serial.println("Sprint");

  } else { // IF NEITHER ARE BEING PRESSED
    digitalWrite(whiteLEDPin, LOW);
    strip.fill(warmWhite, 0, 120);
    strip.show();

    Serial.println("Reading");

  }


 

}






  // CYCLE TEST

  // strip.fill(orange, 0, 120);
  // strip.show();
  // delay(3000);

  // strip.fill(warmWhite, 0, 120);
  // strip.show();
  // delay(3000);

  // strip.fill(off, 0, 120);
  // strip.show();

  // digitalWrite(whiteLEDPin, HIGH);
  // delay(3000);
  // digitalWrite(whiteLEDPin, LOW);
  // delay(1000);



  


