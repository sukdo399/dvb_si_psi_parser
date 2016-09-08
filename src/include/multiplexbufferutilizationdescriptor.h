/*
 *Original Author:	shko
 */

#ifndef MULTIPLEXBUFFERUTILIZATIONDESCRIPTOR_H
#define MULTIPLEXBUFFERUTILIZATIONDESCRIPTOR_H

#include "descriptor.h"

class MultiplexBufferUtilizationDescriptor : public Descriptor
{

private:
    const bool boundValidFlag;
    const int ltwOffsetLowerBound;
    const int ltwOffsetUpperBound;

public:
    MultiplexBufferUtilizationDescriptor(const char* buffer, const int offset, const TableSection* parent);

    bool getBoundValidFlag();
    int getLtwOffsetLowerBound();
    int getLtwOffsetUpperBound();
};


#endif // MULTIPLEXBUFFERUTILIZATIONDESCRIPTOR_H
