/*
 *Original Author:	shko
 */

#include <tdt.h>

TDT::TDT(const char *raw_data)
    : TableSection(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

TDT::TDT(const char *raw_data, const int siSpec)
    : TableSection(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);
}

CharVector* TDT::getUtcTime()
{
    return &UTC_time;
}

int TDT::getUtcTimeMjd()
{
    return UTC_time_mjd;
}

int TDT::getUtcTimeBcd()
{
    return UTC_time_bcd;
}

void TDT::InitInternalData()
{
    UTC_time.clear();
    UTC_time_mjd = 0;
    UTC_time_bcd = 0;
}

void TDT::SetInternalData(const char *raw_data)
{
    UTC_time.resize(5);
    memcpy(&UTC_time[0], raw_data + 3, 5);

    UTC_time_mjd = Utils::getInt(raw_data, 3, 2, MASK_16BITS);
    UTC_time_bcd = Utils::getBcdInt(Utils::getInt(raw_data, 5, 3, MASK_24BITS));

}
