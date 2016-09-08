/*
 *Original Author:	shko
 */

#include <databroadcastdescriptor.h>


DataBroadcastDescriptor::DataBroadcastDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      dataBroadcastId(Utils::getInt(buffer, offset + 2, 2, MASK_16BITS)),
      componentTag(Utils::getInt(buffer, offset + 4, 1, MASK_8BITS)),
      selectorLength(Utils::getInt(buffer, offset + 5, 1, MASK_8BITS)),
      //selectorByte(std::string((char*)&buffer[offset + 6], selectorLength)),
      iso639LanguageCode(std::string((char*)&buffer[offset + 6 + selectorLength], 3)),
      textLength(Utils::getInt(buffer, offset + 9 + selectorLength, 1, MASK_8BITS)),
      text(std::string((char*)&buffer[offset + 10 + selectorLength], textLength))

{
    int t = offset + 6;

    selectorByte.resize(selectorLength);
    memcpy(&selectorByte[0], buffer + t, selectorLength);

    MAC_address_range = 0;
    MAC_IP_mapping_flag = 0;
    alignment_indicator = 0;
    max_sections_per_datagram = 0;

    if (dataBroadcastId == 0x0005) //en 301192 7.2.1
    {
        MAC_address_range = Utils::getInt(buffer, t, 1, 0xE0) >> 5;
        MAC_IP_mapping_flag = Utils::getInt(buffer, t, 1, 0x10) >> 4;
        alignment_indicator = Utils::getInt(buffer, t, 1, 0x08) >> 3;
        max_sections_per_datagram = Utils::getInt(buffer, t + 1, 1, MASK_8BITS);
    }
    else if(dataBroadcastId == 0x0006)
    {
        /** <DVB data carousel */
        // TODO:
        ;
    }
    else if(dataBroadcastId == 0x0007)
    {
        /** <DVB object carousel */
        // TODO:
        ;
    }


}

int DataBroadcastDescriptor::getDataBroadcastId()
{
    return dataBroadcastId;
}

int DataBroadcastDescriptor::getComponentTag()
{
    return componentTag;
}

#if 0
int DataBroadcastDescriptor::getSelectorLength()
{
    return selectorLength;
}
#endif

const CharVector* DataBroadcastDescriptor::getSelectorByte()
{
    return &selectorByte;
}

std::string DataBroadcastDescriptor::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

#if 0
int DataBroadcastDescriptor::getTextLength()
{
    return textLength;
}
#endif

std::string DataBroadcastDescriptor::getText()
{
    return text;
}

std::string DataBroadcastDescriptor::getvalidMACaddressBytesString(const int adresReange)
{
    switch (adresReange)
    {
        case 0x00 :
            return "reserved";
        case 0x01 :
            return "valid MAC_address bytes: 6";
        case 0x02 :
            return "valid MAC_address bytes: 6,5";
        case 0x03 :
            return "valid MAC_address bytes: 6,5,4";
        case 0x04 :
            return "valid MAC_address bytes: 6,5,4,3";
        case 0x05 :
            return "valid MAC_address bytes: 6,5,4,3,2";
        case 0x06 :
            return "valid MAC_address bytes: 6,5,4,3,2,1";
        default:
            return "reserved";
    }
}

