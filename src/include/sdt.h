/*
 *Original Author:	shko
 */

#ifndef SDT_H
#define SDT_H



#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"


class SDT : public TableSectionExtendedSyntax
{
public:
    class Service
    {

    private:
        int serviceID;
        int reserved;
        bool eitScheduleFlag;
        bool eitPresentFollowingFlag;
        int runningStatus;
        bool freeCAmode;
        int serviceDescriptorLoopLength;

        DescriptorVector descriptorVector;

    public:
        Service(int svcId, int reserv, bool eitSchFlag, bool eitPfFlag, int runn,
                bool freeCa, int loopLen, DescriptorVector descVector);
        virtual ~Service(void);

        int getServiceID();
        int getReserved();
        bool getEitScheduleFlag();
        bool getEitPresentFollowingFlag();
        int getRunningStatus();
        bool getFreeCAmode();
        int getServiceDescriptorLoopLength();

        DescriptorVector* getDescriptorVector();


    private:
        void InitInternalData();
    };


private:
    int originalNetworkID;

    std::vector<Service*> serviceVector;


public:
    SDT(const char* raw_data);
    SDT(const char* raw_data, const int siSpec);
    virtual ~SDT(void);

    int getOriginalNetworkID();
    int getTransportStreamID();
    int getNumberOfServices();

    std::vector<Service*>* getServiceVector();

    std::vector<SDT::Service*> buildServicesVector(const char* data, const int i, const int programInfoLength);


    static std::string getEitScheduleFlagString(const int eitScheduleFlag);
    static std::string getEitPresentFollowingFlagString(const int eitPresentFollowingFlag);

private:
    void InitInternalData();
    void SetInternalData(const char* raw_data);
};

typedef std::vector<SDT::Service*> SDTServiceVector;
typedef SDTServiceVector::iterator SDTServiceIterator;
typedef SDTServiceVector::const_iterator SDTServiceConstIterator;


#endif // SDT_H
