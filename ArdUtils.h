//
// Created by robin on 1/8/16.
//

/*
#define ARD_UTILS_DELAYMS
#define ARD_UTILS_UTF8
*/

#ifndef ARDUTILS_ARDUTILS_H
#define ARDUTILS_ARDUTILS_H

#include "Arduino.h"

class ArdUtils
{
public:
#ifdef ARD_UTILS_DELAYMS
    static void delayMs(unsigned ms);
#endif
#ifdef ARD_UTILS_UTF8
    static void utf8ToAscii(char* s);
#endif

private:
#ifdef ARD_UTILS_UTF8
    static byte _utf8ToAscii(byte ascii, byte& c1);
#endif
};

#include "ArdUtils.cpp"
#endif //ARDUTILS_ARDUTILS_H
