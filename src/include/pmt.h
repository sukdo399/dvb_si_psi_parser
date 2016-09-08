/*
 *Original Author:	shko
 */

#ifndef PMT_H
#define PMT_H


#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"

class PMT : public TableSectionExtendedSyntax
{
public:
    class ElementaryStreamInfo
    {

    private:
        int streamtype;
        int elementaryPID;
        int esInfoLength;

        DescriptorVector descriptorVector;

    public:
        std::string getStreamTypeString();

        int getElementaryPID();
        int getEsInfoLength();
        int getStreamtype();


        void setElementaryPID(const int elementaryPID);
        void setEsInfoLength(const int infoLength);
        void setStreamtype(const int streamtype);




        DescriptorVector* getDescriptorVector();
        void setDescriptorVector(DescriptorVector descriptorVector);



    private:
        void InitInternalData();
        //void SetInternal(const char *raw_data);

    public:
        ElementaryStreamInfo();
        virtual ~ElementaryStreamInfo();
    };



private:
    int pcrPid;
    int programInfoLength;

    DescriptorVector descriptorVector;
    std::vector<ElementaryStreamInfo*> elementaryStreamInfoVector;



public:
    PMT(const char* raw_data);
    PMT(const char* raw_data, const int siSpec);
    virtual ~PMT(void);

    virtual std::vector<ElementaryStreamInfo*> buildElementaryStreamInfoVector(const char* data, const int i, const int length);

    int getProgramNumber();
    int getNumberOfStreams();
    int getElementaryPID(const int i);
    int getPcrPid();
    DescriptorVector* getDescriptorVector();
    int getProgramInfoLength();
    std::vector<PMT::ElementaryStreamInfo*>* getElementaryStreamInfoVector();


private:
    void InitInternalData();
    void SetInternalData(const char* raw_data);
};

// TODO: friend class CA

typedef std::vector<PMT::ElementaryStreamInfo*> PMTElementaryStreamInfoVector;
typedef PMTElementaryStreamInfoVector::iterator PMTElementaryStreamInfoIterator;
typedef PMTElementaryStreamInfoVector::const_iterator PMTElementaryStreamInfoConstIterator;


#endif // PMT_H
