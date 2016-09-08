/*
 *Original Author:	shko
 */

#ifndef MULTILINGUALBOUQUETNAMEDESCRIPTOR_H
#define MULTILINGUALBOUQUETNAMEDESCRIPTOR_H

#include "descriptor.h"

class MultilingualBouquetNameDescriptor : public Descriptor
{
public:
    class MultilingualBouquetName
    {

    private:
        const std::string iso639LanguageCode;
        const std::string bouquet_name;

    public:
        MultilingualBouquetName(const std::string &lCode, const std::string bouquetName);
        virtual ~MultilingualBouquetName(void);

        std::string getIso639LanguageCode();
        std::string getBouquetName();

    };

private:
    std::vector<MultilingualBouquetName*> bouquetNameVector;


public:
    MultilingualBouquetNameDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~MultilingualBouquetNameDescriptor(void);

    std::vector<MultilingualBouquetName*>* getMultilingualBouquetNameVector();
};

typedef std::vector<MultilingualBouquetNameDescriptor::MultilingualBouquetName*> MultilingualBouquetNameVector;
typedef MultilingualBouquetNameVector::iterator MultilingualBouquetNameIterator;
typedef MultilingualBouquetNameVector::const_iterator MultilingualBouquetNameConstIterator;

#endif // MULTILINGUALBOUQUETNAMEDESCRIPTOR_H
