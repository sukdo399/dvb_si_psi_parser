/*
 *Original Author:	shko
 */

#include <servicemovedescriptor.h>

ServiceMoveDescriptor::ServiceMoveDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      newOriginalNetworkId(Utils::getInt(buffer, offset + 2, 2, MASK_16BITS)),
      newTransportStreamId(Utils::getInt(buffer, offset + 4, 2, MASK_16BITS)),
      newServiceId(Utils::getInt(buffer, offset + 6, 2, MASK_16BITS))
{
    ;
}

int ServiceMoveDescriptor::getNewOriginalNetworkId()
{
    return newOriginalNetworkId;
}

int ServiceMoveDescriptor::getNewTransportStreamId()
{
    return newTransportStreamId;
}

int ServiceMoveDescriptor::getNewServiceId()
{
    return newServiceId;
}
