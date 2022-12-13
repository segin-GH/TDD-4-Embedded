#include "ledDriver.h"

static uint16_t *virtualLed;

void ledDriverInit(uint16_t *memoryMappedAddr)
{
    virtualLed = memoryMappedAddr;
    *virtualLed = 0;
}


void ledDriverDestroy(void)
{
    //
}


void ledDriverTurnON(int ledNumber)
{
    *virtualLed = 1;
}