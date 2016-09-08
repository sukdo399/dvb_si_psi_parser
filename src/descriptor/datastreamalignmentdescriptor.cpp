/*
 *Original Author:	shko
 */

#include <datastreamalignmentdescriptor.h>

DataStreamAlignmentDescriptor::DataStreamAlignmentDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      alignmentType(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS))
{
    ;
}


int DataStreamAlignmentDescriptor::getAlignmentType()
{
    return alignmentType;
}

std::string DataStreamAlignmentDescriptor::getAlignmentTypeString(const int alignment)
{
    switch (alignment)
    {
        case 0:
            return "Reserved";
        case 1:
            return "Slice, or video access unit";
        case 2:
            return "Video access unit";
        case 3:
            return "GOP, or SEQ";
        case 4:
            return "SEQ";
        default:
            return "Reserved";
    }
}
