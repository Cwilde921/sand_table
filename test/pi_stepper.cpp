#include <stdio.h>
#include <wiringPi.h>

const int motorPins[] = {1,4,5,6};
const int CCWStep[] = {0x01, 0x02, 0x04, 0x08};
const int  CWStep[] = {0x08, 0x04, 0x02, 0x01};

void moveOnePeriod(int dir, int ms) 
{
    for (int j=0; j<4; j++)
    {
        for (int i=0; i<4; i++)
        {
            if dir == 1)
            {
                digitalWrite(motorPins[i], (CCWStep[j] == (1<<i)) ? HIGH : LOW);
            }
            else
            {
                digitalWrite(motorPins[i], (CWSteps[j] == (1<<i)) ? HIGH : LOW);
            }
            printf("motorPin %d, %d \n",motorPins[i],digitalRead(motorPins[i]));
        }
        printf("Step cycle!\n");
        if(ms<3)    //the delay can not be less than 3ms, otherwise 
        {           //it will exceedspeed limit of the motor
            ms=3;
        }
        delay(ms);
    }
}

void moveSteps(int dir, int ms, int steps)
{
    for (int i=0; i<steps; i++)
    {
        moveOnePeriod(dir, ms);
    }
}

void motorStop() 
{
    for (int i=0; i<4; i++)
    {
        digitalWrite(motorPins[i], LOW);
    }
}

int main(void)
{
    if (wiringPiSetup() == -1)
    {
        printf("wiringPi setup failed");
        return 1;
    }
    for (int i=0; i<4; i++)
    {
        pinMode(motorPins[i], OUTPUT);
    }
    while(1)
    {
        moveSteps(1, 3, 512);
        delay(500);
        moveSteps(0, 3, 512);
        delay(500);
    }
    return 0;
}

