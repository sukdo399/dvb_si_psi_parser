/*
 *Original Author:	shko
 */

#include <eit.h>

EIT::Event::Event(int eid, CharVector stTime, int stTimeM,
                  int stTimeB, CharVector dur, int durB,
                  int runn, bool freeCa, int loopLen, DescriptorVector descVec)
{
    InitInternalData();

    eventID = eid;
    startTime = stTime;
    startTimeMjd = stTimeM;
    startTimeBcd = stTimeB;
    duration = dur;
    durationBcd = durB;
    runningStatus = runn;
    freeCAMode = freeCa;
    descriptorsLoopLength = loopLen;

    descriptorVector = descVec;
}

EIT::Event::~Event()
{
    for(DescriptorIterator i = descriptorVector.begin(); i != descriptorVector.end(); ++i)
        delete *i;
}

int EIT::Event::getEventID()
{
    return eventID;
}

CharVector* EIT::Event::getStartTime()
{
    return &startTime;
}

int EIT::Event::getStartTimeMjd()
{
    return startTimeMjd;
}

int EIT::Event::getStartTimeBcd()
{
    return startTimeBcd;
}

CharVector* EIT::Event::getDuration()
{
    return &duration;
}

int EIT::Event::getDurationBcd()
{
    return durationBcd;
}

int EIT::Event::getRunningStatus()
{
    return runningStatus;
}

bool EIT::Event::getFreeCAMode()
{
    return freeCAMode;
}

int EIT::Event::getDescriptorsLoopLength()
{
    return descriptorsLoopLength;
}

std::string EIT::Event::getEventName()
{
    DescriptorConstIterator descs = descriptorVector.begin();
    while (descs != descriptorVector.end())
    {
        Descriptor* d = *descs;
        if (dynamic_cast<ShortEventDescriptor*>(d) != nullptr)
        {
            return (static_cast<ShortEventDescriptor*>(d))->getEventName();
        }
        descs++;
    }

    return "";

}

DescriptorVector* EIT::Event::getDescriptorVector()
{
    return &descriptorVector;
}

void EIT::Event::InitInternalData()
{
    eventID = 0;
    startTime.clear();
    startTimeMjd = 0;
    startTimeBcd = 0;
    duration.clear();
    durationBcd = 0;
    runningStatus = 0;
    freeCAMode = false;
    descriptorsLoopLength = 0;

    descriptorVector.clear();
}

EIT::EIT(const char *raw_data)
    : TableSectionExtendedSyntax(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

EIT::EIT(const char *raw_data, const int siSpec)
    : TableSectionExtendedSyntax(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);

}

EIT::~EIT()
{
    for(EITEventIterator i = eventVector.begin(); i != eventVector.end(); ++i)
        delete *i;
}

int EIT::getServiceId()
{
    return getTableIdExtension();
}

int EIT::getTransportStreamId()
{
    return transportStreamID;
}

int EIT::getOriginalNetworkId()
{
    return originalNetworkID;
}

int EIT::getSegmentLastSectionNumber()
{
    return segmentLastSectionNumber;
}

int EIT::getLastTableId()
{
    return lastTableID;
}

int EIT::getNumberOfEvents()
{
    return eventVector.size();
}

std::vector<EIT::Event*>* EIT::getEventVector()
{
    return &eventVector;
}



std::vector<EIT::Event*> EIT::buildEventVector(const char *data, const int i, const int programInfoLength)
{
    EITEventVector r = EITEventVector();
    int t = 0;
    while (t < programInfoLength)
    {
        CharVector stTime;
        stTime.resize(5);
        memcpy(&stTime[0], data + i + t + 2, 5);

        CharVector dur;
        dur.resize(3);
        memcpy(&dur[0], data + i + t + 7, 3);

        Event* c = new Event(Utils::getInt(data, i + t, 2, MASK_16BITS),
                            stTime,
                            Utils::getInt(data, i + t + 2, 2, MASK_16BITS),
                            Utils::getBcdInt(Utils::getInt(data, i + t + 4, 3, MASK_24BITS)),
                            dur,
                            Utils::getBcdInt(Utils::getInt(data, i + t + 7, 3, MASK_24BITS)),
                            Utils::getInt(data, i + t + 10, 1, 0xE0) >> 5,
                            (Utils::getInt(data, i + t + 10, 1, 0x10) >> 4) ? true : false,
                            Utils::getInt(data, i + t + 10, 2, MASK_12BITS),
                            DescriptorBuilder::buildDescriptorVector(data, i + t + 12, Utils::getInt(data, i + t + 10, 2, MASK_12BITS), this)
                             );

        r.push_back(c);

        t += 12 + c->getDescriptorsLoopLength();
    }

    return r;
}
void EIT::InitInternalData()
{
    transportStreamID = 0;
    originalNetworkID = 0;
    segmentLastSectionNumber = 0;
    lastTableID = 0;

    eventVector.clear();
}
void EIT::SetInternalData(const char *raw_data)
{

    transportStreamID = Utils::getInt(raw_data, 8, 2, MASK_16BITS);
    originalNetworkID = Utils::getInt(raw_data, 10, 2, MASK_16BITS);
    segmentLastSectionNumber = Utils::getInt(raw_data, 12, 1, MASK_8BITS);
    lastTableID = Utils::getInt(raw_data, 13, 1, MASK_8BITS);

    //consider start and CRC(4)
    eventVector = buildEventVector(raw_data, 14, sectionLength - 14 - 4);

}
