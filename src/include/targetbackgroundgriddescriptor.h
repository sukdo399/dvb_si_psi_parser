/*
 *Original Author:	shko
 */

#ifndef TARGETBACKGROUNDGRIDDESCRIPTOR_H
#define TARGETBACKGROUNDGRIDDESCRIPTOR_H

#include "descriptor.h"

class TargetBackGroundDescriptor : public Descriptor
{

private:
    const int horizontalSize;
    const int verticalSize;
    const int aspectRatioInformation;

public:
    TargetBackGroundDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getHorizontalSize();
    int getVerticalSize();
    int getAspectRatioInformation();
};


#endif // TARGETBACKGROUNDGRIDDESCRIPTOR_H
