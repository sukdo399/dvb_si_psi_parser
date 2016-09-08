/*
 *Original Author:	shko
 */


#include <smoothingbufferdescriptor.h>


SmoothingBufferDescriptor::SmoothingBufferDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      reserved(Utils::getInt(buffer, offset + 2, 2, MASK_2BITS)),
      sbLeakRate(Utils::getInt(buffer, offset + 2, 3, MASK_22BITS)),
      reserved2(Utils::getInt(buffer, offset + 5, 2, MASK_2BITS)),
      sbSize(Utils::getInt(buffer,offset + 5, 3, MASK_22BITS))
{
    ;
}

int SmoothingBufferDescriptor::getReserved()
{
    return reserved;
}

int SmoothingBufferDescriptor::getSbLeakRate()
{
    return sbLeakRate;
}



int SmoothingBufferDescriptor::getReserved2()
{
    return reserved2;
}

int SmoothingBufferDescriptor::getSbSize()
{
    return sbSize;
}
