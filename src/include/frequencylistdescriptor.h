/*
 *Original Author:	shko
 */

#ifndef FREQUENCYLISTDESCRIPTOR_H
#define FREQUENCYLISTDESCRIPTOR_H

#include "descriptor.h"

class FrequencyListDescriptor : public Descriptor
{

public:
    class CentreFrequency
    {

    private:
        const int centreFrequency;


    public:
        CentreFrequency(const int centreFrequency);
        virtual ~CentreFrequency(void);

        int getCentreFrequency();

    };


private:
    std::vector<CentreFrequency*> frequencyVector;
    const int codingType;


public:
    FrequencyListDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~FrequencyListDescriptor(void);

    int getCodingType();

    std::vector<FrequencyListDescriptor::CentreFrequency*>* getCentreFrequencyVector();

private:
    static std::string getCodingTypeString(const int codingType);

};

typedef std::vector<FrequencyListDescriptor::CentreFrequency *> CentreFrequencyVector;
typedef CentreFrequencyVector::iterator CentreFrequencyIterator;
typedef CentreFrequencyVector::const_iterator CentreFrequencyConstIterator;


#endif // FREQUENCYLISTDESCRIPTOR_H
