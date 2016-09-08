/*
 *Original Author:	shko
 */

#include <componentdescriptor.h>

ComponentDescriptor::ComponentDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset, parent),
      reserved(Utils::getInt(buffer, offset + 2, 1, MASK_4BITS_UP)),
      streamContent(Utils::getInt(buffer, offset + 2, 1, MASK_4BITS)),
      componentType(Utils::getInt(buffer, offset + 3, 1, MASK_8BITS)),
      componentTag(Utils::getInt(buffer, offset + 4, 1, MASK_8BITS)),
      iso639LanguageCode(std::string((char*)&buffer[offset + 5], 3)),
      text(std::string((char*)&buffer[offset + 8], descriptorLength - 6))
{
    ;
}

int ComponentDescriptor::getReserved()
{
    return reserved;
}

int ComponentDescriptor::getStreamContent()
{
    return streamContent;
}

int ComponentDescriptor::getComponentType()
{
    return componentType;
}

int ComponentDescriptor::getComponentTag()
{
    return componentTag;
}

std::string ComponentDescriptor::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

std::string ComponentDescriptor::getText()
{
    return text;
}
