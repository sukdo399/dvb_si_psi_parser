/*
 *Original Author:	shko
 */

#include <multilingualbouquetnamedescriptor.h>


MultilingualBouquetNameDescriptor::MultilingualBouquetName::MultilingualBouquetName(const std::string &lCode, const std::string bouquetName)
    : iso639LanguageCode(lCode), bouquet_name(bouquetName)
{
    ;
}

MultilingualBouquetNameDescriptor::MultilingualBouquetName::~MultilingualBouquetName()
{
    ;
}


std::string MultilingualBouquetNameDescriptor::MultilingualBouquetName::getIso639LanguageCode()
{
    return iso639LanguageCode;
}

std::string MultilingualBouquetNameDescriptor::MultilingualBouquetName::getBouquetName()
{
    return bouquet_name;
}

MultilingualBouquetNameDescriptor::MultilingualBouquetNameDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset,parent)
{
    int t = offset + 2;
    while (t < (descriptorLength + offset + 2))
    {
        const std::string languageCode = std::string((char*)&buffer[offset + t], 3);
        int bouquet_name_length = Utils::getInt(buffer, t + 3, 1, MASK_8BITS);
        const std::string bouquetName = std::string((char*)&buffer[offset + t + 4], bouquet_name_length);
        MultilingualBouquetName* s = new MultilingualBouquetName(languageCode, bouquetName);
        bouquetNameVector.push_back(s);
        t += 4 + bouquet_name_length;
    }
}

MultilingualBouquetNameDescriptor::~MultilingualBouquetNameDescriptor()
{
    for(MultilingualBouquetNameIterator i = bouquetNameVector.begin(); i != bouquetNameVector.end(); ++i)
        delete *i;
}

std::vector<MultilingualBouquetNameDescriptor::MultilingualBouquetName*>* MultilingualBouquetNameDescriptor::getMultilingualBouquetNameVector()
{
    return &bouquetNameVector;
}
