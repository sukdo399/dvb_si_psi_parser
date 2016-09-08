#ifndef CAIDENTIFIERDESCRIPTOR_H
#define CAIDENTIFIERDESCRIPTOR_H

#include "descriptor.h"

class CaIdentifierDescriptor : public Descriptor
{
public:
    class CaSystemId
    {
    private:
        const int ca_system_id;

    public:
        CaSystemId(const int ca_system_id);
        virtual ~CaSystemId(void);

        virtual int getCaSystemId();
    };


private:
    std::vector<CaSystemId*> CaSystemIdVector;



public:
    CaIdentifierDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~CaIdentifierDescriptor();

    std::vector<CaIdentifierDescriptor::CaSystemId *>* getCaSystemIdVector();

};

typedef std::vector<CaIdentifierDescriptor::CaSystemId *> CaSystemIdVector;
typedef CaSystemIdVector::iterator CaSystemIdIterator;
typedef CaSystemIdVector::const_iterator CaSystemIdConstIterator;

#endif // CAIDENTIFIERDESCRIPTOR_H
