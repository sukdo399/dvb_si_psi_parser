/*
 *Original Author:	shko
 */

#include "timeshiftedeventdescriptor.h"


TimeShiftedEventDescriptor::TimeShiftedEventDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      referenceServiceId(Utils::getInt(buffer, offset + 2, 2, MASK_16BITS)),
      referenceEventId(Utils::getInt(buffer, offset + 4, 2, MASK_16BITS))
{
    ;
}

int TimeShiftedEventDescriptor::getReferenceServiceId()
{
    return referenceServiceId;
}

int TimeShiftedEventDescriptor::getReferenceEventId()
{
    return referenceEventId;
}
