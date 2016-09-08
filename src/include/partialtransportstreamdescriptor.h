/*
 *Original Author:	shko
 */

#ifndef PARTIALTRANSPORTSTREAMDESCRIPTOR_H
#define PARTIALTRANSPORTSTREAMDESCRIPTOR_H

#include "descriptor.h"

class PartialTransportStreamDescriptor : public Descriptor
{


private:
    const int peakRate;
    const int minimumOverallSmoothingRate;
    const int maximumOverallSmoothingBuffer;

public:
    PartialTransportStreamDescriptor(const char*, const int offset, const TableSection* parent);

    int getPeakRate();
    int getMinimumOverallSmoothingRate();
    int getMaximumOverallSmoothingBuffer();

};

#endif // PARTIALTRANSPORTSTREAMDESCRIPTOR_H
