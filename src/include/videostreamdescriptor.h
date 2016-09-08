/*
 *Original Author:	shko
 */

#ifndef VIDEOSTREAMDESCRIPTOR_H
#define VIDEOSTREAMDESCRIPTOR_H

#include "descriptor.h"


class VideoStreamDescriptor : public Descriptor
{

private:
    const bool multipleFrameRateFlag;
    const int frameRateCode;
    const bool mpeg1OnlyFlag;
    const bool constrainedParameterFlag;
    const bool stillPictureFlag;

    const int profileAndLevelIndication;
    const int chromaFormat;
    const bool frameRateExtensionFlag;
    const int reserved;

public:
    VideoStreamDescriptor(const char* buffer, const int offset, const TableSection* parent);



    bool getMultipleFrameRateFlag();
    int getFrameRateCode();
    bool getMpeg1OnlyFlag();
    bool getConstrainedParameterFlag();
    bool getStillPictureFlag();

    int getProfileAndLevelIndication();
    int getChromaFormat();
    bool getFrameRateExtensionFlag();
    int getReserved();


    static std::string getMultipleFrameRateFlagString(const bool multipleFrameRateFlag);
    static std::string getFrameRateString(const int frameRateCode);
    static std::string getMPEG_1_only_flagString(const bool mpeg1OnlyFlag);
    static std::string getConstrainedParameterFlagString(const bool constrainedParameterFlag);
    static std::string getStillPictureFlagString(const bool stillPictureFlag);

    static std::string getVideoProfileString(const int code);
    static std::string getVideoLevelString(const int code);
    static std::string getChromaFormatString(const int code);


};

#endif // VIDEOSTREAMDESCRIPTOR_H
