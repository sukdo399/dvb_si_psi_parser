/*
 *Original Author:	shko
 */

#include <caidentifierdescriptor.h>


CaIdentifierDescriptor::CaSystemId::CaSystemId(const int ca_system_id)
    : ca_system_id(ca_system_id)
{
    ;
}

CaIdentifierDescriptor::CaSystemId::~CaSystemId(void)
{
    ;
}

int CaIdentifierDescriptor::CaSystemId::getCaSystemId()
{
    return ca_system_id;
}

CaIdentifierDescriptor::CaIdentifierDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent)
{
    int t = 0;
    while (t < descriptorLength)
    {
        const int caSystemID = Utils::getInt(buffer, offset + 2 + t, 2, MASK_16BITS);
        CaSystemId* caID = new CaSystemId(caSystemID);
        CaSystemIdVector.push_back(caID);
        t += 2;
    }
}

CaIdentifierDescriptor::~CaIdentifierDescriptor(void)
{
    for(CaSystemIdIterator i = CaSystemIdVector.begin(); i != CaSystemIdVector.end(); ++i)
        delete *i;
}

std::vector<CaIdentifierDescriptor::CaSystemId *>* CaIdentifierDescriptor::getCaSystemIdVector()
{
    return &CaSystemIdVector;
}
