#include <Shifter.h>

#define SER_Pin 4 //SER_IN
#define RCLK_Pin 3 //L_CLOCK
#define SRCLK_Pin 2 //CLOCK

#define NUM_REGISTERS 2 //how many registers are in the chain


//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 

//To turn on a LED, set output HIGH for the grid location
// column and row numbers start at 1

//Example
/*
  X = OFF
  O = ON
  
  X 0 
  X X
  X X
  
row 0 on
column 1 on

*/

void setShifterPinsForLed(int ledRow, int ledCol)
{
    //pins 0-7 are rows   
    //pins 8-15 are columns    
    int ledColPin = ledCol + 8;
    shifter.setPin(ledRow,HIGH);
    shifter.setPin(ledColPin,HIGH);    
}


void setup()
{
  // This code will only run once, after each powerup or reset of the board
}

void loop()
{
  //loop columns
  for(int colNum = 0; colNum < 2; colNum++)
  {
     //loop rows
     for(int rowNum = 0; rowNum < 3; rowNum++)
     {
        shifter.clear();
        setShifterPinsForLed(rowNum,colNum);
        shifter.write();
        delay(500);
     }
  }
  
  
  
  
  
}
