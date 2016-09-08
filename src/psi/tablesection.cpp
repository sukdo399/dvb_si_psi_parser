/*
 *Original Author:	shko
 */

#include "tablesection.h"

void TableSection::tableSectionInner(const char* raw_data)
{
    InitInternalData();

    //raw_data = std::string(raw_data);

    // short section
    tableId = Utils::getInt(raw_data, 0, 1, MASK_8BITS);
    sectionSyntaxIndicator = Utils::getInt(raw_data, 1, 1, 0x80) >> 7;
    privateIndicator = Utils::getInt(raw_data, 1, 1, 0x40) >> 6;
    sectionLength = Utils::getInt(raw_data, 1, 2, MASK_12BITS);

    rawData = (char*)malloc(sizeof(char) * (sectionLength+3));
    memcpy(&rawData[0], raw_data, sectionLength+3);

    // long section
    if (sectionSyntaxIndicator == 1)
    {
        tableIdExtension = Utils::getInt(raw_data, 3, 2, MASK_16BITS);
        version = Utils::getInt(raw_data, 5, 1, 0x3E) >> 1;
        currentNext = Utils::getInt(raw_data, 5, 1, 0x01);
        sectionNumber = Utils::getInt(raw_data, 6, 1, MASK_8BITS);
        sectionLastNumber = Utils::getInt(raw_data, 7, 1, MASK_8BITS);

        const int startCRC = sectionLength - 1; // +3 - 4, first 3 bytes not included, skip back 4 bytes till begin CRC
        crc = ((static_cast<long long>(Utils::getUnsignedByte(raw_data[startCRC]))) << 24) | ((static_cast<long long>(Utils::getUnsignedByte(raw_data[startCRC + 1]))) << 16) | ((static_cast<long long>(Utils::getUnsignedByte(raw_data[startCRC + 2]))) << 8) | (Utils::getUnsignedByte(raw_data[startCRC + 3]));

        const long long res = Crc32::getCrc32(raw_data,sectionLength + 3);
        if (res != 0)
        {
            crc_error = true;
            // TODO: throw error!
        }

    }

}

TableSection::TableSection(const char* raw_data) : siSpec(0)
{
    tableSectionInner(raw_data);
}

TableSection::TableSection(const char* raw_data, const int siSpec) : siSpec(siSpec)
{
    tableSectionInner(raw_data);
}


TableSection::~TableSection(void)
{
    if(rawData != nullptr)
    {
        free(rawData);
        rawData = nullptr;
    }
}

const char *TableSection::getRaw_data()
{
    return rawData;
}

int TableSection::getTableId()
{
    return tableId;
}

int TableSection::getSectionSyntaxIndicator()
{
    return sectionSyntaxIndicator;
}

int TableSection::getPrivateIndicator()
{
    return privateIndicator;
}

int TableSection::getSectionLength()
{
    return sectionLength;
}

int TableSection::getTableIdExtension()
{
    return tableIdExtension;
}

int TableSection::getVersionNumber()
{
    return version;
}

int TableSection::getCurrentNextIndicator()
{
    return currentNext;
}

int TableSection::getSectionNumber()
{
    return sectionNumber;
}

int TableSection::getLastSectionNumber()
{
    return sectionLastNumber;
}

long long TableSection::getCrc()
{
    return crc;
}

bool TableSection::getCrcError()
{
    return crc_error;
}

int TableSection::getSiSpec()
{
    return siSpec;
}

std::string TableSection::getTableType(const int tableId)
{

    switch (tableId)
    {
    case 0x00:
        return "program_association_section";
    case 0x01:
        return "conditional_access_section";
    case 0x02:
        return "program_map_section";
    case 0x03:
        return "transport_stream_description_section";
    case 0x04: // MPEG2 13818-1
        return "ISO_IEC_14496_scene_description_section";
    case 0x05: // MPEG2 13818-1
        return "ISO_IEC_14496_object_descriptor_section";

    // DVBSnoop dvb_str.c
    case 0x06: // H.222.0 AMD1
        return "Metadata Table";
    case 0x07: //  H.222.0 AMD1
        return "IPMP_Control_Information_section (ISO 13818-11)";

    case 0x38:
        return "ISO/IEC 13818-6 reserved";
    case 0x39:
        return "ISO/IEC 13818-6 reserved";
    case 0x3A:
        return "DSM-CC - multiprotocol encapsulated data";
    case 0x3B:
        return "DSM-CC - U-N messages (DSI or DII)";
    case 0x3C:
        return "DSM-CC - Download Data Messages (DDB)";
    case 0x3D:
        return "DSM-CC - stream descriptorlist";
    case 0x3E:
        return "DSM-CC sections with private data // DVB datagram (ISO/IEC 13818-6)";
    case 0x3F:
        return "ISO/IEC 13818-6 reserved";

    case 0x40:
        return "network_information_section - actual_network";
    case 0x41:
        return "network_information_section - other_network";
    case 0x42:
        return "service_description_section - actual_transport_stream";

    case 0x46:
        return "service_description_section - other_transport_stream";

    case 0x4A:
        return "bouquet_association_section";
    case 0x4B:
        return "SSU Update Notification Table (UNT)";
    case 0x4C: // EN 301 192
        return "IP/MAC Notification Table (INT)";

    case 0x4E:
        return "event_information_section - actual_transport_stream, present/following";
    case 0x4F:
        return "event_information_section - other_transport_stream, present/following";

    case 0x70:
        return "time_date_section (TDT)";
    case 0x71:
        return "running_status_section (RST)";
    case 0x72:
        return "stuffing_section (ST)";
    case 0x73:
        return "time_offset_section (TOT)";
    case 0x74: // (TS 102 812 [17])
        return "MHP-application information section (AIT)";
    case 0x75: //(TS 102 323 [15])
        return "TVA-container section (CT)";
    case 0x76: //(TS 102 323 [15])
        return "TVA-related content section (RCT)";
    case 0x77: //(TS 102 323 [15])
        return "TVA-content identifier section (CIT)";
    case 0x78: //(EN 301 192 [4])
        return "MPE-FEC section (MFT)";
    case 0x79: //(TS 102 323 [15])
        return "TVA-resolution notification section (RNT)";

    case 0x7E:
        return "discontinuity_information_section";
    case 0x7F:
        return "selection_information_section";

    case 0x80:
        return "CA_message_section, ECM 1";
    case 0x81:
        return "CA_message_section, ECM 2";

    case 0xFF:
        return "not used (illegal)";

    default:
        // Based on EN300468
        if ((0x08 <= tableId) && (tableId <= 0x3F))
        {
            return "ITU-T Rec. H.222.0|ISO/IEC13818 reserved";
        }
        if ((0x43 <= tableId) && (tableId <= 0x45))
        {
            return "reserved for future use";
        }

        if ((0x47 <= tableId) && (tableId <= 0x49))
        {
            return "reserved for future use";
        }

        if ((0x4B <= tableId) && (tableId <= 0x4D))
        {
            return "reserved for future use";
        }

        if ((0x50 <= tableId) && (tableId <= 0x5F))
        {
            return "event_information_section - actual_transport_stream, schedule";
        }

        if ((0x60 <= tableId) && (tableId <= 0x6F))
        {
            return "event_information_section - other_transport_stream, schedule";
        }

        if ((0x7A <= tableId) && (tableId <= 0x7D))
        {
            return "reserved for future use";
        }

        if ((0x82 <= tableId) && (tableId <= 0x8F))
        {
            return "CA_message_section, CA System private";
        }
        if ((0x90 <= tableId) && (tableId <= 0xFE))
        {
            return "user defined";
        }

        return "illegal value";
    }

}

void TableSection::InitInternalData()
{
    rawData = nullptr;
    tableId = 0;
    sectionSyntaxIndicator = 0;
    privateIndicator = 0;
    sectionLength = 0;
    tableIdExtension = 0;
    version = 0;
    currentNext = 0;
    sectionNumber = 0;
    sectionLastNumber = 0;
    crc = 0;
    crc_error = false;
}
