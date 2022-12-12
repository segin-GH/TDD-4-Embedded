#include <stdio.h>
#include "ledDriver.h"

char buffer[10];
char recivedBuffer[10];

void app_main(void)
{
   printf("name is %s\n", printHello(buffer, "segin"));
}
