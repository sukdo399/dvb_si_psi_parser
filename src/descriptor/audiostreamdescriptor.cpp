/*
 *Original Author:	shko
 */

#include <audiostreamdescriptor.h>

AudioStreamDescriptor::AudioStreamDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset,parent),
      freeFormatFlag((Utils::getInt(buffer, offset + 2, 1, 0x80) >> 7) ? true : false),
      id(Utils::getInt(buffer, offset + 2, 1, 0x40) >> 6),
      layer(Utils::getInt(buffer, offset + 2, 1, 0x30) >> 4),
      variableRateAudioIndicator(Utils::getInt(buffer, offset + 2, 1, 0x08) >> 3),
      reserved(Utils::getInt(buffer, offset + 2, 1, 0x07))
{
    ;
}


bool AudioStreamDescriptor::getFreeFormatFlag()
{
    return freeFormatFlag;
}

int AudioStreamDescriptor::getId()
{
    return id;
}

int AudioStreamDescriptor::getLayer()
{
    return layer;
}

int AudioStreamDescriptor::getVariableRateAudioIndicator()
{
    return variableRateAudioIndicator;
}

int AudioStreamDescriptor::getReserved()
{
    return reserved;
}
