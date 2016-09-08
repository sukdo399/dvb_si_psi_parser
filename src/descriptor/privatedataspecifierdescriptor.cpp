/*
 *Original Author:	shko
 */

#include <privatedataspecifierdescriptor.h>

PrivateDataSpecifierDescriptor::PrivateDataSpecifierDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      privateDataSpecifier(Utils::getInt(buffer, offset + 2, 4, MASK_32BITS))
{
    ;
}

int PrivateDataSpecifierDescriptor::getPrivateDataSpecifier()
{
    return privateDataSpecifier;
}
