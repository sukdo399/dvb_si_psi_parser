/*
 *Original Author:	shko
 */

#include <videowindowdescriptor.h>

VideoWindowDescriptor::VideoWindowDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      horizontalOffset(Utils::getInt(buffer, offset + 2, 2, 0xFFFC) >> 2),
      verticalOffset(Utils::getInt(buffer, offset + 3, 3, 0x03FFF0) >> 4),
      windowPriority(Utils::getInt(buffer, offset + 5, 1, MASK_4BITS))
{
    ;
}

int VideoWindowDescriptor::getHorizontalOffset()
{
    return horizontalOffset;
}

int VideoWindowDescriptor::getVerticalOffset()
{
    return verticalOffset;
}

int VideoWindowDescriptor::getWindowPriority()
{
    return windowPriority;
}
