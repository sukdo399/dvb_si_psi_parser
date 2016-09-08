/*
 *Original Author:	shko
 */

#ifndef SYSTEMCLOCKDESCRIPTOR_H
#define SYSTEMCLOCKDESCRIPTOR_H

#include "descriptor.h"

class SystemClockDescriptor : public Descriptor
{

private:
    const int externalClockReferenceIndicator;
    const int reserved;
    const int clockAccuracyInteger;
    const int clockAccuracyExponent;
    const int reserved2;

public:
    SystemClockDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getExternalClockReferenceIndicator();
    int getReserved();
    int getClockAccuracyInteger();
    int getClockAccuracyExponent();
    int getReserved2();

};


#endif // SYSTEMCLOCKDESCRIPTOR_H
