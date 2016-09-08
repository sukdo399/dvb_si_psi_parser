/*
 *Original Author:	shko
 */

#ifndef BOUQUETNAMEDESCRIPTOR_H
#define BOUQUETNAMEDESCRIPTOR_H

#include "descriptor.h"

class BouquetNameDescriptor : public Descriptor
{

private:
    const std::string bouquetName;

public:
    BouquetNameDescriptor(const char* buffer, const int offset, const TableSection* parent);

    std::string getBouquetName();

};


#endif // BOUQUETNAMEDESCRIPTOR_H
