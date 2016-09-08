/*
 *Original Author:	shko
 */

#ifndef DATABROADCASTDESCRIPTOR_H
#define DATABROADCASTDESCRIPTOR_H

#include "descriptor.h"

class DataBroadcastDescriptor : public Descriptor
{


private:
    const int dataBroadcastId;
    const int componentTag;
    const int selectorLength;
    CharVector selectorByte;
    const std::string iso639LanguageCode;

    int MAC_address_range;
    int MAC_IP_mapping_flag;
    int alignment_indicator;
    int max_sections_per_datagram;

    const int textLength;
    const std::string text;

public:
    DataBroadcastDescriptor(const char *buffer, const int offset, const TableSection* parent);

    int getDataBroadcastId();
    int getComponentTag();
    //int getSelectorLength();
    const CharVector* getSelectorByte();
    std::string getIso639LanguageCode();
    //int getTextLength();
    std::string getText();

    static std::string getvalidMACaddressBytesString(const int adresReange);



};


#endif // DATABROADCASTDESCRIPTOR_H
