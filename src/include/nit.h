/*
 *Original Author:	shko
 */

#ifndef NIT_H
#define NIT_H

#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"


class NIT : public TableSectionExtendedSyntax
{
public:
    class TransportStream
    {
    private:
        int transportStreamID;
        int originalNetworkID;
        int transportDescriptorsLength;

        DescriptorVector descriptorVector;

    public:
        std::vector<Descriptor*>* getDescriptorVector();
        int getOriginalNetworkID();

        int getTransportDescriptorsLength();
        int getTransportStreamID();

    private:
        void InitInternalData();

public:
        TransportStream(const int transportStreamID, const int originalNetworkID, const int transportDescriptorsLength, DescriptorVector descriptorVector);
        ~TransportStream(void);
    };


private:
    DescriptorVector networkDescriptorVector;
    std::vector<TransportStream*> transportStreamVector;
    int networkDescriptorsLength;
    int transportStreamLoopLength;


public:
    NIT(const char* raw_data);
    NIT(const char* raw_data, const int siSpec);
    virtual ~NIT(void);

    int getNetworkID();
    std::vector<Descriptor*>* getNetworkDescriptorVector();
    int getNetworkDescriptorsLength();
    std::vector<NIT::TransportStream*>* getTransportStreamVector();
    int getTransportStreamLoopLength();

//    TransportStream *getTransportStream(const int streamID);
    int getNumberOfTransportStreams();



    std::vector<NIT::TransportStream*> buildTransportStreamVector(const char* data, const int i, const int programInfoLength);


private:
    void InitInternalData();
    void SetInternalData(const char* raw_data);
};

typedef std::vector<NIT::TransportStream*> NITTransportStreamVector;
typedef NITTransportStreamVector::iterator NITTransportStreamIterator;
typedef NITTransportStreamVector::const_iterator NITTransportStreamConstIterator;


#endif // NIT_H
