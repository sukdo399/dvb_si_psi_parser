/*
 *Original Author:	shko
 */

#include <cabledeliverysystemdescriptor.h>


CableDeliverySystemDescriptor::CableDeliverySystemDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset, parent),
      frequency(Utils::getBcdInt(Utils::getInt((char*)&buffer[0], offset + 2, 4, MASK_32BITS))),
      FEC_outer(Utils::getInt(buffer, offset + 7, 1, MASK_4BITS)),
      modulation(Utils::getInt(buffer, offset + 8, 1, MASK_8BITS)),
      symbol_rate(Utils::getBcdInt(((Utils::getInt((char*)&buffer[0], offset + 9, 4, MASK_32BITS)) & 0xFFFFFFF0) >> 4)),
      FEC_inner(Utils::getInt(buffer, offset + 12, 1, MASK_4BITS))
{
    ;
}

int CableDeliverySystemDescriptor::getFrequency()
{
    return frequency;
}

int CableDeliverySystemDescriptor::getFEC_outer()
{
    return FEC_outer;
}

int CableDeliverySystemDescriptor::getModulation()
{
    return modulation;
}

int CableDeliverySystemDescriptor::getSymbol_rate()
{
    return symbol_rate;
}

int CableDeliverySystemDescriptor::getFEC_inner()
{
    return FEC_inner;
}


std::string CableDeliverySystemDescriptor::getFECouterString(const int fecOuter)
{
    switch (fecOuter)
    {
        case 0x00:
            return "not defined";
        case 0x01:
            return "no outer FEC coding";
        case 0x02:
            return "RS(204/188)";
        default:
            return "reserved for future use";
    }
}

std::string CableDeliverySystemDescriptor::getModulationString(const int modulation)
{
    switch (modulation)
    {
        case 0x00:
            return "not defined";
        case 0x01:
            return "16-QAM";
        case 0x02:
            return "32-QAM";
        case 0x03:
            return "64-QAM";
        case 0x04:
            return "128-QAM";
        case 0x05:
            return "256-QAM";
        default:
            return "reserved for future use";
    }
}
