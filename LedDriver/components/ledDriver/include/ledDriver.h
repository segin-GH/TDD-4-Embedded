#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdio.h>
#include <string.h>

/* inti led driver */
void ledDriverInit(uint16_t *memoryMappedAddr);
void ledDriverDestroy(void);
void ledDriverTurnON(int ledNumber);

#endif /* LED_DRIVER_H */