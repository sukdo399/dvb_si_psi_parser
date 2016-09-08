/*
 *Original Author:	shko
 */

#include <streamIdentifierdescriptor.h>

StreamIdentifierDescriptor::StreamIdentifierDescriptor(const char *buffer, const int offset, const TableSection *parent)
    :Descriptor(buffer, offset, parent),
      componentTag(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS))
{
    ;
}


int StreamIdentifierDescriptor::getComponentTag()
{
    return componentTag;
}
