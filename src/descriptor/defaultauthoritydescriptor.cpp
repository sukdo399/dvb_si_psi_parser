/*
 *Original Author:	shko
 */

#include <defaultauthoritydescriptor.h>

DefaultAuthorityDescriptor::DefaultAuthorityDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
{
    int t = offset + 2;

    default_authority_byte.resize(descriptorLength);
    memcpy(&default_authority_byte[0], buffer + t, descriptorLength);
}

CharVector* DefaultAuthorityDescriptor::getDefaultAuthorityByte()
{
    return &default_authority_byte;
}
