/*
 *Original Author:	shko
 */

#ifndef VIDEOWINDOWDESCRIPTOR_H
#define VIDEOWINDOWDESCRIPTOR_H

#include "descriptor.h"

class VideoWindowDescriptor : public Descriptor
{

private:
    const int horizontalOffset;
    const int verticalOffset;
    const int windowPriority;

public:
    VideoWindowDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getHorizontalOffset();
    int getVerticalOffset();
    int getWindowPriority();


};

#endif // VIDEOWINDOWDESCRIPTOR_H
