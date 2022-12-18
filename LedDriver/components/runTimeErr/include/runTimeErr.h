#ifndef RUN_TIME_ERR_H
#define RUN_TIME_ERR_H

#include <stdio.h>

void runTimeErr(const char *msg, int parms, const char *file, int line);

#define RUNTIME_ERROR(description, parameter)\
    runTimeErr(description, parameter, __FILE__, __LINE__)

#endif