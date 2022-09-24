/*
Title:      Program to display POT values on PUTTY screen
Author:     Dave Ross, Student ID, MCO455 Section __
Date:       Today's date
Description:    This program  will display both SHORT and FLOAT values from
                the GROVE POT on the PUTTY screen.
*/
#include "mbed.h"
// Function Prototypes
void clear(void)                       // clears the PC screen
void position(int x, int y)            // positions screen cursor at (x,y)

// Hardware pin Assignments
AnalogIn input(A1);                     // POT connected to pin A1 on header

int main() 
{
    unsigned short value1;
    float value2;
    clear();                            // clear the screen
    position(11,32);                    // position title 
    printf("Short\tFloat");
    for(;;)
    {
        value1=input.read_u16();        // get SHORT value for POT input
        value2=input.read();            // get FLOAT value for POT input
        position(12,31);                // ouput both values on screen
        printf("%6d\t%1.4f",value1,value2*100);
        wait(0.5);
    }
}
void clear(void);
{
       printf("\e[2J");                 // \e[2J clears the screen
       fflush(stdout);
}
void position(int x, int y);
{
      printf("\e[%d;%dH",x,y);          // position cursor at (x,y)
      fflush(stdout);
}