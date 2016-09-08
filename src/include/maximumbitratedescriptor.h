/*
 *Original Author:	shko
 */


#ifndef MAXIMUMBITRATEDESCRIPTOR_H
#define MAXIMUMBITRATEDESCRIPTOR_H

#include "descriptor.h"

class MaximumBitrateDescriptor : public Descriptor
{

private:
    const int reserved;
    const int maximumBitrate;

public:
    MaximumBitrateDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getReserved();
    int getMaximumBitrate();

};


#endif // MAXIMUMBITRATEDESCRIPTOR_H
