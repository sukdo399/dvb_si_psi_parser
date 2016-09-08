/*
 *Original Author:	shko
 */

#ifndef COPYRIGHTDESCRIPTOR_H
#define COPYRIGHTDESCRIPTOR_H

#include "descriptor.h"

class CopyrightDescriptor : public Descriptor
{


private:
    const int copyrightIdentifier;
    CharVector additionalCopyrightInfo;

public:
    CopyrightDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getCopyrightIdentifier();
    const CharVector* getAdditionalCopyrightInfo();


};

#endif // COPYRIGHTDESCRIPTOR_H
