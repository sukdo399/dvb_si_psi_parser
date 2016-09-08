/*
 *Original Author:	shko
 */

#include <iso639languagedescriptor.h>

ISO639LanguageDescriptor::Language::Language(const std::string &languageCode, const int audioType)
    : iso639LanguageCode(languageCode), audioType(audioType)
{
    ;
}
ISO639LanguageDescriptor::Language::~Language()
{
    ;
}

std::string ISO639LanguageDescriptor::Language::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

int ISO639LanguageDescriptor::Language::getAudioType()
{
    return audioType;
}



ISO639LanguageDescriptor::ISO639LanguageDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
{
    int t = 0;
    while (t < descriptorLength)
    {
        std::string languageCode = std::string((char*)&buffer[offset + t + 2], 3);
        int audio = Utils::getInt(buffer, offset + t + 5, 1, MASK_8BITS);
        Language* s = new Language(languageCode, audio);
        languageVector.push_back(s);
        t += 4;
    }
}
ISO639LanguageDescriptor::~ISO639LanguageDescriptor()
{
    for(LanguageIterator i = languageVector.begin(); i != languageVector.end(); ++i)
        delete *i;
}

std::vector<ISO639LanguageDescriptor::Language*>* ISO639LanguageDescriptor::getLanguageVector()
{
    return &languageVector;
}

std::string ISO639LanguageDescriptor::getAudioTypeString(const int audio)
{
    switch (audio)
    {
        case 0:
            return "Main Audio";
        case 1:
            return "Clean effects";
        case 2:
            return "Hearing impaired";
        case 3:
            return "Visual impaired commentary";
        default:
            if ((audio >= 0x04) && (audio <= 0x7F))
            {
                return "User Private";
            }
            return "Reserved";
    }
}



