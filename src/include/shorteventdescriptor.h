/*
 *Original Author:	shko
 */

#ifndef SHORTEVENTDESCRIPTOR_H
#define SHORTEVENTDESCRIPTOR_H

#include "descriptor.h"

class ShortEventDescriptor : public Descriptor
{

private:
    const std::string iso639LanguageCode;
    const int eventNameLength;
    const std::string eventName;
    const int textLength;
    const std::string text;

public:
    ShortEventDescriptor(const char* buffer, const int offset, const TableSection* parent);

    std::string getIso639LanguageCode();
    std::string getEventName();
    std::string getText();

};

#endif // SHORTEVENTDESCRIPTOR_H
