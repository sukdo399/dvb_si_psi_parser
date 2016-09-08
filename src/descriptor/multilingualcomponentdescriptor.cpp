/*
 *Original Author:	shko
 */

#include <multilingualcomponentdescriptor.h>

MultilingualComponentDescriptor::TextDescription::TextDescription(const std::string &lCode, const std::string textDescription)
    : iso639LanguageCode(lCode),
      text(textDescription)
{
    ;
}

MultilingualComponentDescriptor::TextDescription::~TextDescription()
{
    ;
}

std::string MultilingualComponentDescriptor::TextDescription::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

std::string MultilingualComponentDescriptor::TextDescription::getTextDescription()
{
    return text;
}


MultilingualComponentDescriptor::MultilingualComponentDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset,parent),
      component_tag(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS))
{
    int t = offset + 3;
    while (t < (descriptorLength + offset + 2))
    {
        const std::string languageCode = std::string((char*)&buffer[offset + t], 3);
        int text_description_length = Utils::getInt(buffer, t + 3, 1, MASK_8BITS);
        const std::string textDescription = std::string((char*)&buffer[offset + t + 4], text_description_length);
        TextDescription* s = new TextDescription(languageCode, textDescription);
        textDescriptionVector.push_back(s);
        t += 4 + text_description_length;
    }
}

MultilingualComponentDescriptor::~MultilingualComponentDescriptor()
{
    for(TextDescriptionIterator i = textDescriptionVector.begin(); i != textDescriptionVector.end(); ++i)
        delete *i;
}

int MultilingualComponentDescriptor::getComponentTag()
{
    return component_tag;
}

std::vector<MultilingualComponentDescriptor::TextDescription*>* MultilingualComponentDescriptor::getTextDescriptionVector()
{
    return &textDescriptionVector;
}
