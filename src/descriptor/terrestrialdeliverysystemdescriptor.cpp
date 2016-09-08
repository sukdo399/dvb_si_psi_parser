/*
 *Original Author:	shko
 */

#include <terrestrialdeliverysystemdescriptor.h>

TerrestrialDeliverySystemDescriptor::TerrestrialDeliverySystemDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset, parent)
    , centreFrequency(Utils::getInt(buffer, offset + 2, 4, MASK_32BITS))
    , bandwidth((Utils::getInt(buffer, offset + 6, 1, 0xE0) >> 5))
    , priority((Utils::getInt(buffer, offset + 6, 1, 0x10) >> 4))
    , timeSlicingIndicator((Utils::getInt(buffer, offset + 6, 1, 0x08) >> 3))
    , mpeFecIndicator((Utils::getInt(buffer, offset + 6, 1, 0x4) >> 2))
    , constellation((Utils::getInt(buffer, offset + 7, 1, 0xC0) >> 6))
    , hierarchyInformation((Utils::getInt(buffer, offset + 7, 1, 0x38) >> 3))
    , codeRateHPStream(Utils::getInt(buffer, offset + 7, 1, 0x07))
    , codeRateLPStream((Utils::getInt(buffer, offset + 8, 1, 0xE0) >> 5))
    , guardInterval((Utils::getInt(buffer, offset + 8, 1, 0x18) >> 3))
    , transmissionMode((Utils::getInt(buffer, offset + 8, 1, 0x06) >> 1))
    , otherFrequencyFlag(Utils::getInt(buffer, offset + 8, 1, 0x01) == 1 ? true:false)
{
    ;
}

int TerrestrialDeliverySystemDescriptor::getCentreFrequency()
{
    return centreFrequency;
}

int TerrestrialDeliverySystemDescriptor::getBandwidth()
{
    return bandwidth;
}

int TerrestrialDeliverySystemDescriptor::getPriority()
{
    return priority;
}

int TerrestrialDeliverySystemDescriptor::getTimeSlicingIndicator()
{
    return timeSlicingIndicator;
}

int TerrestrialDeliverySystemDescriptor::getMpeFecIndicator()
{
    return mpeFecIndicator;
}

int TerrestrialDeliverySystemDescriptor::getConstellation()
{
    return constellation;
}

int TerrestrialDeliverySystemDescriptor::getHierarchyInformation()
{
    return hierarchyInformation;
}

int TerrestrialDeliverySystemDescriptor::getCodeRateHPStream()
{
    return codeRateHPStream;
}

int TerrestrialDeliverySystemDescriptor::getCodeRateLPStream()
{
    return codeRateLPStream;
}

int TerrestrialDeliverySystemDescriptor::getGuardInterval()
{
    return guardInterval;
}

int TerrestrialDeliverySystemDescriptor::getTransmissionMode()
{
    return transmissionMode;
}

bool TerrestrialDeliverySystemDescriptor::getOtherFrequencyFlag()
{
    return otherFrequencyFlag;
}


std::string TerrestrialDeliverySystemDescriptor::getBandwidtString(const int bandwitdth)
{
    switch (bandwitdth)
    {
        case 0x00:
            return "8 MHz";
        case 0x01:
            return "7 MHz";
        case 0x02:
            return "6 MHz";
        case 0x03:
            return "5 MHz";
        default:
            return "reserved for future use";
    }
}
