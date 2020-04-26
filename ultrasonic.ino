#include <NewPing.h>
const int lefttrigPin = A4;
const int leftechoPin = A5;

const int fronttrigPin = A2;
const int frontechoPin = A3;

const int righttrigPin = A0;
const int rightechoPin = A1;

float oldLeftSensor, oldFrontSensor, leftSensor, frontSensor, lSensor, fSensor, oldRightSensor, rightSensor, rSensor;

const int lmf = 6;
const int lmb = 11;
const int rmf = 10;
const int rmb = 9;

int d = 7;
NewPing sonarLeft(A4, A5, 50);
NewPing sonarFront(A2, A3, 200);
NewPing sonarRight(A0 , A1 , 100);
void setup()
{
  pinMode(lefttrigPin, OUTPUT);
  pinMode(leftechoPin, INPUT);
  pinMode(righttrigPin, OUTPUT);
  pinMode(rightechoPin, INPUT);
  pinMode(fronttrigPin, OUTPUT);
  pinMode(frontechoPin, INPUT);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  Serial.begin(9600);
}
void ReadSensors()
{
  lSensor = sonarLeft.ping_cm();
  fSensor = sonarFront.ping_cm();
  rSensor = sonarRight.ping_cm();

  leftSensor = (lSensor + oldLeftSensor) / 2;
  rightSensor = (rSensor + oldRightSensor) / 2;
  frontSensor = (fSensor + oldFrontSensor) / 2;

  oldLeftSensor = leftSensor;
  oldRightSensor = rightSensor;
  oldFrontSensor = frontSensor;
}
void loop()
{
    digitalWrite(lefttrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(lefttrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(lefttrigPin, LOW);
    leftduration = pulseIn(leftechoPin, HIGH);
    lSensor = leftduration * 0.034 / 2;
  
  
    digitalWrite(fronttrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(fronttrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(fronttrigPin, LOW);
    frontduration = pulseIn(frontechoPin, HIGH);
    fSensor = frontduration * 0.034 / 2;

  ReadSensors();
  Serial.print("left distance : ");
  Serial.println(lSensor);

  Serial.print("right distance : ");
  Serial.println(rSensor);

  Serial.print("front distance : ");
  Serial.println(fSensor);

  if (rSensor > 30) // right
  { Serial.println("------------------------------------------right---------------------------------------------");

    analogWrite(rmf, 80);
    analogWrite(rmb, 0);
    analogWrite(lmf, 80);
    analogWrite(lmb, 0);
    delay(30);
    analogWrite(rmf, 0);
    analogWrite(rmb, 80);
    analogWrite(lmf, 80);
    analogWrite(lmb, 0);
    delay(310);
    analogWrite(rmf, 80);
    analogWrite(rmb, 0);
    analogWrite(lmf, 80);
    analogWrite(lmb, 0);
    delay(450);
  }
  else if (((lSensor) < 15) && ((rSensor) < 15))
  {
    if ((lSensor) == (d - 3))
    {

      analogWrite(rmf, 40);
      analogWrite(rmb, 0);
      analogWrite(lmf, 80);
      analogWrite(lmb, 0);
    }
    else if ((lSensor) == (d + 3))
    {

      analogWrite(rmf, 80);
      analogWrite(rmb, 0);
      analogWrite(lmf, 40);
      analogWrite(lmb, 0);
    }
    else if ((lSensor) == (d - 2))
    {
      analogWrite(rmf, 0);
      analogWrite(rmb, 0);
      analogWrite(lmf, 0);
      analogWrite(lmb, 0);
      delay(15);

      analogWrite(rmf, 50);
      analogWrite(rmb, 0);
      analogWrite(lmf, 80);
      analogWrite(lmb, 0);
    }
    else if ((lSensor) == (d - 1))
    {
      analogWrite(rmf, 0);
      analogWrite(rmb, 0);
      analogWrite(lmf, 0);
      analogWrite(lmb, 0);
      delay(15);
      
      analogWrite(rmf, 70);
      analogWrite(rmb, 0);
      analogWrite(lmf, 80);
      analogWrite(lmb, 0);
    }
    else if ((lSensor) == (d + 1))
    { 
      analogWrite(rmf, 0);
      analogWrite(rmb, 0);
      analogWrite(lmf, 0);
      analogWrite(lmb, 0);
      delay(15);
      
      analogWrite(rmf, 80);
      analogWrite(rmb, 0);
      analogWrite(lmf, 70);
      analogWrite(lmb, 0);
    }
    else if ((lSensor) == (d + 2))
    { 
      analogWrite(rmf, 0);
      analogWrite(rmb, 0);
      analogWrite(lmf, 0);
      analogWrite(lmb, 0);
      delay(15);
      
      analogWrite(rmf, 80);
      analogWrite(rmb, 0);
      analogWrite(lmf, 50);
      analogWrite(lmb, 0);
    }
    else if ((lSensor) == d)
    {
      analogWrite(rmf, 80);
      analogWrite(rmb, 0);
      analogWrite(lmf, 80);
      analogWrite(lmb, 0);
    }
  }
}
  else if (lSensor > 20) // left turn
  {Serial.println("-----------------------------left-----------------------------");
    analogWrite(rmf, 80);
    analogWrite(rmb, 0);
    analogWrite(lmf, 80);
    analogWrite(lmb, 0);
    delay(200);
    analogWrite(rmf, 80);
    analogWrite(rmb, 0);
    analogWrite(lmf, 0);
    analogWrite(lmb, 80);
    delay(400);
    analogWrite(rmf, 80);
    analogWrite(rmb, 0);
    analogWrite(lmf, 80);
    analogWrite(lmb, 0);
    delay(200);
  }
  else if ((lSensor < 10) && (fSensor < 10) && (rSensor < 10)) // U turn
  {Serial.println("---------------------------------------u turn------------------------------------");
    analogWrite(rmf, 0);
    analogWrite(rmb, 80);
    analogWrite(lmf, 80);
    analogWrite(lmb, 0);
    delay(850);

  }









































//  if ((fSensor) > 10)
//  {
//    if ((lSensor) == (d - 3))
//    {
//
//      analogWrite(rmf, 40);
//      analogWrite(rmb, 0);
//      analogWrite(lmf, 80);
//      analogWrite(lmb, 0);
//    }
//    else if ((lSensor) == (d + 3))
//    {
//
//      analogWrite(rmf, 80);
//      analogWrite(rmb, 0);
//      analogWrite(lmf, 40);
//      analogWrite(lmb, 0);
//    }
//    else if ((lSensor) == (d - 2))
//    {
//
//      analogWrite(rmf, 55);
//      analogWrite(rmb, 0);
//      analogWrite(lmf, 80);
//      analogWrite(lmb, 0);
//    }
//    else if ((lSensor) == (d - 1))
//    {
//
//      analogWrite(rmf, 70);
//      analogWrite(rmb, 0);
//      analogWrite(lmf, 80);
//      analogWrite(lmb, 0);
//    }
//    else if ((lSensor) == (d + 1))
//    {
//      analogWrite(rmf, 80);
//      analogWrite(rmb, 0);
//      analogWrite(lmf, 70);
//      analogWrite(lmb, 0);
//    }
//    else if ((lSensor) == (d + 2))
//    {
//      analogWrite(rmf, 80);
//      analogWrite(rmb, 0);
//      analogWrite(lmf, 55);
//      analogWrite(lmb, 0);
//    }
//    else if ((lSensor) == d)
//    {
//      analogWrite(rmf, 80);
//      analogWrite(rmb, 0);
//      analogWrite(lmf, 80);
//      analogWrite(lmb, 0);
//    }
//  }
//}
//  if ((fSensor) == 10 || (fSensor) == 9 )
//  {
//    analogWrite(rmf, 0);
//    analogWrite(rmb, 0);
//    analogWrite(lmf, 0);
//    analogWrite(lmb, 0);
//    delay(200);
//    analogWrite(rmf, 0);
//    analogWrite(rmb, 60);
//    analogWrite(lmf, 60);
//    analogWrite(lmb, 0);
//    delay(470);
//
//  }
//}
