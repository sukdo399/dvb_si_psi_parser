/*
 *Original Author:	shko
 */

#ifndef PDCDESCRIPTOR_H
#define PDCDESCRIPTOR_H

#include "descriptor.h"


class PDCDescriptor : public Descriptor
{

private:
    const int day;
    const int month;
    const int hour;
    const int minute;
    const int programmeIdentificationLabel;


public:
    PDCDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getDay();
    int getMonth();
    int getHour();
    int getMinute();
    int getProgrammeIdentificationLabel();

};


#endif // PDCDESCRIPTOR_H
