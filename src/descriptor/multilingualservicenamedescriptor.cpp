/*
 *Original Author:	shko
 */

#include <multilingualservicenamedescriptor.h>

MultilingualServiceNameDescriptor::MultilingualServiceName::MultilingualServiceName(const std::string &lCode, const std::string service_provider_name2, const std::string service_name2)
    : iso639LanguageCode(lCode), service_provider_name(service_provider_name2), service_name(service_name2)
{
    ;
}

MultilingualServiceNameDescriptor::MultilingualServiceName::~MultilingualServiceName()
{
    ;
}

std::string MultilingualServiceNameDescriptor::MultilingualServiceName::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

std::string MultilingualServiceNameDescriptor::MultilingualServiceName::getServiceProviderName()
{
    return service_provider_name;
}

std::string MultilingualServiceNameDescriptor::MultilingualServiceName::getServiceName()
{
    return service_name;
}

MultilingualServiceNameDescriptor::MultilingualServiceNameDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
{
    int t = offset + 2;
    while (t < (descriptorLength + offset + 2))
    {
        const std::string languageCode = std::string((char*)&buffer[t], 3);
        const int service_provider_name_length = Utils::getInt(buffer, t + 3, 1, MASK_8BITS);
        std::string service_provider_name = std::string((char*)&buffer[t + 4], service_provider_name_length);

        const int service_name_length = Utils::getInt(buffer, t + 4 + service_provider_name_length, 1, MASK_8BITS);
        std::string service_name = std::string((char*)&buffer[t + 5 + service_provider_name_length], service_name_length);

        MultilingualServiceName* s = new MultilingualServiceName(languageCode, service_provider_name, service_name);
        multilingualServiceNameVector.push_back(s);
        t += 5 + service_provider_name_length + service_name_length;
    }
}

MultilingualServiceNameDescriptor::~MultilingualServiceNameDescriptor()
{
    for(MultilingualServiceNameIterator i = multilingualServiceNameVector.begin(); i != multilingualServiceNameVector.end(); ++i)
        delete *i;
}

std::vector<MultilingualServiceNameDescriptor::MultilingualServiceName*> *MultilingualServiceNameDescriptor::getMultilingualServiceNameVector()
{
    return &multilingualServiceNameVector;
}
