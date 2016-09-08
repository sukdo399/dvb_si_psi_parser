/*
 *Original Author:	shko
 */

#ifndef COUNTRYAVAILABILITYDESCRIPTOR_H
#define COUNTRYAVAILABILITYDESCRIPTOR_H

#include "descriptor.h"

class CountryAvailabilityDescriptor : public Descriptor
{
public:
    class Country
    {

    private:
        const std::string countryCode;

    public:
        Country(const std::string countryCode);
        virtual ~Country(void);

        virtual std::string getCountryCode();

    };


private:
    const bool country_availability_flag;

    std::vector<Country*> countryVector;


public:
    CountryAvailabilityDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~CountryAvailabilityDescriptor(void);

    bool getCountryAvailabilityFlag();
    std::vector<Country*>* getCountryVector();

    static std::string getCountryAvailabilityFlagString(const int flag);
};

typedef std::vector<CountryAvailabilityDescriptor::Country *> CountryVector;
typedef CountryVector::iterator CountryIterator;
typedef CountryVector::const_iterator CountryConstIterator;


#endif // COUNTRYAVAILABILITYDESCRIPTOR_H
