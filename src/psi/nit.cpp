/*
 *Original Author:	shko
 */

#include <nit.h>

NIT::TransportStream::TransportStream(const int transportStreamID, const int originalNetworkID, const int transportDescriptorsLength, DescriptorVector descriptorVector)
{
    InitInternalData();

    this->transportStreamID = transportStreamID;
    this->originalNetworkID = originalNetworkID;
    this->transportDescriptorsLength = transportDescriptorsLength;
    this->descriptorVector = descriptorVector;

}

NIT::TransportStream::~TransportStream()
{
    for(DescriptorIterator i = descriptorVector.begin(); i != descriptorVector.end(); ++i)
        delete *i;
}

std::vector<Descriptor*>* NIT::TransportStream::getDescriptorVector()
{
    return &descriptorVector;
}


int NIT::TransportStream::getOriginalNetworkID()
{
    return originalNetworkID;
}


int NIT::TransportStream::getTransportDescriptorsLength()
{
    return transportDescriptorsLength;
}

int NIT::TransportStream::getTransportStreamID()
{
    return transportStreamID;
}




void NIT::TransportStream::InitInternalData()
{
    transportStreamID = 0;
    originalNetworkID = 0;
    transportDescriptorsLength = 0;
}





NIT::NIT(const char *raw_data)
    : TableSectionExtendedSyntax(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

NIT::NIT(const char *raw_data, const int siSpec)
    : TableSectionExtendedSyntax(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);
}

NIT::~NIT()
{
    for(DescriptorIterator i = networkDescriptorVector.begin(); i != networkDescriptorVector.end(); ++i)
        delete *i;

    for(NITTransportStreamIterator ii = transportStreamVector.begin(); ii != transportStreamVector.end(); ++ii)
        delete *ii;
}

int NIT::getNetworkID()
{
    return getTableIdExtension();
}


std::vector<Descriptor*>* NIT::getNetworkDescriptorVector()
{
    return &networkDescriptorVector;
}


int NIT::getNetworkDescriptorsLength()
{
    return networkDescriptorsLength;
}


std::vector<NIT::TransportStream*>* NIT::getTransportStreamVector()
{
    return &transportStreamVector;
}




int NIT::getTransportStreamLoopLength()
{
    return transportStreamLoopLength;
}

int NIT::getNumberOfTransportStreams()
{
    return transportStreamVector.size();
}


std::vector<NIT::TransportStream*> NIT::buildTransportStreamVector(const char* data, const int i, const int programInfoLength)
{
    std::vector<TransportStream*> r = std::vector<TransportStream*>();
    int t = 0;
    while (t < programInfoLength)
    {
        TransportStream* c = new TransportStream(Utils::getInt(data, i + t, 2, MASK_16BITS),
                                                 Utils::getInt(data, i + t + 2, 2, MASK_16BITS),
                                                 Utils::getInt(data, i + t + 4, 2, MASK_12BITS),
                                                 DescriptorBuilder::buildDescriptorVector(data, i + t + 6, Utils::getInt(data, i + t + 4, 2, MASK_12BITS), this));

        t += 6 + c->getTransportDescriptorsLength();
        r.push_back(c);

    }

    return r;
}


void NIT::InitInternalData()
{
    networkDescriptorsLength = 0;
    transportStreamLoopLength = 0;

    networkDescriptorVector.clear();
    transportStreamVector.clear();
}

void NIT::SetInternalData(const char *raw_data)
{
    networkDescriptorsLength = Utils::getInt(raw_data, 8, 2, MASK_12BITS);
    transportStreamLoopLength = Utils::getInt(raw_data, 10 + networkDescriptorsLength, 2, MASK_12BITS);

    networkDescriptorVector = DescriptorBuilder::buildDescriptorVector(raw_data, 10, networkDescriptorsLength,this);
    transportStreamVector = buildTransportStreamVector(raw_data, 12 + networkDescriptorsLength, transportStreamLoopLength);

}
