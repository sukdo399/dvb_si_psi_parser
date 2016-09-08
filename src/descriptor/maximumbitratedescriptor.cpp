/*
 *Original Author:	shko
 */


#include <maximumbitratedescriptor.h>


MaximumBitrateDescriptor::MaximumBitrateDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      reserved(Utils::getInt(buffer, offset + 2, 2, MASK_2BITS)),
      maximumBitrate(Utils::getInt(buffer, offset + 2, 3, MASK_22BITS))

{
    ;
}


int MaximumBitrateDescriptor::getReserved()
{
    return reserved;
}


int MaximumBitrateDescriptor::getMaximumBitrate()
{
    return maximumBitrate;
}


