/*
 *Original Author:	shko
 */

#include <multilingualnetworknamedescriptor.h>


MultilingualNetworkNameDescriptor::MultilingualNetworkName::MultilingualNetworkName(const std::string &lCode, const std::string networkName)
    : iso639LanguageCode(lCode), network_name(networkName)
{
    ;
}

MultilingualNetworkNameDescriptor::MultilingualNetworkName::~MultilingualNetworkName()
{
    ;
}


std::string MultilingualNetworkNameDescriptor::MultilingualNetworkName::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

std::string MultilingualNetworkNameDescriptor::MultilingualNetworkName::getNetworkName()
{
    return network_name;
}

MultilingualNetworkNameDescriptor::MultilingualNetworkNameDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset,parent)
{
    int t = offset + 2;
    while (t < (descriptorLength + offset + 2))
    {
        const std::string languageCode = std::string((char*)&buffer[offset + t], 3);
        int network_name_length = Utils::getInt(buffer, t + 3, 1, MASK_8BITS);
        const std::string networkName = std::string((char*)&buffer[offset + t + 4], network_name_length);
        MultilingualNetworkName* s = new MultilingualNetworkName(languageCode, networkName);
        networkNameVector.push_back(s);
        t += 4 + network_name_length;
    }
}

MultilingualNetworkNameDescriptor::~MultilingualNetworkNameDescriptor()
{
    for(MultilingualNetworkNameIterator i = networkNameVector.begin(); i != networkNameVector.end(); ++i)
        delete *i;
}

std::vector<MultilingualNetworkNameDescriptor::MultilingualNetworkName*>* MultilingualNetworkNameDescriptor::getMultilingualNetworkNameVector()
{
    return &networkNameVector;
}
