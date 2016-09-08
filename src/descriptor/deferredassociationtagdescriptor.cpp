/*
 *Original Author:	shko
 */

#include <deferredassociationtagdescriptor.h>

DeferredAssociationTagDescriptor::AssociationTag::AssociationTag(const int associationTag)
    : associationTag(associationTag)
{
    ;
}

DeferredAssociationTagDescriptor::AssociationTag::~AssociationTag()
{
    ;
}

int DeferredAssociationTagDescriptor::AssociationTag::getAssociationTag()
{
    return associationTag;
}

DeferredAssociationTagDescriptor::DeferredAssociationTagDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      associationTagsLoopLength(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS)),
      transportStreamId(Utils::getInt(buffer, offset + 3 + associationTagsLoopLength, 2, MASK_16BITS)),
      programNumber(Utils::getInt(buffer, offset + 3 + associationTagsLoopLength + 2, 2, MASK_16BITS)),
      originalNetworkId(Utils::getInt(buffer, offset + 3 + associationTagsLoopLength + 4, 2, MASK_16BITS))

{
    int t = offset + 3;
    while (t < 3 + associationTagsLoopLength)
    {
        const int associationTag = Utils::getInt(buffer, t, 2, MASK_16BITS);
        AssociationTag* tag = new AssociationTag(associationTag);
        associationTagVector.push_back(tag);
        t += 2;
    }

    t += 6;

    privateDataByte.resize(descriptorLength - ((t-offset) - 2));
    memcpy(&privateDataByte[0], buffer + t, descriptorLength - ((t-offset) - 2));

}

DeferredAssociationTagDescriptor::~DeferredAssociationTagDescriptor()
{
    for(AssociationTagIterator i = associationTagVector.begin(); i != associationTagVector.end(); ++i)
        delete *i;
}

int DeferredAssociationTagDescriptor::getAssociationTagsLoopLength()
{
    return associationTagsLoopLength;
}

int DeferredAssociationTagDescriptor::getTransportStreamId()
{
    return transportStreamId;
}

int DeferredAssociationTagDescriptor::getProgramNumber()
{
    return programNumber;
}

int DeferredAssociationTagDescriptor::getOriginalNetworkId()
{
    return originalNetworkId;
}

const CharVector* DeferredAssociationTagDescriptor::getPrivateDataByte()
{
    return &privateDataByte;
}

std::vector<DeferredAssociationTagDescriptor::AssociationTag*>* DeferredAssociationTagDescriptor::getAssociationTagVector()
{
    return &associationTagVector;
}
