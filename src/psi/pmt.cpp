/*
 *Original Author:	shko
 */

#include <pmt.h>

std::string PMT::ElementaryStreamInfo::getStreamTypeString()
{
    return Utils::getStreamTypeString(streamtype);
}

int PMT::ElementaryStreamInfo::getElementaryPID()
{
    return elementaryPID;
}

int PMT::ElementaryStreamInfo::getEsInfoLength()
{
    return esInfoLength;
}


int PMT::ElementaryStreamInfo::getStreamtype()
{
    return streamtype;
}

void PMT::ElementaryStreamInfo::setElementaryPID(const int elementaryPID)
{
    this->elementaryPID = elementaryPID;
}

void PMT::ElementaryStreamInfo::setEsInfoLength(const int infoLength)
{
    this->esInfoLength = infoLength;
}

void PMT::ElementaryStreamInfo::setStreamtype(const int streamtype)
{
    this->streamtype = streamtype;
}

DescriptorVector* PMT::ElementaryStreamInfo::getDescriptorVector()
{
    return &descriptorVector;
}

void PMT::ElementaryStreamInfo::setDescriptorVector(DescriptorVector descriptorVector)
{
    this->descriptorVector = descriptorVector;
}

void PMT::ElementaryStreamInfo::InitInternalData()
{
    streamtype = 0;
    elementaryPID = 0;
    esInfoLength = 0;
}

PMT::ElementaryStreamInfo::ElementaryStreamInfo(void)
{
    InitInternalData();
}


PMT::ElementaryStreamInfo::~ElementaryStreamInfo(void)
{
    for (DescriptorIterator i = descriptorVector.begin(); i != descriptorVector.end(); ++i)
        delete *i;
}

std::vector<PMT::ElementaryStreamInfo*> PMT::buildElementaryStreamInfoVector(const char* data, const int i, const int length)
{
    std::vector<ElementaryStreamInfo*> r = std::vector<ElementaryStreamInfo*>();
    int t = 0;
    while (t < length)
    {
        PMT::ElementaryStreamInfo * c = new ElementaryStreamInfo();
        c->setStreamtype(Utils::getUnsignedByte(data[i + t]));
        c->setElementaryPID((256 *(Utils::getUnsignedByte(data[i + t + 1])& 0x1F)) + Utils::getUnsignedByte(data[i + t + 2]));
        c->setEsInfoLength((256 *(Utils::getUnsignedByte(data[i + t + 3])& 0x0F)) + Utils::getUnsignedByte(data[i + t + 4]));
        // TODO:
        c->setDescriptorVector(DescriptorBuilder::buildDescriptorVector(data,i + t + 5,c->getEsInfoLength(), this));
        t += 5 + c->getEsInfoLength();
        r.push_back(c);
    }

    return r;

}


PMT::PMT(const char* raw_data) : TableSectionExtendedSyntax(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

PMT::PMT(const char* raw_data, const int siSpec) : TableSectionExtendedSyntax(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);
}

PMT::~PMT(void)
{
    for (PMTElementaryStreamInfoIterator i = elementaryStreamInfoVector.begin(); i != elementaryStreamInfoVector.end(); ++i)
        delete *i;

    for (DescriptorIterator ii = descriptorVector.begin(); ii != descriptorVector.end(); ++ii)
        delete *ii;
}

int PMT::getProgramNumber()
{
    return getTableIdExtension();
}

int PMT::getNumberOfStreams()
{
    return elementaryStreamInfoVector.size();
}

int PMT::getElementaryPID(const int i)
{
#if 1
    if(i >= elementaryStreamInfoVector.size())
        return 0;

    ElementaryStreamInfo *c = elementaryStreamInfoVector.at(i);

    return c->getElementaryPID();
#else // ES_info_length should be checked
    return ((Utils::getUnsignedByte(rawData[12 + programInfoLength + (i*4)])& 0x1F)*256) + Utils::getUnsignedByte(rawData[11 + programInfoLength + (i*4)]);
#endif
}


int PMT::getPcrPid()
{
    return pcrPid;
}


DescriptorVector* PMT::getDescriptorVector()
{
    return &descriptorVector;
}


int PMT::getProgramInfoLength()
{
    return programInfoLength;
}


std::vector<PMT::ElementaryStreamInfo*>* PMT::getElementaryStreamInfoVector()
{
    return &elementaryStreamInfoVector;
}

void PMT::InitInternalData()
{
    pcrPid = 0;
    programInfoLength = 0;
    descriptorVector.clear();
    elementaryStreamInfoVector.clear();
}

void PMT::SetInternalData(const char* raw_data)
{
    pcrPid = Utils::getInt(raw_data, 8, 2, 0x1FFF);
    programInfoLength = Utils::getInt(raw_data, 10, 2, 0x0FFF);
    descriptorVector = DescriptorBuilder::buildDescriptorVector(raw_data, 12, programInfoLength, this);
    elementaryStreamInfoVector = buildElementaryStreamInfoVector(raw_data,12 + programInfoLength, sectionLength - programInfoLength - 12 - 1);

}
