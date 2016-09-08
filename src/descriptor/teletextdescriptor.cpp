/*
 *Original Author:	shko
 */

#include <teletextdescriptor.h>

TeletextDescriptor::Teletext::Teletext(const std::string &lCode, const int tType, const int tMagazine, const int tPage)
    : iso639LanguageCode(lCode),
      teletextType(tType),
      teletextMagazineNumber(tMagazine),
      teletextPageNumber(tPage)
{
    ;
}

TeletextDescriptor::Teletext::~Teletext()
{
    ;
}

std::string TeletextDescriptor::Teletext::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

int TeletextDescriptor::Teletext::getTeletextType()
{
    return teletextType;
}

int TeletextDescriptor::Teletext::getTeletextMagazineNumber()
{
    return teletextMagazineNumber;
}

int TeletextDescriptor::Teletext::getTeletextPageNumber()
{
    return teletextPageNumber;
}


TeletextDescriptor::TeletextDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
{
    int t = 0;
    while ((t + 4) < descriptorLength)
    {
        const std::string languageCode = std::string((char*)&buffer[offset + 2 + t], 3);
        const int teletext_type = Utils::getInt(buffer, offset + t + 5, 1, 0xF8) >> 3;
        const int teletext_magazine_number = Utils::getInt(buffer, offset + t + 5, 1, 0x07);
        const int teletext__page_number = Utils::getInt(buffer, offset + t + 6, 1, 0xFF);
        Teletext* s = new Teletext(languageCode, teletext_type, teletext_magazine_number, teletext__page_number);
        teletextVector.push_back(s);
        t += 5;
    }
}

TeletextDescriptor::~TeletextDescriptor()
{
    for(TeletextIterator i = teletextVector.begin(); i != teletextVector.end(); ++i)
        delete *i;
}


std::vector<TeletextDescriptor::Teletext*>* TeletextDescriptor::getTeletextVector()
{
    return &teletextVector;
}

std::string TeletextDescriptor::getTeletextTypeString(int const type)
{
    switch (type)
    {
        case 0x00:
            return "reserved for future use";
        case 0x01:
            return "initial Teletext page";
        case 0x02:
            return "Teletext subtitle page";
        case 0x03:
            return "additional information page";
        case 0x04:
            return "programme schedule page";
        case 0x05:
            return "Teletext subtitle page for hearing impaired people";
        default:
            return "reserved for future use";
    }
}
