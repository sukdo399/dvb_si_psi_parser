/*
 *Original Author:	shko
 */

#ifndef ENHANCEDAC3DESCRIPTOR_H
#define ENHANCEDAC3DESCRIPTOR_H

#include "descriptor.h"

class EnhancedAC3Descriptor : public Descriptor
{


private:
    const bool component_type_flag;
    const bool bsid_flag;
    const bool mainid_flag;
    const bool asvc_flag;
    const bool mixinfoexists;
    const bool substream1_flag;
    const bool substream2_flag;
    const bool substream3_flag;

    int component_type;
    int bsid;
    int mainid;
    int asvc;
    int substream1;
    int substream2;
    int substream3;

    CharVector additional_info;


public:
    EnhancedAC3Descriptor(const char* buffer, const int offset, const TableSection* parent);

    bool getComponentTypeFlag();
    bool getBsidFlag();
    bool getMainidFlag();
    bool getAsvcFlag();
    bool getMixInfoExists();
    bool getSubStream1Flag();
    bool getSubStream2Flag();
    bool getSubStream3Flag();

    int getComponentType();
    int getBsid();
    int getMainid();
    int getAsvc();
    int getSubStream1();
    int getSubStream2();
    int getSubStream3();
    const CharVector* getAdditionalInfo();
};

#endif // ENHANCEDAC3DESCRIPTOR_H
