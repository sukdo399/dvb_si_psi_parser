/*
 *Original Author:	shko
 */

#include <networknamedescriptor.h>


NetworkNameDescriptor::NetworkNameDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset, parent)
    , networkName(std::string((char *)&buffer[offset + 2], descriptorLength))
{
    ;
}


std::string NetworkNameDescriptor::getNetworkName(void)
{
    return networkName;
}
