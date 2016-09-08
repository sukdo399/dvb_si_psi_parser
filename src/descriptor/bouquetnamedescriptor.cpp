/*
 *Original Author:	shko
 */

#include <bouquetnamedescriptor.h>

BouquetNameDescriptor::BouquetNameDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent),
      bouquetName(std::string((char*) &buffer[offset + 2], descriptorLength))
{
    ;
}

std::string BouquetNameDescriptor::getBouquetName()
{
    return bouquetName;
}
