/*
 *Original Author:	shko
 */



#include <avcvideodescriptor.h>

AVCVideoDescriptor::AVCVideoDescriptor(const char *buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent),
      profile_idc(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS)),
      constraint_set0_flag((Utils::getInt(buffer, offset + 3, 1, 0x80) >> 7) ? true : false),
      constraint_set1_flag((Utils::getInt(buffer, offset + 3, 1, 0x40) >> 6) ? true : false),
      constraint_set2_flag((Utils::getInt(buffer, offset + 3, 1, 0x20) >> 5) ? true : false),
      AVC_compatible_flags(Utils::getInt(buffer, offset + 3, 1, MASK_5BITS)),
      level_idc(Utils::getInt(buffer, offset + 4, 1, MASK_8BITS)),
      AVC_still_present(Utils::getInt(buffer, offset + 5, 1, 0x80) >> 7),
      AVC_24_hour_picture_flag((Utils::getInt(buffer, offset + 5, 1, 0x40) >> 6) ? true : false)
{
    ;
}

int AVCVideoDescriptor::getProfileIdc()
{
    return profile_idc;
}

bool AVCVideoDescriptor::getConstraintSet0Flag()
{
    return constraint_set0_flag;
}

bool AVCVideoDescriptor::getConstraintSet1Flag()
{
    return constraint_set1_flag;
}

bool AVCVideoDescriptor::getConstraintSet2Flag()
{
    return constraint_set2_flag;
}

int AVCVideoDescriptor::getAvcCompatibleFlags()
{
    return AVC_compatible_flags;
}

int AVCVideoDescriptor::getLevelIdc()
{
    return level_idc;
}

int AVCVideoDescriptor::getAvcStillPresent()
{
    return AVC_still_present;
}

bool AVCVideoDescriptor::getAvc24hourPictureFlag()
{
    return AVC_24_hour_picture_flag;
}


