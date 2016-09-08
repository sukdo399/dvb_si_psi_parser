/*
 *Original Author:	shko
 */

#include <shorteventdescriptor.h>

ShortEventDescriptor::ShortEventDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent)
    , iso639LanguageCode(std::string((char*)&buffer[offset + 2], 3))
    , eventNameLength(Utils::getInt(buffer, offset + 5, 1, MASK_8BITS))
    , eventName(std::string((char*)&buffer[offset + 5 + 1], eventNameLength))
    , textLength(Utils::getInt(buffer, offset + 5 + eventNameLength + 1, 1, MASK_8BITS))
    , text(std::string((char*)&buffer[offset + 6 + eventNameLength + 1], textLength))

{
    ;
}

std::string ShortEventDescriptor::getIso639LanguageCode()
{
    return iso639LanguageCode;
}


std::string ShortEventDescriptor::getEventName()
{
    return eventName;
}

std::string ShortEventDescriptor::getText()
{
    return text;
}


