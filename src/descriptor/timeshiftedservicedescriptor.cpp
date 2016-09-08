/*
 *Original Author:	shko
 */

#include <timeshiftedservicedescriptor.h>


TimeShiftedServiceDescriptor::TimeShiftedServiceDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
    referenceServiceId(Utils::getInt(buffer, offset + 2, 2, MASK_16BITS))
{
    ;
}

int TimeShiftedServiceDescriptor::getReferenceServiceId()
{
    return referenceServiceId;
}

