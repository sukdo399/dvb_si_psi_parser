/*
 *Original Author:	shko
 */

#include <conditionalaccessdescriptor.h>

ConditionalAccessDescriptor::ConditionalAccessDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      caSystemID(Utils::getInt(buffer, offset + 2, 2, MASK_16BITS)),
      caPID(Utils::getInt(buffer, offset + 4, 2, MASK_13BITS))
{
    int t = offset + 6;

    privateDataByte.resize(descriptorLength - ((t-offset) - 2));
    memcpy(&privateDataByte[0], buffer + t, descriptorLength - ((t-offset) - 2));
}



int ConditionalAccessDescriptor::getCaSystemID()
{
    return caSystemID;
}

int ConditionalAccessDescriptor::getCaPID()
{
    return caPID;
}


const CharVector* ConditionalAccessDescriptor::getPrivateDataByte()
{
    return &privateDataByte;
}

