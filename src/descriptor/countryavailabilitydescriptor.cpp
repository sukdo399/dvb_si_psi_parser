/*
 *Original Author:	shko
 */

#include <countryavailabilitydescriptor.h>

CountryAvailabilityDescriptor::Country::Country(const std::string countryCode)
    : countryCode(countryCode)
{
    ;
}

CountryAvailabilityDescriptor::Country::~Country(void)
{
    ;
}

std::string CountryAvailabilityDescriptor::Country::getCountryCode()
{
    return countryCode;
}


CountryAvailabilityDescriptor::CountryAvailabilityDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset, parent),
      country_availability_flag((Utils::getInt(buffer, offset + 2, 1, 0x80) >> 7) ? true : false)
{

    int t = 0;

    while (t < (descriptorLength - 1))
    {
        const std::string languageCode = std::string((char*)&buffer[offset + t + 3], 3);
        Country* s = new Country(languageCode);
        countryVector.push_back(s);
        t += 3;
    }
}

CountryAvailabilityDescriptor::~CountryAvailabilityDescriptor(void)
{
    for(CountryIterator i = countryVector.begin(); i != countryVector.end(); ++i)
        delete *i;
}

bool CountryAvailabilityDescriptor::getCountryAvailabilityFlag()
{
    return country_availability_flag;
}

std::vector<CountryAvailabilityDescriptor::Country*>* CountryAvailabilityDescriptor::getCountryVector()
{
    return &countryVector;
}

std::string CountryAvailabilityDescriptor::getCountryAvailabilityFlagString(const int flag)
{
    switch (flag)
    {
        case 0x00:
            return "reception of the service is not intended";
        case 0x01:
            return "reception of the service is intended";
        default:
            return "Illegal value";
    }
}
