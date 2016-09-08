/*
 *Original Author:	shko
 */

#ifndef BAT_H
#define BAT_H



#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"


class BAT : public TableSectionExtendedSyntax
{
public:
    class TransportStream
    {

    private:
        int transportStreamID;
        int originalNetworkID;
        int transportDescriptorsLength;

        DescriptorVector  descriptorVector;

    public:
        int getTransportStreamId();
        int getOriginalNetworkId();
        int getTransportDescriptorsLength();

        DescriptorVector*  getDescriptorVector();


    private:
        void InitInternalData();

public:
        TransportStream(int tsId, int onId, int loopLen, DescriptorVector descVec);
        virtual ~TransportStream();
    };


private:
    DescriptorVector  bouquetDescriptorVector;
    std::vector<BAT::TransportStream*> transportStreamVector;
    int bouquetDescriptorsLength;
    int transportStreamLoopLength;

public:
    BAT(const char* raw_data);
    BAT(const char* raw_data, const int siSpec);
    virtual ~BAT(void);

    int getBouqetID();
    int getBouquetDescriptorsLength();
    DescriptorVector* getBouquetDescriptorVector();

    int getTransportStreamLoopLength();
    std::vector<BAT::TransportStream*>* getTransportStreamVector();

    int getNumberOfTransportStreams();

    std::vector<BAT::TransportStream*> buildTransportStreamVector(const char* data, const int i, const int programInfoLength);


private:
    void InitInternalData();
    void SetInternalData(const char* raw_data);
};

typedef std::vector<BAT::TransportStream*> BATTransportStreamVector;
typedef BATTransportStreamVector::iterator BATTransportStreamIterator;
typedef BATTransportStreamVector::const_iterator BATTransportStreamConstIterator;


#endif // BAT_H
