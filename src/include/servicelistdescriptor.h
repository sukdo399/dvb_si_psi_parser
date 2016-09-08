/*
 *Original Author:	shko
 */

#ifndef SERVICELISTDESCRIPTOR_H
#define SERVICELISTDESCRIPTOR_H

#include "descriptor.h"

class ServiceListDescriptor : public Descriptor
{
public:
    class Service
    {
    private:
        const ServiceListDescriptor* outerInstance;
        const int serviceID;
        const int serviceType;

    public:
        Service(ServiceListDescriptor* outerInstance, const int serviceid, const int servicetype);
        virtual ~Service(void);

        int getServiceID();
        int getServiceType();
        std::string getServiceTypeString();

    };


private:
    std::vector<Service*> serviceVector; // TODO: const


public:
    ServiceListDescriptor(const char* buffe, const int offset, const TableSection* parent);
    virtual ~ServiceListDescriptor(void);

    int getServiceCount();
    std::vector<ServiceListDescriptor::Service*>* getServiceVector();

};

typedef std::vector<ServiceListDescriptor::Service *> ServiceVector;
typedef ServiceVector::iterator ServiceIterator;
typedef ServiceVector::const_iterator ServiceConstIterator;

#endif // SERVICELISTDESCRIPTOR_H
