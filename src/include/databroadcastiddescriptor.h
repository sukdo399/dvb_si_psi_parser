/*
 *Original Author:	shko
 */

#ifndef DATABROADCASTIDDESCRIPTOR_H
#define DATABROADCASTIDDESCRIPTOR_H

#include "descriptor.h"

class DataBroadcastIDDescriptor : public Descriptor
{


private:
    const int dataBroadcastId;
    CharVector selectorByte;


public:
    DataBroadcastIDDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getDataBroadcastId();
    const CharVector* getSelectorByte();

};


#endif // DATABROADCASTIDDESCRIPTOR_H
