/*
 *Original Author:	shko
 */

#ifndef CRC32_H
#define CRC32_H

#include <utils.h>

class Crc32
{

private:
    Crc32();

public:
    static const long long crc32_table[256];

    static long long getCrc32(const char* data, const int len);
};


#endif // CRC32_H
