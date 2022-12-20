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

// Chip Communication Variables 
RF24 radio(10,9); // SPI pins + Pin 9 and 10 on the NANO
const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for 2 NRF24L01 

// Processing Variables 
char val; // Data received from the serial port

void setup() {
  // Chip Com Setupd
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
  radio.stopListening();

  // Processing Setup 
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  // Receiving Information from Processing
  if (Serial.available()) 
  { // If data is available to read,
    val = Serial.read(); // read it and store it in val
  }

  //Sending Information to other Arduino
  char text[] = {""};
  for(int i = 0; i < 9; i++)
  {
    text[0] = i + '0'; 
    Serial.println(text[0]);
    radio.write(&text, sizeof(text)); // Send value through NRF24L01
    delay(1000);
  }
}


