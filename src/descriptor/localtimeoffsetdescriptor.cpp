/*
 *Original Author:	shko
 */

#include <localtimeoffsetdescriptor.h>

LocalTimeOffsetDescriptor::LocalTimeOffset::LocalTimeOffset(const std::string &ccode, const int id, const int localPolarity, const int localOffset, CharVector timeChange, const int timeChangeMjd, const int timeChangeBcd, const int nextOffset)
    : countryCode(ccode),
      countryRegionId(id),
      localTimeOffsetPolarity(localPolarity),
      localTimeOffset(localOffset),
      timeOfChange(timeChange),
      timeOfChangeMjd(timeChangeMjd),
      timeOfChangeBcd(timeChangeBcd),
      nextTimeOffset(nextOffset)
{
    ;
}

LocalTimeOffsetDescriptor::LocalTimeOffset::~LocalTimeOffset(void)
{
    ;
}

std::string LocalTimeOffsetDescriptor::LocalTimeOffset::getCountryCode()
{
    return countryCode;
}

int LocalTimeOffsetDescriptor::LocalTimeOffset::getCountryRegionId()
{
    return countryRegionId;
}

int LocalTimeOffsetDescriptor::LocalTimeOffset::getLocalTimeOffsetPolarity()
{
    return localTimeOffsetPolarity;
}

int LocalTimeOffsetDescriptor::LocalTimeOffset::getLocalTimeOffset()
{
    return localTimeOffset;
}

const CharVector* LocalTimeOffsetDescriptor::LocalTimeOffset::getTimeOfChange()
{
    return &timeOfChange;
}

int LocalTimeOffsetDescriptor::LocalTimeOffset::getTimeOfChangeMjd()
{
    return timeOfChangeMjd;
}

int LocalTimeOffsetDescriptor::LocalTimeOffset::getTimeOfChangeBcd()
{
    return timeOfChangeBcd;
}

int LocalTimeOffsetDescriptor::LocalTimeOffset::getNextTimeOffset()
{
    return nextTimeOffset;
}


LocalTimeOffsetDescriptor::LocalTimeOffsetDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset, parent)
{
    int t = 0;

    while (t < descriptorLength)
    {
        std::string countryCode;
        countryCode.assign((char *)&buffer[offset + 2 + t], 3);
        const int countryRegionId = Utils::getInt(buffer, offset + t + 5, 1, 0xFC) >> 2;
        const int localTimeOffsetPolarity = Utils::getInt(buffer, offset + t + 5, 1, MASK_1BIT);
        const int localTimeOffset = Utils::getBcdInt(Utils::getInt(buffer, offset + t + 6, 2, MASK_16BITS));
        CharVector timeOfChange;
        timeOfChange.resize(5);
        memcpy(&timeOfChange[0], buffer+t+8, 5);
        const int timeOfChangeMjd = Utils::getInt(buffer, offset + t + 8, 2, MASK_16BITS);
        const int timeOfChangeBcd = Utils::getBcdInt(Utils::getInt(buffer, offset + t + 10, 3, MASK_24BITS));
        const int nextTimeOffset = Utils::getBcdInt(Utils::getInt(buffer, offset + t + 13, 2, MASK_16BITS));

        LocalTimeOffset* s = new LocalTimeOffset(countryCode,countryRegionId,localTimeOffsetPolarity
                                                 ,localTimeOffset
                                                 ,timeOfChange, timeOfChangeMjd, timeOfChangeBcd
                                                 , nextTimeOffset);
        offsetVector.push_back(s);
        t += 13;
    }
}

LocalTimeOffsetDescriptor::~LocalTimeOffsetDescriptor(void)
{
    for(LocalTimeOffsetIterator i = offsetVector.begin(); i != offsetVector.end(); ++i)
        delete *i;
}

std::vector<LocalTimeOffsetDescriptor::LocalTimeOffset *>* LocalTimeOffsetDescriptor::getLocalOffsetVector()
{
    return &offsetVector;
}

