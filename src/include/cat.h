/*
 *Original Author:	shko
 */


#ifndef CAT_H
#define CAT_H



#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"


class CAT : public TableSectionExtendedSyntax
{

private:
    DescriptorVector descriptorVector;

public:
    CAT(const char* raw_data);
    CAT(const char* raw_data, const int siSpec);
    virtual ~CAT(void);

    DescriptorVector* getDescriptorVector();

private:
    void InitInternalData();
    void SetInternalData(const char* raw_data);
};




#endif // CAT_H
