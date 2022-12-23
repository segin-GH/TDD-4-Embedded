#ifndef RUN_TIME_ERR_STUB_H
#define RUN_TIME_ERR_STUB_H

#include <stdio.h>


void runTimeErrStub_reset(void);
const char* runTimeErrStub_getLastError(void);
int runTimeErrStub_getLastParameter(void);
void runTimeError(const char *msg, int parms, const char *file, int line);

#define RUNTIME_ERROR(description, parameter)\
            runTimeError(description, parameter, __FILE__, __LINE__);

#endif