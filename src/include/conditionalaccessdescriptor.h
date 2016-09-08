/*
 *Original Author:	shko
 */

#ifndef CONDITIONALACCESSDESCRIPTOR_H
#define CONDITIONALACCESSDESCRIPTOR_H

#include "descriptor.h"

class ConditionalAccessDescriptor : public Descriptor
{

private:
    int caSystemID;
    int caPID;
    CharVector privateDataByte;

public:
    ConditionalAccessDescriptor(const char* buffer, const int offset, const TableSection* parent);


    int getCaSystemID();
    int getCaPID();
    const CharVector* getPrivateDataByte();

};


#endif // CONDITIONALACCESSDESCRIPTOR_H
