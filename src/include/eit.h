/*
 *Original Author:	shko
 */

#ifndef EIT_H
#define EIT_H


#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"



class EIT : public TableSectionExtendedSyntax
{
public:
    class Event
    {
    private:
        int eventID;
        CharVector startTime;
        int startTimeMjd;
        int startTimeBcd;
        CharVector duration;
        int durationBcd;
        int runningStatus;
        bool freeCAMode;
        int descriptorsLoopLength;

        DescriptorVector descriptorVector;

    public:
        int getEventID();
        CharVector* getStartTime();
        int getStartTimeMjd();
        int getStartTimeBcd();
        CharVector* getDuration();
        int getDurationBcd();
        int getRunningStatus();
        bool getFreeCAMode();
        int getDescriptorsLoopLength();

        std::string getEventName();

        DescriptorVector* getDescriptorVector();

    private:
        void InitInternalData();

public:
        Event(int eid, CharVector stTime, int stTimeM, int stTimeB,
              CharVector dur, int durB, int runn,
              bool freeCa, int loopLen, DescriptorVector descVec);
        virtual ~Event(void);
    };


private:
    int transportStreamID;
    int originalNetworkID;
    int segmentLastSectionNumber;
    int lastTableID;

    std::vector<Event*> eventVector;

public:
    EIT(const char* raw_data);
    EIT(const char* raw_data, const int siSpec);
    virtual ~EIT(void);

    int getServiceId();
    int getTransportStreamId();
    int getOriginalNetworkId();
    int getSegmentLastSectionNumber();
    int getLastTableId();

    int getNumberOfEvents();
    std::vector<Event*>* getEventVector();

    std::vector<EIT::Event*> buildEventVector(const char* data, const int i, const int programInfoLength);


private:
    void InitInternalData();
    void SetInternalData(const char* raw_data);
};


typedef std::vector<EIT::Event*> EITEventVector;
typedef EITEventVector::iterator EITEventIterator;
typedef EITEventVector::const_iterator EITEventConstIterator;

#endif // EIT_H
