/*
 *Original Author:	shko
 */

#include <parentalratingdescriptor.h>

ParentalRatingDescriptor::Rating::Rating(const std::string countryCode, const int rating)
    : countryCode(std::string(countryCode)), rating(rating)
{
    ;
}

ParentalRatingDescriptor::Rating::~Rating(void)
{
    ;
}

int ParentalRatingDescriptor::Rating::getRating()
{
    return rating;
}

std::string ParentalRatingDescriptor::Rating::getCountryCode()
{
    return countryCode;
}

ParentalRatingDescriptor::ParentalRatingDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent)
{
    int t = 0;
    while (t < descriptorLength)
    {
        const std::string countryCode = std::string((char*)&buffer[offset + t + 2], 3);
        const int rating = Utils::getInt(buffer, offset + t + 5, 1, MASK_8BITS);
        Rating* r = new Rating(countryCode,rating);
        ratingVector.push_back(r);
        t += 4;
    }
}

ParentalRatingDescriptor::~ParentalRatingDescriptor(void)
{
    for(RatingIterator i = ratingVector.begin(); i != ratingVector.end(); ++i)
        delete *i;
}

std::string ParentalRatingDescriptor::getRatingString(const int type)
{
    if(type == 0)
    {
        return "undefined";
    }
    else if((1 <= type) && (type <= 0x0F))
    {
        std::string strRet;
        (void)Utils::strPrintf(strRet, "age >= %d", type+3);
        return strRet;
    }
    else
    {
        return "defined by the broadcaster";
    }
}


std::vector<ParentalRatingDescriptor::Rating*>* ParentalRatingDescriptor::getRatingVector()
{
    return &ratingVector;
}

