/*
 *Original Author:	shko
 */


#ifndef AVCVIDEODESCRIPTOR_H
#define AVCVIDEODESCRIPTOR_H

#include "descriptor.h"

class AVCVideoDescriptor : public Descriptor
{

private:
    const int profile_idc;
    const bool constraint_set0_flag;
    const bool constraint_set1_flag;
    const bool constraint_set2_flag;
    const int AVC_compatible_flags;
    const int level_idc;
    const int AVC_still_present;
    const bool AVC_24_hour_picture_flag;


public:
    AVCVideoDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getProfileIdc();
    bool getConstraintSet0Flag();
    bool getConstraintSet1Flag();
    bool getConstraintSet2Flag();
    int getAvcCompatibleFlags();
    int getLevelIdc();
    int getAvcStillPresent();
    bool getAvc24hourPictureFlag();


};


#endif // AVCVIDEODESCRIPTOR_H
