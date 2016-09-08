/*
 *Original Author:	shko
 */

#include <s2satellitedeliverysystemdescriptor.h>


S2SatelliteDeliverySystemDescriptor::S2SatelliteDeliverySystemDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      scrambling_sequence_selector(Utils::getInt(buffer, offset + 2, 1, 0x80) >> 7),
      multiple_input_stream_flag((Utils::getInt(buffer, offset + 2, 1, 0x40) >> 6) ? true : false),
      backwards_compatibility_indicator(Utils::getInt(buffer, offset + 2, 1, 0x20) >> 5)
{

    int t = offset + 3;
    if (scrambling_sequence_selector == 1)
    {
        // Reserved 6 bslbf
        scrambling_sequence_index = Utils::getInt(buffer, t, 3, MASK_18BITS);
        t += 3;
    }
    else
    {
        scrambling_sequence_index = 0;
    }

    if (multiple_input_stream_flag == 1)
    {
        input_stream_identifier = Utils::getInt(buffer, t, 1, MASK_8BITS);
        t += 1;
    }
    else
    {
        input_stream_identifier = 0;
    }
}

int S2SatelliteDeliverySystemDescriptor::getScramblingSequenceSelector()
{
    return scrambling_sequence_selector;
}

bool S2SatelliteDeliverySystemDescriptor::getmultipleInputStreamFlag()
{
    return multiple_input_stream_flag;
}

int S2SatelliteDeliverySystemDescriptor::getBackwardsCompatibilityIndicator()
{
    return backwards_compatibility_indicator;
}

int S2SatelliteDeliverySystemDescriptor::getScramblingSequenceIndex()
{
    return scrambling_sequence_index;
}

int S2SatelliteDeliverySystemDescriptor::getInputStreamidentifier()
{
    return input_stream_identifier;
}
