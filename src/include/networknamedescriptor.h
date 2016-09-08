/*
 *Original Author:	shko
 */

#ifndef NETWORKNAMEDESCRIPTOR_H
#define NETWORKNAMEDESCRIPTOR_H

#include "descriptor.h"

class NetworkNameDescriptor : public Descriptor
{


private:
    const std::string networkName;

public:
    NetworkNameDescriptor(const char* buffer, const int offset, const TableSection* parent);

    std::string getNetworkName();


};


#endif // NETWORKNAMEDESCRIPTOR_H
