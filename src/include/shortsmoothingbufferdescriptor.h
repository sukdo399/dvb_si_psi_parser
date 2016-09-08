/*
 *Original Author:	shko
 */

#ifndef SHORTSMOOTHINGBUFFERDESCRIPTOR_H
#define SHORTSMOOTHINGBUFFERDESCRIPTOR_H

#include "descriptor.h"

class ShortSmoothingBufferDescriptor : public Descriptor
{

private:
    const int sb_size;
    const int sb_leak_rate;


public:
    ShortSmoothingBufferDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getSbSize();
    int getSbLeakRate();


};


#endif // SHORTSMOOTHINGBUFFERDESCRIPTOR_H
