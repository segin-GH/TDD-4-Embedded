#include "ledDriver.h"

static uint16_t *virtualLedAddr;
static uint16_t ledImg;

const enum {
    ALL_LED_ON = ~0,
    ALL_LED_OFF = ~ALL_LED_ON
}led_val;

const enum {
    FIRST_LED = 1,
    LAST_LED = 16,
}led_num_def;


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

static bool isLedOutOfBound(int ledNumber)
{
    if((ledNumber < FIRST_LED) || (ledNumber > LAST_LED))
        return true;
    return false;
}

static void setLedImgBit(int ledNumber)
{
    ledImg |= convertLedNumToBit(ledNumber);
}

static void clearLedImgBit(int ledNumber)
{
    ledImg &= ~(convertLedNumToBit(ledNumber));
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
    if(isLedOutOfBound(ledNumber))
        return;

    setLedImgBit(ledNumber);
    updateHardware();
}

/* turn off one led */
void ledDriverTurnOFF(int ledNumber)
{
    if(isLedOutOfBound(ledNumber))
        return;

    clearLedImgBit(ledNumber);
    updateHardware(); 
}

/* turn all led on */
void ledDriverTurnAllOn()
{
    ledImg = ALL_LED_ON;
    updateHardware(); 
}