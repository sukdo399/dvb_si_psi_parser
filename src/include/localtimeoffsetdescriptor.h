/*
 *Original Author:	shko
 */

#ifndef LOCALTIMEOFFSETDESCRIPTOR_H
#define LOCALTIMEOFFSETDESCRIPTOR_H

#include "descriptor.h"

class LocalTimeOffsetDescriptor : public Descriptor
{
public:
    class LocalTimeOffset
    {

    private:
        const std::string countryCode;
        const int countryRegionId;
        const int localTimeOffsetPolarity;
        const int localTimeOffset;
        const CharVector timeOfChange;
        const int timeOfChangeMjd;
        const int timeOfChangeBcd;
        const int nextTimeOffset;

    public:
        LocalTimeOffset(const std::string &ccode, const int id, const int localPolarity, const int localOffset, CharVector timeChange, const int timeChangeMjd, const int timeChangeBcd, const int nextOffset);
        virtual ~LocalTimeOffset(void);

        std::string getCountryCode();
        int getCountryRegionId();
        int getLocalTimeOffsetPolarity();
        int getLocalTimeOffset();
        const CharVector* getTimeOfChange();
        int getTimeOfChangeMjd();
        int getTimeOfChangeBcd();
        // TODO: unixtime (combination of mjd and bcd).
        int getNextTimeOffset();

    };


private:
    std::vector<LocalTimeOffset*> offsetVector;

public:
    LocalTimeOffsetDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~LocalTimeOffsetDescriptor(void);

    virtual std::vector<LocalTimeOffsetDescriptor::LocalTimeOffset *>* getLocalOffsetVector();

};


typedef std::vector<LocalTimeOffsetDescriptor::LocalTimeOffset *> LocalTimeOffsetVector;
typedef LocalTimeOffsetVector::iterator LocalTimeOffsetIterator;
typedef LocalTimeOffsetVector::const_iterator LocalTimeOffsetConstIterator;


#endif // LOCALTIMEOFFSETDESCRIPTOR_H
