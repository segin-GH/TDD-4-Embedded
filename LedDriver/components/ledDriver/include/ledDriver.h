#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <runTimeErr.h>

/* inti led driver */
void ledDriverInit(uint16_t *memoryMappedAddr);
void ledDriverDestroy(void);
void ledDriverTurnON(int ledNumber);
void ledDriverTurnOFF(int ledNumber);
void ledDriverTurnAllOn(void);
bool ledDriverIsLedOn(int ledNumber);
bool ledDriverIsLedOff(int ledNumber);
void ledDriverTurnAllOff(void);

#endif /* LED_DRIVER_H */