/*
 *Original Author:	shko
 */

#ifndef CONTENTIDENTIFIERDESCRIPTOR_H
#define CONTENTIDENTIFIERDESCRIPTOR_H

#include "descriptor.h"

class ContentIdentifierDescriptor : public Descriptor
{
public:
    class Crid
    {

    private:
        const int cridType;
        const int cridLocation;

        const int cridLength;
        const CharVector cridByte;

        const int cridRef;

    public:

        Crid(const int cridType, const int cridLocation, const int cridLength, CharVector cridByte, const int cridRef);
        virtual ~Crid(void);

        int getCridType();
        int getCridLocation();

        int getCridLength();
        const CharVector* getCridByte();

        int getCridRef();
    };


private:
    std::vector<Crid*> cridVector;


public:
    ContentIdentifierDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~ContentIdentifierDescriptor(void);

    std::vector<ContentIdentifierDescriptor::Crid*>* getCridVector();

    static std::string getCridTypeString(const int type);
    static std::string getCridLocationString(const int type);


};

typedef std::vector<ContentIdentifierDescriptor::Crid *> CridVector;
typedef CridVector::iterator CridIterator;
typedef CridVector::const_iterator CridConstIterator;



#endif // CONTENTIDENTIFIERDESCRIPTOR_H
