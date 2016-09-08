/*
 *Original Author:	shko
 */

#ifndef AUDIOSTREAMDESCRIPTOR_H
#define AUDIOSTREAMDESCRIPTOR_H

#include "descriptor.h"

class AudioStreamDescriptor : public Descriptor
{

private:
    const bool freeFormatFlag;
    const int id;
    const int layer;
    const int variableRateAudioIndicator;
    const int reserved;


public:
    AudioStreamDescriptor(const char* buffer, const int offset, const TableSection* parent);

    bool getFreeFormatFlag();
    int getId();
    int getLayer();
    int getVariableRateAudioIndicator();
    int getReserved();

};

#endif // AUDIOSTREAMDESCRIPTOR_H
