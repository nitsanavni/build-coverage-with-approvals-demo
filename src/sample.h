#ifndef SAMPLE_H
#define SAMPLE_H

#include "./constants.h"
#include "./globals.h"

extern void theFunctionToTest();

// exposed for testing only
extern void print_privates();
extern void set_internals(int _IstwMin, int _IstwMax, unsigned int _Zustand_0,
                          unsigned int _Zustand_1_);

#endif // SAMPLE_H
