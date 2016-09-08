/*
 *Original Author:	shko
 */

#include <linkagedescriptor.h>


LinkageDescriptor::LinkageDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent),
      transportStreamId(Utils::getInt(buffer, offset + 2, 2, MASK_16BITS)),
      originalNetworkId(Utils::getInt(buffer, offset + 4, 2, MASK_16BITS)),
      serviceId(Utils::getInt(buffer,offset + 6, 2, MASK_16BITS)),
      linkageType(Utils::getInt(buffer, offset + 8, 1, MASK_8BITS))
{
    int t = offset + 9;

    privateDataBytes.resize(descriptorLength - ((t-offset) - 2));
    memcpy(&privateDataBytes[0], buffer+t, descriptorLength - ((t-offset) - 2));
}

int LinkageDescriptor::getTransportStreamId()
{
    return transportStreamId;
}

int LinkageDescriptor::getOriginalNetworkId()
{
    return originalNetworkId;
}

int LinkageDescriptor::getServiceId()
{
    return serviceId;
}

int LinkageDescriptor::getLinkageType()
{
    return linkageType;
}

const CharVector* LinkageDescriptor::getPrivateDataByte()
{
    return &privateDataBytes;
}


std::string LinkageDescriptor::getLinkageTypeString(const int linkageType)
{
    switch (linkageType)
    {
        case 0x00 :
            return "reserved for future use";
        case 0x01 :
            return "information service";
        case 0x02 :
            return "EPG service";
        case 0x03 :
            return "CA replacement service";
        case 0x04 :
            return "TS containing complete Network/Bouquet SI";
        case 0x05 :
            return "service replacement service";
        case 0x06 :
            return "data broadcast service";
        case 0x07 :
            return "RCS Map";
        case 0x08 :
            return "mobile hand-over";
        case 0x09 :
            return "System Software Update Service";
        case 0x0A :
            return "TS containing SSU BAT or NIT";
        case 0x0B :
            return "IP/MAC Notification Service";
        case 0x0C :
            return "TS containing INT BAT or NIT";

        case 0x81 :
            return "user defined: (linkage to NorDig bootloader)";
        case 0x82 : // or NorDig Simulcast replacement service.
            return "user defined: (NorDig Simulcast replacement service/linkage to Ziggo software update)";

        case 0xA0 : // http://download.tdconline.dk/pub/kabeltv/pdf/CPE/Rules_of_Operation.pdf
            return "user defined: link to OpenTV VOD service (YOUSEE)";
        case 0xA6 : // http://download.tdconline.dk/pub/kabeltv/pdf/CPE/Rules_of_Operation.pdf
            return "user defined: link to OpenTV ITV service (YOUSEE)";
        case 0xA7 : // http://download.tdconline.dk/pub/kabeltv/pdf/CPE/Rules_of_Operation.pdf
            return "user defined: link to WEB service (YOUSEE)";

        case 0xFF :
            return "reserved for future use";

        default:
            if ((0x0D <= linkageType) && (linkageType <= 0x7F))
            {
                return "reserved for future use";
            }
            if ((0x80 <= linkageType) && (linkageType <= 0xFE))
            {
                return "user defined";
            }

            return "Illegal value";

    }
}




