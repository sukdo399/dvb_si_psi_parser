/*
 *Original Author:	shko
 */

#ifndef UTILS_H
#define UTILS_H

#include <common.h>

#define MASK_1BIT       0x01
#define MASK_2BITS      0x03
#define MASK_3BITS      0x07
#define MASK_4BITS      0x0F
#define MASK_4BITS_UP      0xF0
#define MASK_5BITS      0x1F
#define MASK_6BITS      0x3F
#define MASK_7BITS      0x7F
#define MASK_8BITS      0xFF
#define MASK_9BITS      0x01FF
#define MASK_10BITS     0x03FF
#define MASK_12BITS     0x0FFF
#define MASK_13BITS     0x1FFF
#define MASK_14BITS     0x3FFF
#define MASK_15BITS     0x7FFF
#define MASK_16BITS     0xFFFF
#define MASK_18BITS     0x3FFFF
#define MASK_20BITS     0xFFFFF
#define MASK_22BITS     0x3FFFFF
#define MASK_24BITS     0xFFFFFF
#define MASK_31BITS     0x7FFFFFFF

#define MASK_32BITS     0xFFFFFFFF
#define MASK_33BITS_LONGLONG  0x1FFFFFFFFLL

class Utils
{

private:
    Utils();


public:
    static int getUnsignedByte(const char b);
    static char getInt2UnsignedByte(const int b);
    static int getInt(const char* bytes, const int offset, const int len, const int mask);
    static long long getLong(const char* bytes, const int offset, const int len, const long long mask);
    static int getBit(const char b, const int i);
    static int getBits(const char b, const int i, const int len);

    static std::string getStreamTypeString(const int tag);
    static std::string::size_type strPrintf(std::string& rstr, const char *pFmt, ...);

    //static std::string getBCD(const char* buffer, const int nibble_no, const int length);
    static long int getBcdInt(long int val);
};

#endif // UTILS_H
