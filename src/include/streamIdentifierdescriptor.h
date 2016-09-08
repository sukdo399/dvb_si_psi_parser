/*
 *Original Author:	shko
 */

#ifndef STREAMIDENTIFIERDESCRIPTOR_H
#define STREAMIDENTIFIERDESCRIPTOR_H

#include "descriptor.h"

class StreamIdentifierDescriptor : public Descriptor
{


private:
    const int componentTag;

public:
    StreamIdentifierDescriptor(const char*, const int offset, const TableSection* parent);

    int getComponentTag();

};
#endif // STREAMIDENTIFIERDESCRIPTOR_H
