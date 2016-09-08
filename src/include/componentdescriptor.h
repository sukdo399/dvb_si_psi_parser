/*
 *Original Author:	shko
 */

#ifndef COMPONENTDESCRIPTOR_H
#define COMPONENTDESCRIPTOR_H

#include "descriptor.h"

class ComponentDescriptor : public Descriptor
{

private:
    const int reserved; // 4bit
    const int streamContent;
    const int componentType;
    const int componentTag;
    const std::string iso639LanguageCode;
    const std::string text;


public:
    ComponentDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getReserved();
    int getStreamContent();
    int getComponentType();
    int getComponentTag();
    std::string getIso639LanguageCode();
    std::string getText();


};


#endif // COMPONENTDESCRIPTOR_H
