/*
 *Original Author:	shko
 */

#include <subtitlingdescriptor.h>



SubtitlingDescriptor::Subtitle::Subtitle(const std::string &lCode, const int sType, const int sCompositionPageDd, const int aPageId)
    : iso639LanguageCode(lCode)
    , subtitlingType(sType)
    , compositionPageId(sCompositionPageDd)
    , ancillaryPageId(aPageId)
{
    ;
}

SubtitlingDescriptor::Subtitle::~Subtitle(void)
{
    ;
}

std::string SubtitlingDescriptor::Subtitle::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

int SubtitlingDescriptor::Subtitle::getSubtitlingType()
{
    return subtitlingType;
}

int SubtitlingDescriptor::Subtitle::getCompositionPageId()
{
    return compositionPageId;
}

int SubtitlingDescriptor::Subtitle::getAncillaryPageId()
{
    return ancillaryPageId;
}


SubtitlingDescriptor::SubtitlingDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent)
{
    //std::vector<Subtitle*> r = std::vector<Subtitle*>();
    int t = 0;


    while (t < descriptorLength)
    {
        std::string languageCode;
        languageCode.assign((char *)&buffer[offset + 2 + t], 3);
        const int subtitling_type = Utils::getInt(buffer, offset + 5 + t, 1, MASK_8BITS);
        const int composition_page_id = Utils::getInt(buffer, offset + 6 + t, 2, MASK_16BITS);
        const int ancillary_page_id = Utils::getInt(buffer, offset + 8 + t, 2, MASK_16BITS);

        Subtitle * s = new Subtitle(languageCode, subtitling_type,composition_page_id,ancillary_page_id); // TODO: const
        subtitleVector.push_back(s);

        t += 8;
    }

    //this->setSubtitleDescriptorVector(r);

}

SubtitlingDescriptor::~SubtitlingDescriptor(void)
{
    for(SubtitleIterator i = subtitleVector.begin(); i != subtitleVector.end(); ++i)
        delete *i;
}

std::vector<SubtitlingDescriptor::Subtitle *>* SubtitlingDescriptor::getSubtitleVector()
{
    return &subtitleVector;
}

