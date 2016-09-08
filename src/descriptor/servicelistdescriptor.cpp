/*
 *Original Author:	shko
 */

#include <servicelistdescriptor.h>

ServiceListDescriptor::Service::Service(ServiceListDescriptor* outerInstance, const int id, const int type)
    : outerInstance(outerInstance)
    , serviceID(id)
    , serviceType(type)
{
    ;
}

ServiceListDescriptor::Service::~Service(void)
{
    ;
}

int ServiceListDescriptor::Service::getServiceID()
{
    return serviceID;
}

int ServiceListDescriptor::Service::getServiceType()
{
    return serviceType;
}

std::string ServiceListDescriptor::Service::getServiceTypeString()
{
    // TODO:
    // return Descriptor::getServiceTypeString(serviceType);
    return "should be implemented";
}


ServiceListDescriptor::ServiceListDescriptor(const char* buffer, const int offset, const TableSection* parent) : Descriptor(buffer, offset,parent)
{
    int t = 0;
    while (t < descriptorLength)
    {
        const int serviceId = Utils::getInt(buffer, offset + 2 + t,2,MASK_16BITS);
        const int serviceType = Utils::getInt(buffer, offset + 4 + t,1,MASK_8BITS);

        Service* service = new Service(this, serviceId,serviceType); // TODO: const
        serviceVector.push_back(service);

        t += 3;
    }

    // TODO:
    //this->setServiceVector(r);
}

ServiceListDescriptor::~ServiceListDescriptor(void)
{
    for(ServiceIterator i = serviceVector.begin(); i != serviceVector.end(); ++i)
        delete *i;
}

int ServiceListDescriptor::getServiceCount()
{
    return serviceVector.size();
}


std::vector<ServiceListDescriptor::Service*>* ServiceListDescriptor::getServiceVector()
{
    return &serviceVector;
}

