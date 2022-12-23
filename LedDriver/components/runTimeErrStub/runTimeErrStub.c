#include "runTimeErrStub.h"

static const char *m_msg = "No Error";
static int m_parameter = -1;
static const char *m_file = 0;
static int m_line = -1;


void runTimeErrStub_reset(void)
{
    m_msg = "No Error";
    m_parameter = -1;
}

const char* runTimeErrStub_getLastError(void)
{
    return m_msg;
}

void runTimeError(const char *msg, int parms, const char *file, int line)
{
    m_msg = msg;
    m_parameter = parms;
    m_file = file;
    m_line = line;
}
int runTimeErrStub_getLastParameter(void)
{
    return m_parameter;
}

