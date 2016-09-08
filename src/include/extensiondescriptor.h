/*
 *Original Author:	shko
 */

#ifndef EXTENSIONDESCRIPTOR_H
#define EXTENSIONDESCRIPTOR_H

#include "descriptor.h"

class ExtensionDescriptor : public Descriptor
{
private:
    const int descriptorTagExtension;
    CharVector selectorByte;

public:
    ExtensionDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getDescriptorTagExtension();
    CharVector* getSelectorByte();

    static std::string getDescriptorTagExtensionString(const int descriptor_tag_extension);
};

#endif // EXTENSIONDESCRIPTOR_H
