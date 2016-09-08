/*
 *Original Author:	shko
 */

#include <targetbackgroundgriddescriptor.h>


TargetBackGroundDescriptor::TargetBackGroundDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      horizontalSize(Utils::getInt(buffer, offset + 2, 2, 0xFFFC) >> 2),
      verticalSize(Utils::getInt(buffer, offset + 3, 3, 0x03FFF0) >> 4),
      aspectRatioInformation(Utils::getInt(buffer, offset + 5, 1, MASK_4BITS))
{
    ;
}

int TargetBackGroundDescriptor::getHorizontalSize()
{
    return horizontalSize;
}

int TargetBackGroundDescriptor::getVerticalSize()
{
    return verticalSize;
}

int TargetBackGroundDescriptor::getAspectRatioInformation()
{
    return aspectRatioInformation;
}
