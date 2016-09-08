/*
 *Original Author:	shko
 */

#ifndef ANCILLARYDATADESCRIPTOR_H
#define ANCILLARYDATADESCRIPTOR_H

#include "descriptor.h"

class AncillaryDataDescriptor : public Descriptor
{

private:
    const int ancillaryDataIdentifier;

public:
    AncillaryDataDescriptor(const char* buffer, const int offset, const TableSection* parent);



    int getAncillaryDataIdentifier();


};


#endif // ANCILLARYDATADESCRIPTOR_H
