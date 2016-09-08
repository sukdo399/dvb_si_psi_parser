/*
 *Original Author:	shko
 */

#ifndef NVODREFERENCEDESCRIPTOR_H
#define NVODREFERENCEDESCRIPTOR_H

#include "descriptor.h"


class NvodReferenceDescriptor : public Descriptor
{
public:
    class NvodService
    {
    private:
        const int transportStreamId;
        const int originalNetworkId;
        const int serviceId;

    public:
        NvodService(const int transportStreamId, const int originalNetworkId, const int serviceId);
        virtual ~NvodService(void);

        int getTransportStreamId();
        int getOriginalNetworkId();
        int getServiceId();

    };


private:
    std::vector<NvodService*> nvodServiceVector; // TODO: const


public:
    NvodReferenceDescriptor(const char* buffe, const int offset, const TableSection* parent);
    virtual ~NvodReferenceDescriptor(void);

    std::vector<NvodReferenceDescriptor::NvodService*>* getNvodServiceVector();

};

typedef std::vector<NvodReferenceDescriptor::NvodService *> NvodServiceVector;
typedef NvodServiceVector::iterator NvodServiceIterator;
typedef NvodServiceVector::const_iterator NvodServiceConstIterator;

#endif // NVODREFERENCEDESCRIPTOR_H
