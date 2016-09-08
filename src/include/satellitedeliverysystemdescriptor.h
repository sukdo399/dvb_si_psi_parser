/*
 *Original Author:	shko
 */

#ifndef SATELLITEDELIVERYSYSTEMDESCRIPTOR_H
#define SATELLITEDELIVERYSYSTEMDESCRIPTOR_H

#include "descriptor.h"


class SatelliteDeliverySystemDescriptor : public Descriptor
{

private:
    const int frequency;
    const int orbitalPosition;
    const bool westEastFlag;
    const int polarization;
    const int rollOff;
    const int modulationSystem;
    const int modulationType;
    const int symbol_rate;
    const int FEC_inner;


public:
    SatelliteDeliverySystemDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getFrequency();
    int getOrbitalPosition();
    bool getWestEastFlag();
    int getPolarization();
    int getRollOff();
    int getModulationSystem();
    int getModulationType();
    int getSymbol_rate();
    int getFEC_inner();

    static std::string getModulationString(const int modulation);
    static std::string getPolarizationString(const int polarization);
    static std::string getRollOffString(const int poliarization);

};

#endif // SATELLITEDELIVERYSYSTEMDESCRIPTOR_H
