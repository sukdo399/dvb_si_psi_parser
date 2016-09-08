/*
 *Original Author:	shko
 */

#include <servicedescriptor.h>

ServiceDescriptor::ServiceDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent)
    , serviceType(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS))
    , serviceProviderNameLength(Utils::getInt(buffer, offset + 3, 1, MASK_8BITS))
    , serviceProviderName(std::string((char *)&buffer[offset + 4], serviceProviderNameLength))
    , serviceNameLength(Utils::getInt(buffer, offset + 4 + serviceProviderNameLength, 1, MASK_8BITS))
    , serviceName(std::string((char *)&buffer[offset + 5 + serviceProviderNameLength], serviceNameLength))
{
    ;
}


int ServiceDescriptor::getServiceType()
{
    return serviceType;
}

int ServiceDescriptor::getServiceProviderNameLength()
{
    return serviceProviderName.length();
}

std::string ServiceDescriptor::getServiceProviderName()
{
    return serviceProviderName;
}

int ServiceDescriptor::getServiceNameLength()
{
    return serviceName.length();
}

std::string ServiceDescriptor::getServiceName()
{
    return serviceName;
}



