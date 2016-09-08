/*
 *Original Author:	shko
 */

#ifndef PRIVATEDATASPECIFIERDESCRIPTOR_H
#define PRIVATEDATASPECIFIERDESCRIPTOR_H

#include "descriptor.h"

class PrivateDataSpecifierDescriptor : public Descriptor
{

private:
    int privateDataSpecifier;

public:
    PrivateDataSpecifierDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getPrivateDataSpecifier();

};

#endif // PRIVATEDATASPECIFIERDESCRIPTOR_H
