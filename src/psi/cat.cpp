/*
 *Original Author:	shko
 */

#include <cat.h>

CAT::CAT(const char* raw_data)
    : TableSectionExtendedSyntax(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

CAT::CAT(const char* raw_data, const int siSpec)
    : TableSectionExtendedSyntax(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);
}

CAT::~CAT()
{
    for(DescriptorIterator i = descriptorVector.begin(); i != descriptorVector.end(); ++i)
        delete *i;
}

DescriptorVector* CAT::getDescriptorVector()
{
    return &descriptorVector;
}

void CAT::InitInternalData()
{
    descriptorVector.clear();
}

void CAT::SetInternalData(const char* raw_data)
{
    descriptorVector = DescriptorBuilder::buildDescriptorVector(raw_data, 8, sectionLength - 9, this);
}
