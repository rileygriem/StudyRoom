import processing.sound.*;
import processing.serial.*;

Serial port;    // Create an object from Serial class
String inString;
String inStringPrev = "Reading";

SoundFile soundfileReading;
SoundFile soundfileSprint;
SoundFile soundfileMeditation;

void setup() {
  size(640, 360);
  background(0);

  port = new Serial(this, "/dev/cu.usbmodem142401", 9600);
  port.bufferUntil('\n');

  // Load the soundfiles
  soundfileReading = new SoundFile(this, "Reading2.mp3");
  soundfileSprint = new SoundFile(this, "Sprint2.mp3");
  soundfileMeditation = new SoundFile(this, "Meditation2.mp3");

  // Play default reading music in a loop
  soundfileReading.loop();
}

void draw() {
  // Check if inString has changed
  if (!inString.equals(inStringPrev)) {
    if (inString.equals("Meditation")) {
      soundfileReading.stop();
      soundfileSprint.stop();
      soundfileMeditation.loop();
    } else if (inString.equals("Sprint")) {
      soundfileReading.stop();
      soundfileMeditation.stop();
      soundfileSprint.loop();
    } else {
      soundfileMeditation.stop();
      soundfileSprint.stop();
      soundfileReading.loop();
    }

    // Update inStringPrev after handling the change
    inStringPrev = inString;
  }
}

void serialEvent(Serial p) {
  inString = p.readString().trim(); // Remove leading/trailing whitespaces
}
