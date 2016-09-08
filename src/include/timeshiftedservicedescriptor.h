/*
 *Original Author:	shko
 */

#ifndef TIMESHIFTEDSERVICEDESCRIPTOR_H
#define TIMESHIFTEDSERVICEDESCRIPTOR_H

#include "descriptor.h"


class TimeShiftedServiceDescriptor : public Descriptor
{

private:
    const int referenceServiceId;


public:
    TimeShiftedServiceDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getReferenceServiceId();

};

#endif // TIMESHIFTEDSERVICEDESCRIPTOR_H
