#include <TFT.h>
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen
char sensorPrintout[4];

const int led_pin = 3;

void setup() {
  Serial.begin(115200);

  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, HIGH);
  
  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

 
  String text = "Hallo mein Name ist Ardunote und ich bin ein programmierbares Notizbuch. Falls du mehr ueber mich erfahren moechtest, kannst du dich gerne an meine Entwickler Winnie, Martin, Thomas, Jonathan und an deren Mentoren David U., Dieter und Veronika wenden.";
  String text2 = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16";


  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(255, 150, 25); //b, g, r
  // set the font size
  TFTscreen.setTextSize(1);
  // write the text to the top left corner of the screen
  TFTscreen.text(ZeilenumbruchEinfg(text).c_str(), 0, 0);
  // ste the font size very large for the loop
  TFTscreen.setTextSize(5);

}

void loop() {
  int sw_left = analogRead(A1);
  int sw_right = analogRead(A2);
  if (sw_left > 700) {
    digitalWrite(led_pin, LOW);
  } else if (sw_right > 700) {
    digitalWrite(led_pin, HIGH);
  }
  delay(100);
}
  
String ZeilenumbruchEinfg(String text){
  String text2 = "";

  for (int i = 0; i < text.length()/26 + 1; i++){
    text2.concat(text.substring(26*i, i*26+26) + "\n");
  }
  return text2;
}

