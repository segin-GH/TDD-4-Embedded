#include <stdio.h>
#include <unity.h>
#include <unity_fixture.h>
#include "ledDriver.h"

char buffer[10];
char recivedBuffer[10];

void app_main(void)
{
   printf("name is running in test %s\n", printHello(buffer, "segin"));
}
