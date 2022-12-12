#include "ledDriver.h"


char* printHello(char *buffer , char *name)
{
    sprintf(buffer,"Hello ");
    sprintf(buffer,name);
    return buffer;
}