/*
 *Original Author:	shko
 */

#include <telephonedescriptor.h>


TelephoneDescriptor::TelephoneDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent),
      foreign_availability((Utils::getInt(buffer, offset + 2, 1, 0x20)) ? true:false),
      connection_type(Utils::getInt(buffer, offset + 2, 1, MASK_5BITS)),
      country_prefix_length(Utils::getInt(buffer, offset + 3, 1, 0x60) >> 5),
      international_area_code_length(Utils::getInt(buffer, offset + 3, 1, 0x1C) >> 2),
      operator_code_length(Utils::getInt(buffer, offset + 3, 1, 0x3)),
      national_area_code_length(Utils::getInt(buffer, offset + 4, 1, 0x70) >> 4),
      core_number_length(Utils::getInt(buffer, offset + 4, 1, MASK_4BITS)),
      country_prefix(std::string((char*)&buffer[offset + 5], country_prefix_length)),
      international_area_code(std::string((char*)&buffer[offset + 5 + country_prefix_length], international_area_code_length)),
      operator_code(std::string((char*)&buffer[offset + 5 + country_prefix_length + international_area_code_length], operator_code_length)),
      national_area_code(std::string((char*)&buffer[offset + 5 + country_prefix_length + international_area_code_length + operator_code_length], national_area_code_length)),
      core_number(std::string((char*)&buffer[offset + 5 + country_prefix_length + international_area_code_length + operator_code_length + national_area_code_length], core_number_length))
{
    ;
}


bool TelephoneDescriptor::getForeignAvailability()
{
    return foreign_availability;
}

int TelephoneDescriptor::getConnectionType()
{
    return connection_type;
}

std::string TelephoneDescriptor::getCountryPrefix()
{
    return country_prefix;
}

std::string TelephoneDescriptor::getInternationalAreaCode()
{
    return international_area_code;
}

std::string TelephoneDescriptor::getOperatorCode()
{
    return operator_code;
}

std::string TelephoneDescriptor::getNationalAreaCode()
{
    return national_area_code;
}

std::string TelephoneDescriptor::getCoreNumber()
{
    return core_number;
}


int TelephoneDescriptor::getCountryPrefixLength()
{
    return country_prefix_length;
}

int TelephoneDescriptor::getInternationalAreaCodeLength()
{
    return international_area_code_length;
}

int TelephoneDescriptor::getOperatorCodeLength()
{
    return operator_code_length;
}

int TelephoneDescriptor::getNationalAreaCodeLength()
{
    return national_area_code_length;
}

int TelephoneDescriptor::getCoreNumberLength()
{
    return core_number_length;
}

