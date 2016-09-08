/*
 *Original Author:	shko
 */

#ifndef MULTILINGUALSERVICENAMEDESCRIPTOR_H
#define MULTILINGUALSERVICENAMEDESCRIPTOR_H

#include "descriptor.h"

class MultilingualServiceNameDescriptor : public Descriptor
{

public:
    class MultilingualServiceName
    {
        ///
    private:
        const std::string iso639LanguageCode;
        const std::string service_provider_name;
        const std::string service_name;

    public:
        MultilingualServiceName(const std::string &lCode, const std::string service_provider_name2, const std::string service_name2);
        virtual ~MultilingualServiceName(void);


        std::string getIso639LanguageCode();
        std::string getServiceProviderName();
        std::string getServiceName();

    };


private:
    std::vector<MultilingualServiceName*> multilingualServiceNameVector;


public:
    MultilingualServiceNameDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~MultilingualServiceNameDescriptor(void);


    std::vector<MultilingualServiceName*>* getMultilingualServiceNameVector();
};

typedef std::vector<MultilingualServiceNameDescriptor::MultilingualServiceName*> MultilingualServiceNameVector;
typedef MultilingualServiceNameVector::iterator MultilingualServiceNameIterator;
typedef MultilingualServiceNameVector::const_iterator MultilingualServiceNameConstIterator;

#endif // MULTILINGUALSERVICENAMEDESCRIPTOR_H
