/*
 *Original Author:	shko
 */

#ifndef LINKAGEDESCRIPTOR_H
#define LINKAGEDESCRIPTOR_H

#include "descriptor.h"

#if 0
typedef std::vector<char> PrivateDataVector;
typedef PrivateDataVector::iterator PrivateDataIterator;
typedef PrivateDataVector::const_iterator PrivateDataConstIterator;
#endif

class LinkageDescriptor : public Descriptor
{
#if 0
public:
    class OUIEntry : public TreeNode
    {

    private:
        const int oui;
        const int selectorLength;
        const char* selectorByte;


    public:
        OUIEntry(const int oui, const int selectorLength, const char* selectorByte);

    };
#endif

#if 0
public:
    class Platform
    {
    private:
        const int platformId;
        std::vector<PlatformName*> platformNameVector;

    public:
        Platform(const int pID);
        virtual void addPlatformName(const PlatformName* s);
    };

public:
    class PlatformName
    {
    private:
        const std::string iso639LanguageCode;
        const std::string platformName;

    public:
        PlatformName(const std::string &lCode, const std::string pName);
    };
#endif

private:

#if 0
    std::vector<OUIEntry*> ouiList;
    std::vector<Platform*> platformList;
#endif

    const int transportStreamId;
    const int originalNetworkId;
    const int serviceId;
    const int linkageType;

    CharVector privateDataBytes;

#if 0
    // linkage type 8
    int hand_over_type;
    int origin_type;
    int network_id;
    int initial_service_id;

    // linkage type 9
    int OUI_data_length;

    // linkage type 0x0a
    int tableType;
    char *privateDataByte;

    // linkage type 0x0b

    int platformIdDataLength;

    // linkage type 0x0c
    int bouquetID;

    // TODO handle linkage_type ==0x05
    // TODO handle linkage_type ==0x0D 300468

    // linkage type=09 is software update, oui = http://standards.ieee.org/regauth/oui/oui.txt
#endif

public:
    LinkageDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getTransportStreamId();
    int getOriginalNetworkId();
    int getServiceId();
    int getLinkageType();
    const CharVector* getPrivateDataByte();

    static std::string getLinkageTypeString(const int linkageType);



};

#endif // LINKAGEDESCRIPTOR_H
