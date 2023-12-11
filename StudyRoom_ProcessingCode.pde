import processing.serial.*;
import ddf.minim.*;
 
Serial myPort;
Minim minim;
AudioPlayer playerRead;
AudioPlayer playerSprint;
AudioPlayer playerMeditation;
byte arbitraryCodeRead = 97;
byte arbitraryCodeSprint = 98;
byte arbitraryCodeMeditation = 99;
 
void setup()
{
  // In the next line, you'll need to change this based on your USB port name CHANGED BUT MIGHT NEED TO BE CHANGED AGAIN
  myPort = new Serial(this, "/dev/tty.usbmodem143301", 9600);
  minim = new Minim(this);
 
  // Put in the name of your sound file below, and make sure it is in the same directory
  playerRead = minim.loadFile("soundfile.mp3");
  playerSprint = minim.loadFile("soundfile.mp3");
  playerMeditation = minim.loadFile("soundfile.mp3");
}
 
void draw() {
  while (myPort.available() > 0) {
    int inByte = myPort.read();
    if (inByte == arbitraryCodeRead) {
      playerRead.rewind();
      playerRead.play();
    } else if (inByte == arbitraryCodeSprint) {
      playerSprint.rewind();
      playerSprint.play();
    } else if (inByte == arbitraryCodeMeditation) {
      playerMeditation.rewind();
      playerMeditation.play();
    }
  }
}
