/*
 *Original Author:	shko
 */

#include <shortsmoothingbufferdescriptor.h>

ShortSmoothingBufferDescriptor::ShortSmoothingBufferDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      sb_size(Utils::getInt(buffer, offset + 2, 1, 0xC0) >> 6),
      sb_leak_rate(Utils::getInt(buffer, offset + 2, 1, MASK_6BITS))
{
    ;
}

int ShortSmoothingBufferDescriptor::getSbSize()
{
    return sb_size;
}

int ShortSmoothingBufferDescriptor::getSbLeakRate()
{
    return sb_leak_rate;
}
