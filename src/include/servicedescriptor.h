/*
 *Original Author:	shko
 */

#ifndef SERVICEDESCRIPTOR_H
#define SERVICEDESCRIPTOR_H

#include "descriptor.h"

class ServiceDescriptor : public Descriptor
{

private:
    const int serviceType;
    const int serviceProviderNameLength;
    const std::string serviceProviderName;
    const int serviceNameLength;
    const std::string serviceName;

public:
    ServiceDescriptor(const char* buffer, int const offset, const TableSection* parent);

    int getServiceType();
    int getServiceProviderNameLength();
    std::string getServiceProviderName();
    int getServiceNameLength();
    std::string getServiceName();


};

#endif // SERVICEDESCRIPTOR_H
