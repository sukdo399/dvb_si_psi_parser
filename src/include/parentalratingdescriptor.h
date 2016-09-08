/*
 *Original Author:	shko
 */

#ifndef PARENTALRATINGDESCRIPTOR_H
#define PARENTALRATINGDESCRIPTOR_H

#include "descriptor.h"

class ParentalRatingDescriptor : public Descriptor
{
public:
    class Rating
    {

    private:
        const std::string countryCode;
        const int rating;

    public:
        Rating(const std::string countryCode, const int rating);
        virtual ~Rating(void);

        std::string getCountryCode();
        int getRating();

    };


private:
    std::vector<Rating*> ratingVector;


public:
    ParentalRatingDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~ParentalRatingDescriptor(void);

    static std::string getRatingString(const int type);
    std::vector<Rating*>* getRatingVector();

};

typedef std::vector<ParentalRatingDescriptor::Rating *> RatingVector;
typedef RatingVector::iterator RatingIterator;
typedef RatingVector::const_iterator RatingConstIterator;


#endif // PARENTALRATINGDESCRIPTOR_H
