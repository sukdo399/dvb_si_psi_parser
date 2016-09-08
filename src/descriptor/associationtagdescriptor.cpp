/*
 *Original Author:	shko
 */

#include <associationtagdescriptor.h>

AssociationTagDescriptor::AssociationTagDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      associationTag(Utils::getInt(buffer, offset + 2, 2, MASK_16BITS)),
      use(Utils::getInt(buffer, offset + 4, 2, MASK_16BITS))
{
    int t = 6 + offset;

    transactionId = 0;
    timeout = 0;
    selectorLength = 0;
    selectorByte.clear();

    privateDataByte.clear();

    if (use == 0x0000)
    {
        selectorLength = Utils::getInt(buffer, offset + 6, 1, MASK_8BITS); // 0x08;
        transactionId = Utils::getInt(buffer, offset + 7, 4, MASK_32BITS);
        timeout = Utils::getInt(buffer, offset + 11, 4, MASK_32BITS);
        t += 9;
    }
    else if (use == 0x0001)
    {
        selectorLength = Utils::getInt(buffer, offset + 6, 1, MASK_8BITS); // 0x00;
        t++;
    }
    else
    {
        selectorLength = Utils::getInt(buffer, offset + 6, 1, MASK_8BITS);
        selectorByte.resize(selectorLength);
        memcpy(&selectorByte[0], buffer + offset + 7, selectorLength);
        t += 1 + selectorLength;
    }

    privateDataByte.resize(descriptorLength - ((t-offset) - 2));
    memcpy(&privateDataByte[0], buffer + t, descriptorLength - ((t-offset) - 2));

}


int AssociationTagDescriptor::getAssociationTag()
{
    return associationTag;
}

int AssociationTagDescriptor::getUse()
{
    return use;
}


int AssociationTagDescriptor::getSelectorLength()
{
    return selectorLength;
}

int AssociationTagDescriptor::getTransactionId()
{
    return transactionId;
}

int AssociationTagDescriptor::getTimeout()
{
    return timeout;
}

const CharVector* AssociationTagDescriptor::getSelectorByte()
{
    return &selectorByte;
}

const CharVector* AssociationTagDescriptor::getPrivateDataByte()
{
    return &privateDataByte;
}


std::string AssociationTagDescriptor::getUseString(const int use)
{
    if (use == 0)
    {
        return "DSI with IOR of SGW";
    }
    else if (use == 1)
    {
        return "General Object Carousel Data";
    }
    else if ((use >= 0x100) && (use <= 0x1fff))
    {
        return "DVB reserved";
    }
    else if ((use >= 0x2000) && (use <= 0xffff))
    {
        return "user private";
    }
    else
    {
        return "unknown";
    }
}
