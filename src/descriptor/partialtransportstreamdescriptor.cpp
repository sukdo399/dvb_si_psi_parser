/*
 *Original Author:	shko
 */

#include <partialtransportstreamdescriptor.h>

PartialTransportStreamDescriptor::PartialTransportStreamDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      peakRate(Utils::getInt(buffer, offset + 2, 3, MASK_22BITS)),
      minimumOverallSmoothingRate(Utils::getInt(buffer, offset + 5, 3, MASK_22BITS)),
      maximumOverallSmoothingBuffer(Utils::getInt(buffer, offset + 8, 2, MASK_14BITS))
{
    ;
}

int PartialTransportStreamDescriptor::getPeakRate()
{
    return peakRate;
}

int PartialTransportStreamDescriptor::getMinimumOverallSmoothingRate()
{
    return minimumOverallSmoothingRate;
}

int PartialTransportStreamDescriptor::getMaximumOverallSmoothingBuffer()
{
    return maximumOverallSmoothingBuffer;
}
