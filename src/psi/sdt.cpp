/*
 *Original Author:	shko
 */

#include <sdt.h>

SDT::Service::Service(int svcId, int reserv, bool eitSchFlag, bool eitPfFlag, int runn, bool freeCa, int loopLen, DescriptorVector descVector)
{
    InitInternalData();

    serviceID = svcId;
    reserved = reserv;
    eitScheduleFlag = eitSchFlag;
    eitPresentFollowingFlag = eitPfFlag;
    runningStatus = runn;
    freeCAmode = freeCa;
    serviceDescriptorLoopLength = loopLen;

    descriptorVector = descVector;
}

SDT::Service::~Service()
{
    for(DescriptorIterator i = descriptorVector.begin(); i != descriptorVector.end(); ++i)
        delete *i;
}

int SDT::Service::getServiceID()
{
    return serviceID;
}

int SDT::Service::getReserved()
{
    return reserved;
}

bool SDT::Service::getEitPresentFollowingFlag()
{
    return eitPresentFollowingFlag;
}

bool SDT::Service::getEitScheduleFlag()
{
    return eitScheduleFlag;
}

int SDT::Service::getRunningStatus()
{
    return runningStatus;
}

bool SDT::Service::getFreeCAmode()
{
    return freeCAmode;
}

int SDT::Service::getServiceDescriptorLoopLength()
{
    return serviceDescriptorLoopLength;
}

DescriptorVector* SDT::Service::getDescriptorVector()
{
    return &descriptorVector;
}

void SDT::Service::InitInternalData()
{
    serviceID = 0;
    reserved = 0;
    eitScheduleFlag = 0;
    eitPresentFollowingFlag = 0;
    runningStatus = 0;
    freeCAmode = 0;
    serviceDescriptorLoopLength = 0;
}



SDT::SDT(const char *raw_data)
    : TableSectionExtendedSyntax(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

SDT::SDT(const char *raw_data, const int siSpec)
    : TableSectionExtendedSyntax(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);
}

SDT::~SDT()
{
    for(SDTServiceIterator i = serviceVector.begin(); i != serviceVector.end(); ++i)
        delete *i;
}

int SDT::getOriginalNetworkID()
{
    return originalNetworkID;
}

int SDT::getTransportStreamID()
{
    return getTableIdExtension();
}

int SDT::getNumberOfServices()
{
    return serviceVector.size();
}

std::vector<SDT::Service*>* SDT::getServiceVector()
{
    return &serviceVector;
}

std::vector<SDT::Service*> SDT::buildServicesVector(const char *data, const int i, const int programInfoLength)
{
    std::vector<Service*> r = std::vector<Service*>();
    int t = 0;
    while (t < programInfoLength)
    {
        Service * const c = new Service(Utils::getInt(data, i + t, 2, 0xFFFF),
                                        Utils::getInt(data, i + t + 2, 1, 0xFC) >> 2,
                                        (Utils::getInt(data, i + t + 2, 1, 0x02) >> 1) ? true : false,
                                        (Utils::getInt(data, i + t + 2, 1, 0x01)) ? true : false,
                                        Utils::getInt(data, i + t + 3, 1, 0xE0) >> 5,
                                        (Utils::getInt(data, i + t + 3, 1, 0x10) >> 4) ? true : false,
                                        Utils::getInt(data, i + t + 3, 2, 0x0FFF),
                                        DescriptorBuilder::buildDescriptorVector(data,i + t + 5, Utils::getInt(data, i + t + 3, 2, 0x0FFF), this)
                                        );

        t += 5 + c->getServiceDescriptorLoopLength();
        r.push_back(c);

    }

    return r;
}




std::string SDT::getEitScheduleFlagString(const int eitScheduleFlag)
{

    switch (eitScheduleFlag)
    {
        case 0:
            return "No EIT schedule information";
        case 1:
            return "EIT schedule information present in TS";
        default:
            return "Illegal value";
    }

}

std::string SDT::getEitPresentFollowingFlagString(const int eitPresentFollowingFlag)
{

    switch (eitPresentFollowingFlag)
    {
        case 0:
            return "No EIT_present_following information";
        case 1:
            return "EIT_present_following information present in TS";
        default:
            return "Illegal value";
    }

}

void SDT::InitInternalData()
{
    originalNetworkID = 0;
    serviceVector.clear();
}

void SDT::SetInternalData(const char *raw_data)
{
    originalNetworkID = Utils::getInt(raw_data, 8, 2, MASK_16BITS);
    serviceVector = buildServicesVector(raw_data, 11, sectionLength - 12);
}
