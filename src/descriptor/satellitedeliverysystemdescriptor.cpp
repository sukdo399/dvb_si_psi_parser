/*
 *Original Author:	shko
 */

#include <satellitedeliverysystemdescriptor.h>

SatelliteDeliverySystemDescriptor::SatelliteDeliverySystemDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset, parent),
      frequency(Utils::getBcdInt(Utils::getInt((char*)&buffer[0], offset + 2, 4, MASK_32BITS))),
      orbitalPosition(Utils::getBcdInt(Utils::getInt((char*)&buffer[0], offset + 6, 2, MASK_16BITS))),
      westEastFlag((Utils::getInt(buffer, offset + 8, 1, 0x80) >> 7) ? true : false),
      polarization(Utils::getInt(buffer, offset + 8, 1, 0x60) >> 5),
      rollOff(Utils::getInt(buffer, offset + 8, 1, 0x18) >> 3),
      modulationSystem(Utils::getInt(buffer, offset + 8, 1, 0x04) >> 2),
      modulationType(Utils::getInt(buffer, offset + 8, 1, MASK_2BITS)),
      symbol_rate(Utils::getBcdInt(((Utils::getInt((char*)&buffer[0], offset + 9, 4, MASK_32BITS)) & 0xFFFFFFF0) >> 4)),
      FEC_inner(Utils::getInt(buffer, offset + 12, 1, MASK_4BITS))
{
    ;
}

int SatelliteDeliverySystemDescriptor::getFrequency()
{
    return frequency;
}

int SatelliteDeliverySystemDescriptor::getOrbitalPosition()
{
    return orbitalPosition;
}

bool SatelliteDeliverySystemDescriptor::getWestEastFlag()
{
    return westEastFlag;
}

int SatelliteDeliverySystemDescriptor::getPolarization()
{
    return polarization;
}

int SatelliteDeliverySystemDescriptor::getRollOff()
{
    return rollOff;
}

int SatelliteDeliverySystemDescriptor::getModulationSystem()
{
    return modulationSystem;
}

int SatelliteDeliverySystemDescriptor::getModulationType()
{
    return modulationType;
}

int SatelliteDeliverySystemDescriptor::getSymbol_rate()
{
    return symbol_rate;
}

int SatelliteDeliverySystemDescriptor::getFEC_inner()
{
    return FEC_inner;
}

std::string SatelliteDeliverySystemDescriptor::getModulationString(const int modulation)
{
    switch (modulation)
    {
        case 0x00:
            return "Auto";
        case 0x01:
            return "QPSK";
        case 0x02:
            return "8PSK";
        case 0x03:
            return "16-QAM";
        default:
            return "illegal value";
    }
}

std::string SatelliteDeliverySystemDescriptor::getPolarizationString(const int polarization)
{
    switch (polarization)
    {
        case 0x00:
            return "linear - horizontal";
        case 0x01:
            return "linear - vertical";
        case 0x02:
            return "Circular - left";
        case 0x03:
            return "Circular - right";
        default:
            return "illegal value";
        }
}

std::string SatelliteDeliverySystemDescriptor::getRollOffString(const int poliarization)
{
    switch (poliarization)
    {
        case 0x00: // alpha
            return "\u03b1 = 0,35";
        case 0x01:
            return "\u03b1 = 0,25";
        case 0x02:
            return "\u03b1 = 0,20";
        case 0x03:
            return "reserved";
        default:
            return "illegal value";
    }
}








