#include "states.h"


namespace BALLRAISE{

// declares pin 9 and 10 as the variables piston left and right
const byte pistonLeft = 9;
const byte pistonRight = 10;

void setup() {
//declares the two variables as outputs
  pinMode(pistonLeft, OUTPUT);
  pinMode(pistonRight, OUTPUT);

}

void loop() {
}
//turns the left wall piston on and off to raise and lower and the does it for the right too

void events:: demo()
  {
  for(int x=0; x<=6; x++)
  {
   events::liftLeftWall();
   delay(1700);
   events:lowerLeftWall();
   delay(1700);
   events::liftRightWall();
   delay(1700);
   events::lowerRightWall();
   delay(1700);   
   }
  }
void events:: leftWall() // only lifts and lowers the left side 
{
  events::liftLeftWall();
  delay(1700);
  events::lowerLeftWall();
  delay(1700);
} 

void events:: rightWall() // only lifts and lowers right side 
{
  events::liftRightWall();
  delay(1700);
  events::lowerRightWall();
  delay(1700);
} 
  
void events::liftLeftWall() // just lifts the left side 
{
  digitalWrite(pistonLeft, HIGH);
}


void events::lowerLeftWall()  // lower only the left wall
 {
   digitalWrite(pistonLeft, LOW);
 } 
   
void events::liftRightWall() // just lifts the right wall
{  
  digitalWrite(pistonRight, HIGH);
} 

void events::lowerRightWall() // just lowers the right 
{
  digitalWrite(pistonRight, LOW);
}  
  
  
  



}