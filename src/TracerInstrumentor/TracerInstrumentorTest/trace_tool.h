#ifndef TRACE_TOOL_H
#define TRACE_TOOL_H

#include <stdbool.h>

void TARGET_PATH_SET(int pathCount);

void SESSION_START(const char *SIID);

void SWITCH_SI(const char *SIID);

void SESSION_END(int successful);

void TARGET_PATH_SET(int pathCount);

int PATH_GET();

void PATH_INC(int expectedCount);

void PATH_DEC(int expectedCount);

void TRACE_FUNCTION_START(int numFuncs);

void TRACE_FUNCTION_END();

int TRACE_START();

int TRACE_END(int index);

#endif
