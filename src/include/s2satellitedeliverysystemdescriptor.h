/*
 *Original Author:	shko
 */

#ifndef S2SATELLITEDELIVERYSYSTEMDESCRIPTOR_H
#define S2SATELLITEDELIVERYSYSTEMDESCRIPTOR_H

#include "descriptor.h"

class S2SatelliteDeliverySystemDescriptor : public Descriptor
{

private:
    const int scrambling_sequence_selector;
    const bool multiple_input_stream_flag;
    const int backwards_compatibility_indicator;
    int scrambling_sequence_index;
    int input_stream_identifier;

public:
    S2SatelliteDeliverySystemDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getScramblingSequenceSelector();
    bool getmultipleInputStreamFlag();
    int getBackwardsCompatibilityIndicator();
    int getScramblingSequenceIndex();
    int getInputStreamidentifier();

};


#endif // S2SATELLITEDELIVERYSYSTEMDESCRIPTOR_H
