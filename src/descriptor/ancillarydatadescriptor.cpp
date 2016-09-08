/*
 *Original Author:	shko
 */

#include <ancillarydatadescriptor.h>

AncillaryDataDescriptor::AncillaryDataDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      ancillaryDataIdentifier(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS))
{

}


int AncillaryDataDescriptor::getAncillaryDataIdentifier()
{
    return ancillaryDataIdentifier;
}
