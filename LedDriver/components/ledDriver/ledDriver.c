#include "ledDriver.h"

const enum
{
    ALL_LED_ON = ~0,
    ALL_LED_OFF = ~ALL_LED_ON
}led_val;

static uint16_t *virtualLedAddr;
static uint16_t ledImg;

/* initialize led driver */
void ledDriverInit(uint16_t *memoryMappedAddr)
{
    virtualLedAddr = memoryMappedAddr;
    ledImg = ALL_LED_OFF;
    *virtualLedAddr = ledImg;
}

/* clean up led driver after no use */
void ledDriverDestroy(void)
{
    //
}

static uint16_t convertLedNumberTBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

/* turn on one led */
void ledDriverTurnON(int ledNumber)
{
    ledImg |= convertLedNumberTBit(ledNumber);
    *virtualLedAddr = ledImg;
}

/* turn off one led */
void ledDriverTurnOFF(int ledNumber)
{
   ledImg &= ~(convertLedNumberTBit(ledNumber));
    *virtualLedAddr = ledImg; 
}


void ledDriverTurnAllOn()
{
   ledImg = ALL_LED_ON;
    *virtualLedAddr = ledImg; 
}