/*
 *Original Author:	shko
 */

#include <bat.h>

BAT::TransportStream::TransportStream(int tsId, int onId, int loopLen, DescriptorVector descVec)
{
    InitInternalData();

    transportStreamID = tsId;
    originalNetworkID = onId;
    transportDescriptorsLength = loopLen;
    descriptorVector = descVec;
}

BAT::TransportStream::~TransportStream()
{
    for(DescriptorIterator i = descriptorVector.begin(); i != descriptorVector.end(); ++i)
        delete *i;
}

int BAT::TransportStream::getTransportStreamId()
{
    return transportStreamID;
}

int BAT::TransportStream::getOriginalNetworkId()
{
    return originalNetworkID;
}

int BAT::TransportStream::getTransportDescriptorsLength()
{
    return transportDescriptorsLength;
}

DescriptorVector* BAT::TransportStream::getDescriptorVector()
{
    return &descriptorVector;
}

void BAT::TransportStream::InitInternalData()
{
    transportStreamID = 0;
    originalNetworkID = 0;
    transportDescriptorsLength = 0;

    descriptorVector.clear();
}

BAT::BAT(const char *raw_data)
    : TableSectionExtendedSyntax(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

BAT::BAT(const char *raw_data, const int siSpec)
    : TableSectionExtendedSyntax(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);
}

BAT::~BAT()
{
    for(DescriptorIterator i = bouquetDescriptorVector.begin(); i != bouquetDescriptorVector.end(); ++i)
        delete *i;

    for(BATTransportStreamIterator ii = transportStreamVector.begin(); ii != transportStreamVector.end(); ++ii)
        delete *ii;
}

int BAT::getBouqetID()
{
    return getTableIdExtension();
}


int BAT::getBouquetDescriptorsLength()
{
    return bouquetDescriptorsLength;
}

DescriptorVector* BAT::getBouquetDescriptorVector()
{
    return &bouquetDescriptorVector;
}

int BAT::getTransportStreamLoopLength()
{
    return transportStreamLoopLength;
}

std::vector<BAT::TransportStream*>* BAT::getTransportStreamVector()
{
    return &transportStreamVector;
}

int BAT::getNumberOfTransportStreams()
{
    return transportStreamVector.size();
}


std::vector<BAT::TransportStream*> BAT::buildTransportStreamVector(const char *data, const int i, const int programInfoLength)
{
    std::vector<TransportStream*> r = std::vector<TransportStream*>();
    int t = 0;
    while (t < programInfoLength)
    {
        int len = Utils::getInt(data, i + t + 4, 2, MASK_12BITS);
        TransportStream* c = new TransportStream(Utils::getInt(data, i + t, 2, MASK_12BITS),
                                                Utils::getInt(data, i + t + 2, 2, MASK_12BITS),
                                                len,
                                                DescriptorBuilder::buildDescriptorVector(data, i + t + 6, len, this)
                                                 );
        t += 6 + len;
        r.push_back(c);

    }

    return r;
}


void BAT::InitInternalData()
{
    bouquetDescriptorsLength = 0;
    transportStreamLoopLength = 0;

    bouquetDescriptorVector.clear();
    transportStreamVector.clear();
}

void BAT::SetInternalData(const char *raw_data)
{

    bouquetDescriptorsLength = Utils::getInt(raw_data, 8, 2, 0x0FFF);
    transportStreamLoopLength = Utils::getInt(raw_data, 10 + bouquetDescriptorsLength, 2, 0x0FFF);

    bouquetDescriptorVector = DescriptorBuilder::buildDescriptorVector(raw_data, 10, bouquetDescriptorsLength, this);
    transportStreamVector = buildTransportStreamVector(raw_data, 12 + bouquetDescriptorsLength, transportStreamLoopLength);

}
