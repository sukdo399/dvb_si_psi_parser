/*
 *Original Author:	shko
 */

#ifndef TERRESTRIALDELIVERYSYSTEMDESCRIPTOR_H
#define TERRESTRIALDELIVERYSYSTEMDESCRIPTOR_H

#include "descriptor.h"


class TerrestrialDeliverySystemDescriptor : public Descriptor
{

private:
    const int centreFrequency;
    const int bandwidth;
    const int priority;
    const int timeSlicingIndicator;
    const int mpeFecIndicator;
    const int constellation;
    const int hierarchyInformation;
    const int codeRateHPStream;
    const int codeRateLPStream;
    const int guardInterval;
    const int transmissionMode;
    const bool otherFrequencyFlag;

public:
    TerrestrialDeliverySystemDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getCentreFrequency();
    int getBandwidth();
    int getPriority();
    int getTimeSlicingIndicator();
    int getMpeFecIndicator();
    int getConstellation();
    int getHierarchyInformation();
    int getCodeRateHPStream();
    int getCodeRateLPStream();
    int getGuardInterval();
    int getTransmissionMode();
    bool getOtherFrequencyFlag();

    static std::string getBandwidtString(const int bandwidth);

};

#endif // TERRESTRIALDELIVERYSYSTEMDESCRIPTOR_H
