/*
 *Original Author:	shko
 */

#ifndef CABLEDELIVERYSYSTEMDESCRIPTOR_H
#define CABLEDELIVERYSYSTEMDESCRIPTOR_H

#include "descriptor.h"

class CableDeliverySystemDescriptor : public Descriptor
{

private:
    const int frequency;
    const int FEC_outer;
    const int modulation;
    const long int symbol_rate;
    const int FEC_inner;


public:
    CableDeliverySystemDescriptor(const char* buffer, const int offset, const TableSection* parent);


    int getFrequency();
    int getFEC_outer();
    int getModulation();
    int getSymbol_rate();
    int getFEC_inner();

    static std::string getFECouterString(const int fecOuter);
    static std::string getModulationString(const int modulation);

};

#endif // CABLEDELIVERYSYSTEMDESCRIPTOR_H
