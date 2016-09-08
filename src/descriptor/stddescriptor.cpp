/*
 *Original Author:	shko
 */

#include <stddescriptor.h>


STDDescriptor::STDDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      leakValidFlag((Utils::getInt(buffer, offset + 2, 1, MASK_1BIT)) ? true : false)
{
    ;
}

bool STDDescriptor::getLeakValidFlag()
{
    return leakValidFlag;
}
