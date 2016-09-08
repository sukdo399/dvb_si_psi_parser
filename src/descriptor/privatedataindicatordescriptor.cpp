/*
 *Original Author:	shko
 */


#include <privatedataindicatordescriptor.h>

PrivateDataIndicatorDescriptor::PrivateDataIndicatorDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
    privateDataIndicator(Utils::getInt(buffer, offset + 2, 4, MASK_32BITS))
{
    ;
}

int PrivateDataIndicatorDescriptor::getPrivateDataIndicator()
{
    return privateDataIndicator;
}



