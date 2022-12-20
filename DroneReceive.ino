//CODE FOR ARDUINO TO INTERPRET
//0000: HOLD POSITION 
//0001: ROTATE RIGHT
//0010: ROTATE LEFT
//0011: MOVE UP
//0100: MOVE DOWN
//0101: MOVE FORWARD
//0110: MOVE BACKWARD
//0111: MOVE RIGHT
//1000: MOVE LEFT

#include "BTLE.h" 
#include "RF24.h"
#include "SPI.h"

//create an RF24 object
RF24 radio(10, 9);  // CE, CSN

#define CHECK 7 
#define UNO 6 
#define DOS 5 
#define TRE 4 

//address through which two modules communicate.
const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for 2 NRF24L01 
int decipher = 0;

void setup()
{
  pinMode(CHECK, OUTPUT);
  pinMode(UNO, OUTPUT);
  pinMode(DOS, OUTPUT);
  pinMode(TRE, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, pipe); //set the address
  radio.startListening(); //Set module as receiver
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[] = {10};
    radio.read(&text, sizeof(text));
    int decipher = text[0] - 48;
    Serial.println(decipher);
    //Following is for debugging, use diff code for drone com
    switch(decipher)
    {
      case 0:
        digitalWrite(CHECK, HIGH);
        Serial.println("Zero");
        break;
      case 1: 
        Serial.println("One");
        break;
      case 2: 
        digitalWrite(UNO, HIGH);
        Serial.println("Two");
        break;
      case 3: 
        digitalWrite(DOS, HIGH);
        Serial.println("Three");
        break;
      case 4: 
        digitalWrite(UNO, HIGH);
        digitalWrite(DOS, HIGH);
        Serial.println("Four");
        break;
      case 5: 
        digitalWrite(TRE, HIGH);
        Serial.println("Five");
        break;
      case 6: 
        digitalWrite(UNO, HIGH);
        digitalWrite(TRE, HIGH);
        Serial.println("Six");
        break;
      case 7: 
        digitalWrite(DOS, HIGH);
        digitalWrite(TRE, HIGH);
        Serial.println("Seven");
        break;
      case 8: 
        digitalWrite(UNO, HIGH);
        digitalWrite(DOS, HIGH);
        digitalWrite(TRE, HIGH);
        Serial.println("Eight");
        break;
    }
    delay(1000);
    digitalWrite(UNO, LOW);
    digitalWrite(DOS, LOW);
    digitalWrite(TRE, LOW);
    digitalWrite(CHECK, LOW);
  }
}
