/*
 *Original Author:	shko
 */

#include <aacdescriptor.h>


AACDescriptor::AACDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      profile_and_level(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS)),
      aac_type_flag(Utils::getInt(buffer, offset + 3, 1, 0x80) >> 7)
{

    int t = offset + 4;
    if (aac_type_flag == 1)
    {
        aac_type = Utils::getInt(buffer, t++, 1, MASK_8BITS);
    }
    else
    {
        aac_type = 0;
    }

    if ((t-offset-1) <= descriptorLength)
    {
        additional_info.resize(descriptorLength - ((t-offset) - 2));
        memcpy(&additional_info[0], buffer+t, descriptorLength - ((t-offset) - 2));
    }
    else
    {
        additional_info.clear();
    }
}

int AACDescriptor::getProfileAndLevel()
{
    return profile_and_level;
}

int AACDescriptor::getAacType()
{
    return aac_type;
}

const CharVector* AACDescriptor::getAdditionalInfo()
{
    return &additional_info;
}


std::string AACDescriptor::getProfileLevelString(const int profile_and_level)
{
    switch (profile_and_level)
    {

        case 0x10:
            return "Main profile, level 1";
        case 0x11:
            return "Main profile, level 2";
        case 0x12:
            return "Main profile, level 3";
        case 0x13:
            return "Main profile, level 4";
        case 0x18:
            return "Scalable Profile, level 1";
        case 0x19:
            return "Scalable Profile, level 2";
        case 0x1A:
            return "Scalable Profile, level 3";
        case 0x1B:
            return "Scalable Profile, level 4";
        case 0x20:
            return "Speech profile, level 1";
        case 0x21:
            return "Speech profile, level 2";
        case 0x28:
            return "Synthesis profile, level 1";
        case 0x29:
            return "Synthesis profile, level 2";
        case 0x2A:
            return "Synthesis profile, level 3";
        case 0x30:
            return "High quality audio profile, level 1";
        case 0x31:
            return "High quality audio profile, level 2";
        case 0x32:
            return "High quality audio profile, level 3";
        case 0x33:
            return "High quality audio profile, level 4";
        case 0x34:
            return "High quality audio profile, level 5";
        case 0x35:
            return "High quality audio profile, level 6";
        case 0x36:
            return "High quality audio profile, level 7";
        case 0x37:
            return "High quality audio profile, level 8";
        case 0x38:
            return "Low delay audio profile, level 1";
        case 0x39:
            return "Low delay audio profile, level 2";
        case 0x3A:
            return "Low delay audio profile, level 3";
        case 0x3B:
            return "Low delay audio profile, level 4";
        case 0x3C:
            return "Low delay audio profile, level 5";
        case 0x3D:
            return "Low delay audio profile, level 6";
        case 0x3E:
            return "Low delay audio profile, level 7";
        case 0x3F:
            return "Low delay audio profile, level 8";
        case 0x40:
            return "Natural audio profile, level 1";
        case 0x41:
            return "Natural audio profile, level 2";
        case 0x42:
            return "Natural audio profile, level 3";
        case 0x43:
            return "Natural audio profile, level 4";
        case 0x48:
            return "Mobile audio internetworking profile, level 1";
        case 0x49:
            return "Mobile audio internetworking profile, level 2";
        case 0x4A:
            return "Mobile audio internetworking profile, level 3";
        case 0x4B:
            return "Mobile audio internetworking profile, level 4";
        case 0x4C:
            return "Mobile audio internetworking profile, level 5";
        case 0x4D:
            return "Mobile audio internetworking profile, level 6";
        case 0x50:
            return "AAC profile, level 1";
        case 0x51:
            return "AAC profile, level 2";
        case 0x52:
            return "AAC profile, level 4";
        case 0x53:
            return "AAC profile, level 5";
        case 0x58:
            return "High efficiency AAC profile, level 2";
        case 0x59:
            return "High efficiency AAC profile, level 3";
        case 0x5A:
            return "High efficiency AAC profile, level 4";
        case 0x5B:
            return "High efficiency AAC profile, level 5";
        case 0x60:
            return "High efficiency AAC v2 profile, level 2";
        case 0x61:
            return "High efficiency AAC v2 profile, level 3";
        case 0x62:
            return "High efficiency AAC v2 profile, level 4";
        case 0x63:
            return "High efficiency AAC v2 profile, level 5";

        case 0xFF:
            return "Audio profile and level not specified by the MPEG-4_audio_profile_and_level field in this descriptor";
        default:
            return "Reserved";

    }
}
