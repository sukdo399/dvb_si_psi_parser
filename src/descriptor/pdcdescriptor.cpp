/*
 *Original Author:	shko
 */

#include <pdcdescriptor.h>

PDCDescriptor::PDCDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      day(Utils::getInt(buffer, offset + 2, 2, 0x0F80) >> 7),
      month(Utils::getInt(buffer, offset + 3, 1, 0x78) >> 3),
      hour(Utils::getInt(buffer, offset + 3, 2, 0x07C0) >> 6),
      minute(Utils::getInt(buffer, offset + 4, 1, MASK_6BITS)),
      programmeIdentificationLabel(Utils::getInt(buffer, offset + 2, 3, MASK_20BITS))
{
    ;
}

int PDCDescriptor::getDay()
{
    return day;
}

int PDCDescriptor::getMonth()
{
    return month;
}

int PDCDescriptor::getHour()
{
    return hour;
}

int PDCDescriptor::getMinute()
{
    return minute;
}

int PDCDescriptor::getProgrammeIdentificationLabel()
{
    return programmeIdentificationLabel;
}

