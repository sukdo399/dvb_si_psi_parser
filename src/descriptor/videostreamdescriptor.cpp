/*
 *Original Author:	shko
 */

#include <videostreamdescriptor.h>


VideoStreamDescriptor::VideoStreamDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      multipleFrameRateFlag((Utils::getInt(buffer, offset + 2, 1, 0x80) >> 7) > 0 ? true : false),
      frameRateCode(Utils::getInt(buffer, offset + 2, 1, 0x78) >> 3),
      mpeg1OnlyFlag((Utils::getInt(buffer, offset + 2, 1, 0x04) >> 2) > 0 ? true : false),
      constrainedParameterFlag((Utils::getInt(buffer, offset + 2, 1, 0x02) >> 1) > 0 ? true : false),
      stillPictureFlag((Utils::getInt(buffer, offset + 2, 1, 0x01)) > 0 ? true : false),
      profileAndLevelIndication((mpeg1OnlyFlag == 0) ? (Utils::getInt(buffer, offset + 3, 1, 0xFF)) : 0),
      chromaFormat((mpeg1OnlyFlag == 0) ? (Utils::getInt(buffer, offset + 4, 1, 0xC0) >> 6) : 0),
      frameRateExtensionFlag(((mpeg1OnlyFlag == 0) ? (Utils::getInt(buffer, offset + 4, 1, 0x20) >> 5) : 0) > 0 ? true : false),
      reserved((mpeg1OnlyFlag == 0) ? (Utils::getInt(buffer, offset + 4, 1, 0x1F)) : 0)
{
    ;

}



bool VideoStreamDescriptor::getMultipleFrameRateFlag()
{
    return multipleFrameRateFlag;
}

int VideoStreamDescriptor::getFrameRateCode()
{
    return frameRateCode;
}

bool VideoStreamDescriptor::getMpeg1OnlyFlag()
{
    return mpeg1OnlyFlag;
}

bool VideoStreamDescriptor::getConstrainedParameterFlag()
{
    return constrainedParameterFlag;
}

bool VideoStreamDescriptor::getStillPictureFlag()
{
    return stillPictureFlag;
}


int VideoStreamDescriptor::getProfileAndLevelIndication()
{
    return profileAndLevelIndication;
}


int VideoStreamDescriptor::getChromaFormat()
{
    return chromaFormat;
}

bool VideoStreamDescriptor::getFrameRateExtensionFlag()
{
    return frameRateExtensionFlag;
}

int VideoStreamDescriptor::getReserved()
{
    return reserved;
}



std::string VideoStreamDescriptor::getMultipleFrameRateFlagString(const bool multipleFrameRateFlag)
{
    if (multipleFrameRateFlag == 1)
    {
        return "multiple frame rates may be present";
    }
    return "single frame rate is present";
}

std::string VideoStreamDescriptor::getFrameRateString(const int frameRateCode)
{
    switch (frameRateCode)
    {
        case 0:
            return "forbidden";
        case 1:
            return "24000÷1001 (23,976...)";
        case 2:
            return "24 or 23,976";
        case 3:
            return "25";
        case 4:
            return "30 000÷1001 (29,97...) or 23,976";
        case 5:
            return "30 or 23,976 24,0 29,97";
        case 6:
            return "50 or 25,0";
        case 7:
            return "60 000÷1001 (59,94...) or 23,976 29,97";
        case 8:
            return "60 or 23,976 24,0 29,97 30,0 59,94";
        default:
            return "reserved";
    }
}


std::string VideoStreamDescriptor::getMPEG_1_only_flagString(const bool mpeg1OnlyFlag)
{
    if (mpeg1OnlyFlag == 1)
    {
        return "video stream contains only ISO/IEC 11172-2 data";
    }
    return "video stream may contain both ITU-T H.262 | ISO/IEC 13818-2 video data and constrained parameter ISO/IEC 11172-2 video data";
}

std::string VideoStreamDescriptor::getConstrainedParameterFlagString(const bool constrainedParameterFlag)
{
    if (constrainedParameterFlag == 1)
    {
        return "video stream shall not contain unconstrained ISO/IEC 11172-2 video data";
    }
    return "video stream may contain both constrained parameters and unconstrained ISO/IEC 11172-2 video streams";
}

std::string VideoStreamDescriptor::getStillPictureFlagString(const bool stillPictureFlag)
{
    if (stillPictureFlag == 1)
    {
        return "video stream contains only still pictures";
    }
    return "video stream may contain either moving or still picture data";
}



std::string VideoStreamDescriptor::getVideoProfileString(const int code)
{

    switch ((code & 0x7f) >> 4) // 6,5,4 are the 3 bits for the profile code
    {
        case 0:
            return "reserved profile";
        case 1:
            return "high profile";
        case 2:
            return "spatially scalable profile";
        case 3:
            return "snr scalable profile";
        case 4:
            return "main profile";
        case 5:
            return "simple profile";
    }

    return "";
}

std::string VideoStreamDescriptor::getVideoLevelString(const int code)
{

    switch (code & 0x0f)
    {
        case 4:
            return "high level";
        case 6:
            return "high 1440 level";
        case 8:
            return "main level";
        case 10:
            return "low level";
        default:
            return "reserved level";
    }

}

std::string VideoStreamDescriptor::getChromaFormatString(const int code)
{

    switch (code)
    {
        case 0:
            return "forbidden";
        case 1:
            return "4:2:0";
        case 2:
            return "4:2:2";
        case 3:
            return "4:4:4";
    }
    return "illegal";
}
