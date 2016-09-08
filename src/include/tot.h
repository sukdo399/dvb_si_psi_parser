/*
 *Original Author:	shko
 */

#ifndef TOT_H
#define TOT_H

#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"

class TOT : public TableSection
{

private:
    CharVector UTC_time;
    int UTC_time_mjd;
    int UTC_time_bcd;
    int descriptorsLoopLength;
    DescriptorVector descriptorVector;

public:
    TOT(const char* raw_data);
    TOT(const char* raw_data, const int siSpec);
    virtual ~TOT(void);

    DescriptorVector* getDescriptorVector();

    CharVector* getUtcTime();
    int getUtcTimeMjd();
    int getUtcTimeBcd();


private:
    void InitInternalData();
    void SetInternalData(const char *raw_data);
};


#endif // TOT_H
