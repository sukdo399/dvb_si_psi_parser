/*
 *Original Author:	shko
 */

#ifndef ASSOCIATIONTAGDESCRIPTOR_H
#define ASSOCIATIONTAGDESCRIPTOR_H

#include <descriptor.h>


class AssociationTagDescriptor : public Descriptor
{

private:
    const int associationTag;
    const int use;

    int transactionId;
    int timeout;
    int selectorLength;
    CharVector selectorByte;

    CharVector privateDataByte;

public:
    AssociationTagDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getAssociationTag();
    int getUse();

    int getSelectorLength();
    int getTransactionId();
    int getTimeout();

    const CharVector* getSelectorByte();



    const CharVector* getPrivateDataByte();

    static std::string getUseString(const int use);
};

#endif // ASSOCIATIONTAGDESCRIPTOR_H
