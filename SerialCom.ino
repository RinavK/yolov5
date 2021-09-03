#include<Servo.h>

Servo vmotor; //Vertical Axis Motor
Servo hmotor; //Horizontal Axis Motor

int ledPin = 4;
int data;
int currentX = 90;
int currentY = 90;

void setup() {
  Serial.begin(9600);
  vmotor.attach(7);
  hmotor.attach(6);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  vmotor.write(90);
  hmotor.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    data = Serial.read();
  }
  if(data == '0' && currentY < 180)
  {
    currentY += 5;
    vmotor.write(currentY);
    data = '.';
  }
  else if(data == '1' && currentY > 5)
  {
    currentY -= 5;
    vmotor.write(currentY);
    data = '.';
  }
  else if(data == '2' && currentX < 175)
  {
    currentX += 5;
    hmotor.write(currentX);
    data = '.';
  }
  else if(data == '3' && currentX > 5)
  {
    currentX -= 5;
    hmotor.write(currentX);
    data = '.';
  }
  else if(data == '4')
  {
    vmotor.write(90);
    hmotor.write(90);
    currentX = 90;
    currentY = 90;
    data = '.';
  }
  else if(data == '5')
  {
    vmotor.write(0);
    hmotor.write(0);
    currentX = 0;
    currentY = 0;
    data = '.';
  }
  else if(data == '6')
  {
    vmotor.write(180);
    hmotor.write(180);
    currentX = 180;
    currentY = 180;
    data = '.';
  }
}
