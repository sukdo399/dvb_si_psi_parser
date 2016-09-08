/*
 *Original Author:	shko
 */

#ifndef ISO639LANGUAGEDESCRIPTOR_H
#define ISO639LANGUAGEDESCRIPTOR_H

#include "descriptor.h"

class ISO639LanguageDescriptor : public Descriptor
{
public:
    class Language
    {

    private:
        const std::string iso639LanguageCode;
        const int audioType;


    public:
        Language(const std::string &languageCode, const int audioType);
        virtual ~Language(void);

        std::string getIso639LanguageCode();
        int getAudioType();
    };


private:
    std::vector<Language*> languageVector;


public:
    ISO639LanguageDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~ISO639LanguageDescriptor(void);

    std::vector<Language*>* getLanguageVector();

    static std::string getAudioTypeString(const int audio);
};

typedef std::vector<ISO639LanguageDescriptor::Language *> LanguageVector;
typedef LanguageVector::iterator LanguageIterator;
typedef LanguageVector::const_iterator LanguageConstIterator;


#endif // ISO639LANGUAGEDESCRIPTOR_H
