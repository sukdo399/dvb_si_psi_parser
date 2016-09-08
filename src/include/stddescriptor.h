/*
 *Original Author:	shko
 */

#ifndef STDDESCRIPTOR_H
#define STDDESCRIPTOR_H

#include "descriptor.h"

class STDDescriptor : public Descriptor
{

private:
    const bool leakValidFlag;

public:
    STDDescriptor(const char* buffer, const int offset, const TableSection* parent);

    bool getLeakValidFlag();

};


#endif // STDDESCRIPTOR_H
