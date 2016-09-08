/*
 *Original Author:	shko
 */

#ifndef TIMESHIFTEDEVENTDESCRIPTOR_H
#define TIMESHIFTEDEVENTDESCRIPTOR_H

#include "descriptor.h"


class TimeShiftedEventDescriptor : public Descriptor
{

private:
    const int referenceServiceId;
    const int referenceEventId;


public:
    TimeShiftedEventDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getReferenceServiceId();
    int getReferenceEventId();

};

#endif // TIMESHIFTEDEVENTDESCRIPTOR_H
