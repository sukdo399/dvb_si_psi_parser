/*
 *Original Author:	shko
 */

#include <copyrightdescriptor.h>


CopyrightDescriptor::CopyrightDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      copyrightIdentifier(Utils::getInt(buffer, offset + 2, 4, MASK_32BITS))
{

    int t = offset + 6;

    if (t < descriptorLength)
    {
        additionalCopyrightInfo.resize(descriptorLength - ((t-offset) - 2));
        memcpy(&additionalCopyrightInfo[0], buffer+t, descriptorLength - ((t-offset) - 2));
    }
}

int CopyrightDescriptor::getCopyrightIdentifier()
{
    return copyrightIdentifier;
}


const CharVector* CopyrightDescriptor::getAdditionalCopyrightInfo()
{
    return &additionalCopyrightInfo;
}
