/*
 *Original Author:	shko
 */


#include <multiplexbufferutilizationdescriptor.h>

MultiplexBufferUtilizationDescriptor::MultiplexBufferUtilizationDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      boundValidFlag((Utils::getInt(buffer, offset + 2, 1, 0x80) >> 7) ? true : false),
      ltwOffsetLowerBound(Utils::getInt(buffer, offset + 2, 2, MASK_15BITS)),
      ltwOffsetUpperBound(Utils::getInt(buffer, offset + 4, 2 , MASK_15BITS))
{
    ;
}



bool MultiplexBufferUtilizationDescriptor::getBoundValidFlag()
{
    return boundValidFlag;
}

int MultiplexBufferUtilizationDescriptor::getLtwOffsetLowerBound()
{
    return ltwOffsetLowerBound;
}

int MultiplexBufferUtilizationDescriptor::getLtwOffsetUpperBound()
{
    return ltwOffsetUpperBound;
}
