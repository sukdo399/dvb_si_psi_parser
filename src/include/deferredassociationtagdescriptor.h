/*
 *Original Author:	shko
 */

#ifndef DEFERREDASOCIATIONTAGDESCRIPTOR__H
#define DEFERREDASOCIATIONTAGDESCRIPTOR__H

#include "descriptor.h"

class DeferredAssociationTagDescriptor : public Descriptor
{
public:
    class AssociationTag
    {
    private:
        const int associationTag;
    public:
        AssociationTag(const int associationTag);
        virtual ~AssociationTag(void);

        int getAssociationTag();
    };

private:
    const int associationTagsLoopLength;
    const int transportStreamId;
    const int programNumber;
    const int originalNetworkId;

    CharVector privateDataByte;

    std::vector<AssociationTag*> associationTagVector;

public:
    DeferredAssociationTagDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~DeferredAssociationTagDescriptor(void);

    int getAssociationTagsLoopLength();
    int getTransportStreamId();
    int getProgramNumber();
    int getOriginalNetworkId();
    const CharVector* getPrivateDataByte();

    std::vector<DeferredAssociationTagDescriptor::AssociationTag*>* getAssociationTagVector();

};

typedef std::vector<DeferredAssociationTagDescriptor::AssociationTag*> AssociationTagVector;
typedef AssociationTagVector::iterator AssociationTagIterator;
typedef AssociationTagVector::const_iterator AssociationTagConstIterator;

#endif // DEFERREDASOCIATIONTAGDESCRIPTOR__H
