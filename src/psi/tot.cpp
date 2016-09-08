/*
 *Original Author:	shko
 */

#include <tot.h>


TOT::TOT(const char *raw_data)
    : TableSection(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

TOT::TOT(const char *raw_data, const int siSpec)
    : TableSection(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);
}

TOT::~TOT()
{
    for(DescriptorIterator i = descriptorVector.begin(); i != descriptorVector.end(); ++i)
        delete *i;
}

DescriptorVector* TOT::getDescriptorVector()
{
    return &descriptorVector;
}

CharVector* TOT::getUtcTime()
{
    return &UTC_time;
}

int TOT::getUtcTimeMjd()
{
    return UTC_time_mjd;
}

int TOT::getUtcTimeBcd()
{
    return UTC_time_bcd;
}

void TOT::InitInternalData()
{
    descriptorsLoopLength = 0;
    UTC_time.clear();
    UTC_time_mjd = 0;
    UTC_time_bcd = 0;
    descriptorVector.clear();
}

void TOT::SetInternalData(const char *raw_data)
{
    UTC_time.resize(5);
    memcpy(&UTC_time[0], raw_data + 3, 5);

    UTC_time_mjd = Utils::getInt(raw_data, 3, 2, MASK_16BITS);
    UTC_time_bcd = Utils::getBcdInt(Utils::getInt(raw_data, 5, 3, MASK_24BITS));
    descriptorsLoopLength = Utils::getInt(raw_data, 8, 2, MASK_12BITS);
    descriptorVector = DescriptorBuilder::buildDescriptorVector(raw_data, 10, descriptorsLoopLength - 4, this);

}
