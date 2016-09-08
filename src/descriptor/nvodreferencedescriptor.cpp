/*
 *Original Author:	shko
 */

#include <nvodreferencedescriptor.h>

NvodReferenceDescriptor::NvodService::NvodService(const int transportStreamId, const int originalNetworkId, const int serviceId)
    : transportStreamId(transportStreamId)
    , originalNetworkId(originalNetworkId)
    , serviceId(serviceId)
{
    ;
}

NvodReferenceDescriptor::NvodService::~NvodService(void)
{
    ;
}

int NvodReferenceDescriptor::NvodService::getTransportStreamId()
{
    return transportStreamId;
}

int NvodReferenceDescriptor::NvodService::getOriginalNetworkId()
{
    return originalNetworkId;
}

int NvodReferenceDescriptor::NvodService::getServiceId()
{
    return serviceId;
}



NvodReferenceDescriptor::NvodReferenceDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent)
{
    int t = 0;
    while (t < descriptorLength)
    {
        const int tsid = Utils::getInt(buffer, offset + 2 + t, 2,MASK_16BITS);
        const int onid = Utils::getInt(buffer, offset + 4 + t, 2, MASK_16BITS);
        const int svcid = Utils::getInt(buffer, offset + 6 + t, 2, MASK_16BITS);

        NvodService* service = new NvodService(tsid, onid, svcid);
        nvodServiceVector.push_back(service);

        t += 6;
    }


}

NvodReferenceDescriptor::~NvodReferenceDescriptor(void)
{
    for(NvodServiceIterator i = nvodServiceVector.begin(); i != nvodServiceVector.end(); ++i)
        delete *i;
}



std::vector<NvodReferenceDescriptor::NvodService*>* NvodReferenceDescriptor::getNvodServiceVector()
{
    return &nvodServiceVector;
}

