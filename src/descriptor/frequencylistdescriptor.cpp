/*
 *Original Author:	shko
 */

#include <frequencylistdescriptor.h>


FrequencyListDescriptor::CentreFrequency::CentreFrequency(const int freqOffset)
    : centreFrequency(freqOffset)
{
    ;
}

FrequencyListDescriptor::CentreFrequency::~CentreFrequency()
{
    ;
}

int FrequencyListDescriptor::CentreFrequency::getCentreFrequency()
{
    return centreFrequency;
}

FrequencyListDescriptor::FrequencyListDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
    , codingType(Utils::getInt(buffer, offset + 2, 1, 0x03))
{


    int t = 1;
    while (t < descriptorLength)
    {
        const int freq = Utils::getInt(buffer, offset + 2 + t, 4, MASK_32BITS);
        CentreFrequency* s = new CentreFrequency(freq);
        frequencyVector.push_back(s);
        t += 4;
    }
}

FrequencyListDescriptor::~FrequencyListDescriptor()
{
    for(CentreFrequencyIterator i = frequencyVector.begin(); i != frequencyVector.end(); ++i)
        delete *i;
}

int FrequencyListDescriptor::getCodingType()
{
    return codingType;
}

std::vector<FrequencyListDescriptor::CentreFrequency*>* FrequencyListDescriptor::getCentreFrequencyVector()
{
    return &frequencyVector;
}


std::string FrequencyListDescriptor::getCodingTypeString(const int codingType)
{
    switch (codingType)
    {
        case 0x00:
            return "not defined";
        case 0x01:
            return "satellit";
        case 0x02:
            return "cable";
        case 0x03:
            return "terrestrial";

        default:
            return "illegal value codng_type";

    }

}
