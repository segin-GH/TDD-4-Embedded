#include "ledDriver.h"

static uint16_t *virtualLed;

/* initialize led driver */
void ledDriverInit(uint16_t *memoryMappedAddr)
{
    virtualLed = memoryMappedAddr;
    *virtualLed = 0;
}

/* clean up led driver after no use */
void ledDriverDestroy(void)
{
    //
}

/* turn on one led */
void ledDriverTurnON(int ledNumber)
{
    *virtualLed |= (1 << (ledNumber -1));
}

/* turn off one led */
void ledDriverTurnOFF(int ledNumber)
{
    *virtualLed = 0;
}