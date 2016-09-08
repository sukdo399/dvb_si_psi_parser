/*
 *Original Author:	shko
 */

#include <contentdescriptor.h>

ContentDescriptor::Content::Content(const int contentNibbleLevel1, const int contentNibbleLevel2, const int userByte)
    : contentNibbleLevel1(contentNibbleLevel1),
      contentNibbleLevel2(contentNibbleLevel2),
      userByte(userByte)
{
    ;
}

ContentDescriptor::Content::~Content(void)
{
    ;
}

int ContentDescriptor::Content::getContentNibbleLevel1()
{
    return contentNibbleLevel1;
}

int ContentDescriptor::Content::getContentNibbleLevel2()
{
    return contentNibbleLevel2;
}

int ContentDescriptor::Content::getUserByte()
{
    return userByte;
}


ContentDescriptor::ContentDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset, parent)
{

    int t = 0;
    while (t < descriptorLength)
    {
        const int cNibble1 = Utils::getInt(buffer, offset + t + 2, 1, MASK_4BITS_UP) >> 4;
        const int cNnibble2 = Utils::getInt(buffer, offset + t + 2, 1, MASK_4BITS);
        const int userByte = Utils::getInt(buffer, offset + t + 3, 1, MASK_8BITS);

        Content* s = new Content(cNibble1, cNnibble2, userByte);
        contentVector.push_back(s);
        t += 2;
    }
}

ContentDescriptor::~ContentDescriptor(void)
{
    for(ContentIterator i = contentVector.begin(); i != contentVector.end(); ++i)
        delete *i;
}

std::vector<ContentDescriptor::Content*>* ContentDescriptor::getContentVector()
{
    return &contentVector;
}


std::string ContentDescriptor::getContentNibbleLevel1String(const int nibble1)
{
    switch (nibble1)
    {
        case 0x0:
            return "undefined content";
        case 0x1:
            return "Movie/Drama:";
        case 0x2:
            return "News/Current affairs:";
        case 0x3:
            return "Show/Game show:";
        case 0x4:
            return "Sports:";
        case 0x5:
            return "Children's/Youth programmes:";
        case 0x6:
            return "Music/Ballet/Dance:";
        case 0x7:
            return "Arts/Culture (without music)::";
        case 0x8:
            return "Social/Political issues/Economics:";
        case 0x9:
            return "Education/Science/Factual topics:";
        case 0xA:
            return "Leisure hobbies:";
        case 0xB:
            return "Special characteristics:";
        case 0xF:
            return "user defined";
        default:
            return "reserved for future use:";
    }
}

std::string ContentDescriptor::getContentNibbleLevel2String(const int nibble1, const int nibble2)
{
    switch (nibble1)
    {
        case 0x0:
            return "";
        case 0x1: // Movie/Drama:
            switch (nibble2)
            {
            case 0x0:
                return "movie/drama (general)";
            case 0x1:
                return "detective/thriller";
            case 0x2:
                return "adventure/western/war";
            case 0x3:
                return "science fiction/fantasy/horror";
            case 0x4:
                return "comedy";
            case 0x5:
                return "soap/melodrama/folkloric";
            case 0x6:
                return "romance";
            case 0x7:
                return "serious/classical/religious/historical movie/drama";
            case 0x8:
                return "adult movie/drama";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0x2: // News/Current affairs:
            switch (nibble2)
            {
            case 0x0:
                return "news/current affairs (general)";
            case 0x1:
                return "news/weather report";
            case 0x2:
                return "news magazine";
            case 0x3:
                return "documentary";
            case 0x4:
                return "discussion/interview/debate";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0x3: // Show/Game show:
            switch (nibble2)
            {
            case 0x0 :
                return "show/game show (general)";
            case 0x1 :
                return "game show/quiz/contest";
            case 0x2 :
                return "variety show";
            case 0x3 :
                return "talk show";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0x4: // Sports:
            switch (nibble2)
            {
            case 0x0 :
                return "sports (general)";
            case 0x1 :
                return "special events (Olympic Games, World Cup, etc.)";
            case 0x2 :
                return "sports magazines";
            case 0x3 :
                return "football/soccer";
            case 0x4 :
                return "tennis/squash";
            case 0x5 :
                return "team sports (excluding football)";
            case 0x6 :
                return "athletics";
            case 0x7 :
                return "motor sport";
            case 0x8 :
                return "water sport";
            case 0x9 :
                return "winter sports";
            case 0xA :
                return "equestrian";
            case 0xB :
                return "martial sports";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0x5: // Children's/Youth programmes:
            switch (nibble2)
            {
            case 0x0 :
                return "children's/youth programmes (general)";
            case 0x1 :
                return "pre-school children's programmes";
            case 0x2 :
                return "entertainment programmes for 6 to14";
            case 0x3 :
                return "entertainment programmes for 10 to 16";
            case 0x4 :
                return "informational/educational/school programmes";
            case 0x5 :
                return "cartoons/puppets";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0x6: // Music/Ballet/Dance:
            switch (nibble2)
            {
            case 0x0 :
                return "music/ballet/dance (general)";
            case 0x1 :
                return "rock/pop";
            case 0x2 :
                return "serious music/classical music";
            case 0x3 :
                return "folk/traditional music";
            case 0x4 :
                return "jazz";
            case 0x5 :
                return "musical/opera";
            case 0x6 :
                return "ballet";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0x7: // Arts/Culture (without music):
            switch (nibble2)
            {
            case 0x0 :
                return "arts/culture (without music, general)";
            case 0x1 :
                return "performing arts";
            case 0x2 :
                return "fine arts";
            case 0x3 :
                return "religion";
            case 0x4 :
                return "popular culture/traditional arts";
            case 0x5 :
                return "literature";
            case 0x6 :
                return "film/cinema";
            case 0x7 :
                return "experimental film/video";
            case 0x8 :
                return "broadcasting/press";
            case 0x9 :
                return "new media";
            case 0xA :
                return "arts/culture magazines";
            case 0xB :
                return "fashion";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0x8: // Social/Political issues/Economics:
            switch (nibble2)
            {
            case 0x0 :
                return "social/political issues/economics (general)";
            case 0x1 :
                return "magazines/reports/documentary";
            case 0x2 :
                return "economics/social advisory";
            case 0x3 :
                return "remarkable people";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0x9: // Education/Science/Factual topics:
            switch (nibble2)
            {
            case 0x0 :
                return "education/science/factual topics (general)";
            case 0x1 :
                return "nature/animals/environment";
            case 0x2 :
                return "technology/natural sciences";
            case 0x3 :
                return "medicine/physiology/psychology";
            case 0x4 :
                return "foreign countries/expeditions";
            case 0x5 :
                return "social/spiritual sciences";
            case 0x6 :
                return "further education";
            case 0x7 :
                return "languages";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0xA: // Leisure hobbies:
            switch (nibble2)
            {
            case 0x0 :
                return "leisure hobbies (general)";
            case 0x1 :
                return "tourism/travel";
            case 0x2 :
                return "handicraft";
            case 0x3 :
                return "motoring";
            case 0x4 :
                return "fitness and health";
            case 0x5 :
                return "cooking";
            case 0x6 :
                return "advertisement/shopping";
            case 0x7 :
                return "gardening";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0xB: // Special characteristics:
            switch (nibble2)
            {
            case 0x0 :
                return "original language";
            case 0x1 :
                return "black and white";
            case 0x2 :
                return "unpublished";
            case 0x3 :
                return "live broadcast";
            case 0xF:
                return "user defined";
            default:
                return "reserved for future use";
            }
        case 0xF:
            return "";
        default:
            return "reserved for future use";
    }
}



