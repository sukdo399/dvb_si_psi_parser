/*
 *Original Author:	shko
 */

#ifndef MULTILINGUALNETWORKNAMEDESCRIPTOR_H
#define MULTILINGUALNETWORKNAMEDESCRIPTOR_H

#include "descriptor.h"

class MultilingualNetworkNameDescriptor : public Descriptor
{
public:
    class MultilingualNetworkName
    {

    private:
        const std::string iso639LanguageCode;
        const std::string network_name;

    public:
        MultilingualNetworkName(const std::string &lCode, const std::string networkName);
        virtual ~MultilingualNetworkName(void);

        std::string getIso639LanguageCode();
        std::string getNetworkName();

    };

private:
    std::vector<MultilingualNetworkName*> networkNameVector;


public:
    MultilingualNetworkNameDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~MultilingualNetworkNameDescriptor(void);

    std::vector<MultilingualNetworkName*>* getMultilingualNetworkNameVector();
};

typedef std::vector<MultilingualNetworkNameDescriptor::MultilingualNetworkName*> MultilingualNetworkNameVector;
typedef MultilingualNetworkNameVector::iterator MultilingualNetworkNameIterator;
typedef MultilingualNetworkNameVector::const_iterator MultilingualNetworkNameConstIterator;

#endif // MULTILINGUALNETWORKNAMEDESCRIPTOR_H
