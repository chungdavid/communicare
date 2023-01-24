/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

#include <IRremote.h>
#include <LiquidCrystal.h>

// receiving pin for IR remote
const int RECV_PIN = 7;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int setPainScore = 0; // tracks if patient wants to set a pain score
int setHappyScore = 0; // tracks if patient wants to set a happy score

void setup() {
  Serial.begin(9600); // Serial Monitor @ 9600 baud
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); //  Enable the IR reiever

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Pt: John Smith");

}

void loop() {

  if(IrReceiver.decode()){

    switch(IrReceiver.decodedIRData.decodedRawData){
      case 3910598400: //0 No
        Serial.print(millis()/1000);
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("0");
          Serial.println(": Patient reported a pain score of 0");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("0");
          Serial.println(": Patient reported a happiness score of 0");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("No              ");
          Serial.println(": Patient said 'no'");
        }
        break;
      case 4077715200: //1 Yes
        Serial.print(millis()/1000);
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("1");
          Serial.println(": Patient reported a pain score of 1");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("1");
          Serial.println(": Patient reported a happiness score of 1");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Yes             ");
          Serial.println(": Patient said 'yes'");
        }
        break;
      case 3877175040: //2 Bathroom
        Serial.print(millis()/1000);
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("2");
          Serial.println(": Patient reported a pain score of 2");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("2");
          Serial.println(": Patient reported a happiness score of 2");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Bathroom        ");
          Serial.println(": Patient said 'bathroom'");
        }
        break;
      case 2707357440: //3 Hungry
        Serial.print(millis()/1000);
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("3");
          Serial.println(": Patient reported a pain score of 3");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("3");
          Serial.println(": Patient reported a happiness score of 3");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Hungry          ");
          Serial.println(": Patient said 'hungry'");
        }
        break;
      case 4144561920: //4 Thirsty
        Serial.print(millis()/1000);
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("4");
          Serial.println(": Patient reported a pain score of 4");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("4");
          Serial.println(": Patient reported a happiness score of 4");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Thirsty         ");
          Serial.println(": Patient said 'thirsty'");
        }
        break;
      case 3810328320: //5 Reposition
        Serial.print(millis()/1000);
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("5");
          Serial.println(": Patient reported a pain score of 5");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("5");
          Serial.println(": Patient reported a happiness score of 5");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Reposition      ");
          Serial.println(": Patient said 'reposition'");
        }
        break;
      case 2774204160: //6 Call caregiver
        Serial.print(millis()/1000);
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("6");
          Serial.println(": Patient reported a pain score of 6");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("6");
          Serial.println(": Patient reported a happiness score of 6");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Caregiver called");
          Serial.println(": Patient called for caregiver");
        }
        break;
      case 3175284480: //7 Set painscale
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("7");
          Serial.print(millis()/1000);
          Serial.println(": Patient reported a pain score of 7");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("7");
          Serial.print(millis()/1000);
          Serial.println(": Patient reported a happiness score of 7");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Pain score:     ");
          setPainScore=1;
        }
        break;
      case 2907897600: //8 Set happyscale
        if(setPainScore==1){
          lcd.setCursor(13, 1);
          lcd.print("8");
          Serial.print(millis()/1000);
          Serial.println(": Patient reported a pain score of 8");
          setPainScore=0;
        } else if (setHappyScore==1) {
          lcd.setCursor(13, 1);
          lcd.print("8");
          Serial.print(millis()/1000);
          Serial.println(": Patient reported a happiness score of 8");
          setHappyScore=0;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Happy score:    ");
          setHappyScore=1;
        }
        break;
      case 3041591040: //9 Nothing
        if(setPainScore==1){
          Serial.print(millis()/1000);
          lcd.setCursor(13, 1);
          lcd.print("9");
          Serial.println(": Patient reported a pain score of 9");
          setPainScore=0;
        } else if (setHappyScore==1) {
          Serial.print(millis()/1000);
          lcd.setCursor(13, 1);
          lcd.print("9");
          Serial.println(": Patient reported a happiness score of 9");
          setHappyScore=0;
        }
        break;
    }

    IrReceiver.resume(); // Enable receiving of the next value

  }

}
