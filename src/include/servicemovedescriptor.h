/*
 *Original Author:	shko
 */

#ifndef SERVICEMOVEDESCRIPTOR_H
#define SERVICEMOVEDESCRIPTOR_H

#include "descriptor.h"

class ServiceMoveDescriptor : public Descriptor
{

private:
    const int newOriginalNetworkId;
    const int newTransportStreamId;
    const int newServiceId;


public:
    ServiceMoveDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getNewOriginalNetworkId();
    int getNewTransportStreamId();
    int getNewServiceId();

};
#endif // SERVICEMOVEDESCRIPTOR_H
