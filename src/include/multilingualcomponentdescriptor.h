/*
 *Original Author:	shko
 */

#ifndef MULTILINGUALCOMPONENTDESCRIPTOR_H
#define MULTILINGUALCOMPONENTDESCRIPTOR_H

#include <descriptor.h>

class MultilingualComponentDescriptor : public Descriptor
{
public:
    class TextDescription
    {

    private:
        const std::string iso639LanguageCode;
        const std::string text;

    public:
        TextDescription(const std::string &lCode, const std::string textDescription);
        virtual ~TextDescription(void);

        std::string getIso639LanguageCode();
        std::string getTextDescription();

    };

private:
    const int component_tag;
    std::vector<TextDescription*> textDescriptionVector;


public:
    MultilingualComponentDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~MultilingualComponentDescriptor(void);

    int getComponentTag();

    std::vector<TextDescription*>* getTextDescriptionVector();
};

typedef std::vector<MultilingualComponentDescriptor::TextDescription*> TextDescriptionVector;
typedef TextDescriptionVector::iterator TextDescriptionIterator;
typedef TextDescriptionVector::const_iterator TextDescriptionConstIterator;


#endif // MULTILINGUALCOMPONENTDESCRIPTOR_H
