/*
 *Original Author:	shko
 */

#ifndef SUBTITLINGDESCRIPTOR_H
#define SUBTITLINGDESCRIPTOR_H

#include "descriptor.h"

class SubtitlingDescriptor : public Descriptor
{
public:
    class Subtitle
    {

    private:
        const std::string iso639LanguageCode;
        const int subtitlingType;
        const int compositionPageId;
        const int ancillaryPageId;


    public:
        Subtitle(const std::string &lCode, const int sType, const int sCompositionPageDd, const int aPageId);
        virtual ~Subtitle(void);

        std::string getIso639LanguageCode();
        int getSubtitlingType();
        int getCompositionPageId();
        int getAncillaryPageId();


    };


private:
    std::vector<Subtitle*> subtitleVector; // TODO: const

public:
    SubtitlingDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~SubtitlingDescriptor();

    std::vector<SubtitlingDescriptor::Subtitle *>* getSubtitleVector();
};

typedef std::vector<SubtitlingDescriptor::Subtitle *> SubtitleVector;
typedef SubtitleVector::iterator SubtitleIterator;
typedef SubtitleVector::const_iterator SubtitleConstIterator;


#endif // SUBTITLINGDESCRIPTOR_H
