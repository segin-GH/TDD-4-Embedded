#include "ledDriver.h"

const enum {
    ALL_LED_ON = ~0,
    ALL_LED_OFF = ~ALL_LED_ON
}led_val;

static uint16_t *virtualLedAddr;
static uint16_t ledImg;


/* wrapper function for updating hardware */
void updateHardware()
{
    *virtualLedAddr = ledImg;
}

/* wrapper function for covert led number */
static uint16_t convertLedNumToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

/* initialize led driver */
void ledDriverInit(uint16_t *memoryMappedAddr)
{
    virtualLedAddr = memoryMappedAddr;
    ledImg = ALL_LED_OFF;
    updateHardware();
}

/* clean up led driver after no use */
void ledDriverDestroy(void)
{
    //
}


/* turn on one led */
void ledDriverTurnON(int ledNumber)
{
    if(ledNumber <= 0 || ledNumber > 16)
        return;

    ledImg |= convertLedNumToBit(ledNumber);
    updateHardware();
}

/* turn off one led */
void ledDriverTurnOFF(int ledNumber)
{
    if(ledNumber <= 0 || ledNumber > 16)
        return;

    ledImg &= ~(convertLedNumToBit(ledNumber));
    updateHardware(); 
}

/* turn all led on */
void ledDriverTurnAllOn()
{
    ledImg = ALL_LED_ON;
    updateHardware(); 
}