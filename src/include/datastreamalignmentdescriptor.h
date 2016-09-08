/*
 *Original Author:	shko
 */

#ifndef DATASTREAMALIGNMENTDESCRIPTOR_H
#define DATASTREAMALIGNMENTDESCRIPTOR_H

#include "descriptor.h"

class DataStreamAlignmentDescriptor : public Descriptor
{

private:
    const int alignmentType;

public:
    DataStreamAlignmentDescriptor(const char* buffer, const int offset, const TableSection* parent);


    int getAlignmentType();
    static std::string getAlignmentTypeString(const int alignment);

};


#endif // DATASTREAMALIGNMENTDESCRIPTOR_H
