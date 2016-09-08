/*
 *Original Author:	shko
 */

#ifndef DEFAULTAUTHORITYDESCRIPTOR_H
#define DEFAULTAUTHORITYDESCRIPTOR_H

#include "descriptor.h"


class DefaultAuthorityDescriptor : public Descriptor
{

private:
    CharVector default_authority_byte;

public:
    DefaultAuthorityDescriptor(const char* buffer, const int offset, const TableSection* parent);

    CharVector* getDefaultAuthorityByte();

};


#endif // DEFAULTAUTHORITYDESCRIPTOR_H
