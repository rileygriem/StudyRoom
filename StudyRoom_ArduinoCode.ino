#include <Adafruit_NeoPixel.h>

#define LED_PIN_LOWER 2      // Define the pin where the data line is connected
#define LED_PIN_UPPER 2
#define NUM_LEDS 120   // Total number of LEDs per line

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS, LED_PIN_LOWER, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS, LED_PIN_UPPER, NEO_GRB + NEO_KHZ800);

int deskPin = 6;
int matPin = 8;

byte arbitraryCodeRead = 97; // for an audio file
byte arbitraryCodeSprint = 98; // might need this one for the other audio file?
byte arbitraryCodeMeditation = 99; // might need this one for the other other audio file?

void setup() {
  Serial.begin(9600);

  strip1.begin();
  strip1.show();  // Initialize all pixels to 'off'

  strip2.begin();
  strip2.show(); 

  pinMode(deskPin, INPUT);
  pinMode(matPin, INPUT);

  Serial.println("Go!");
}

void loop() {
  int matState = digitalRead(matPin);
  int deskState = digitalRead(deskPin);
  Serial.print("Mat: ");
  Serial.print(matState);
  Serial.print(" Desk: ");
  Serial.println(deskState);

  if (digitalRead(matPin) == HIGH) {
    strip1.setPixelColor(255, 165, 0); // ORANGE
    strip2.setPixelColor(255, 165, 0); // ORANGE
    Serial.write(arbitraryCodeMeditation);
    delay(500);
  } else if (digitalRead(deskPin) == HIGH) {
    strip1.setPixelColor(255, 255, 255); // BRIGHT WHITE
    strip2.setPixelColor(255, 255, 255); // BRIGHT WHITE
    Serial.write(arbitraryCodeSprint);
    delay(500);
  } else {
    strip1.setPixelColor(255, 215, 0); // WARM WHITE
    strip2.setPixelColor(255, 215, 0); // WARM WHITE
    Serial.write(arbitraryCodeRead);
    delay(500);
  }
  

}

// void setColor(int red, int green, int blue) {
//   analogWrite(redPin, red);
//   analogWrite(greenPin, green);
//   analogWrite(bluePin, blue);
// }





// BACKWARDS COLORS:
    // setColor(0, 255, 255); // Red
    // setColor(0, 210, 255); // Orange
    // setColor(0, 30, 255); // Yellow
    // setColor(255, 0, 255); // Green
    // setColor(255, 0, 0); // Cyan
    // setColor(255, 255, 0); // Cyan
    // setColor(150, 255, 0); // Purple