/*
 *Original Author:	shko
 */


#ifndef SMOOTHINGBUFFERDESCRIPTOR_H
#define SMOOTHINGBUFFERDESCRIPTOR_H

#include "descriptor.h"

class SmoothingBufferDescriptor : public Descriptor
{

private:
    const int reserved;
    const int sbLeakRate;
    const int reserved2;
    const int sbSize;

public:
    SmoothingBufferDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getReserved();
    int getSbLeakRate();
    int getReserved2();
    int getSbSize();

};

#endif // SMOOTHINGBUFFERDESCRIPTOR_H
