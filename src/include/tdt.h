/*
 *Original Author:	shko
 */

#ifndef TDT_H
#define TDT_H

#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"

class TDT : public TableSection
{

private:
    CharVector UTC_time;
    int UTC_time_mjd;
    int UTC_time_bcd;

public:
    TDT(const char* raw_data);
    TDT(const char* raw_data, const int siSpec);

    CharVector* getUtcTime();
    int getUtcTimeMjd();
    int getUtcTimeBcd();


private:
    void InitInternalData();
    void SetInternalData(const char *raw_data);
};

#endif // TDT_H
