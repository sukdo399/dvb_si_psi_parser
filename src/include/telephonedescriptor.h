/*
 *Original Author:	shko
 */

#ifndef TELEPHONEDESCRIPTOR_H
#define TELEPHONEDESCRIPTOR_H

#include "descriptor.h"

class TelephoneDescriptor : public Descriptor
{

private:
    const bool foreign_availability;
    const int connection_type;
    const int country_prefix_length;
    const int international_area_code_length;
    const int operator_code_length;
    const int national_area_code_length;
    const int core_number_length;
    const std::string country_prefix;
    const std::string international_area_code;
    const std::string operator_code;
    const std::string national_area_code;
    const std::string core_number;

public:
    TelephoneDescriptor(const char* buffer, int const offset, const TableSection* parent);

    bool getForeignAvailability();
    int getConnectionType();
    std::string getCountryPrefix();
    std::string getInternationalAreaCode();
    std::string getOperatorCode();
    std::string getNationalAreaCode();
    std::string getCoreNumber();

    int getCountryPrefixLength();
    int getInternationalAreaCodeLength();
    int getOperatorCodeLength();
    int getNationalAreaCodeLength();
    int getCoreNumberLength();

};
#endif // TELEPHONEDESCRIPTOR_H
