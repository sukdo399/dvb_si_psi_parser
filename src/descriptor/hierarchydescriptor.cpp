/*
 *Original Author:	shko
 */

#include <hierarchydescriptor.h>

HierarchyDescriptor::HierarchyDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset,parent),
      reserved1(Utils::getInt(buffer, offset + 2, 1, 0xf0) >> 4),
      hierarchy_type(Utils::getInt(buffer, offset + 2, 1, 0x0f)),
      reserved2(Utils::getInt(buffer, offset + 3, 1, 0xb0) >> 6),
      hierarchy_layer_index(Utils::getInt(buffer, offset + 3, 1, 0x3F)),
      reserved3(Utils::getInt(buffer, offset + 4, 1, 0xb0) >> 6),
      hierarchy_embedded_layer_index(Utils::getInt(buffer, offset + 4, 1, 0x3F)),
      reserved4(Utils::getInt(buffer, offset + 5, 1, 0xb0) >> 6),
      hierarchy_channel(Utils::getInt(buffer, offset + 5, 1, 0x3F))
{
    ;
}


std::string HierarchyDescriptor::getHierarchyTypeString(const int hierarchyType)
{
    switch (hierarchyType)
    {
        case 0x00 :
            return "Reserved";
        case 0x01 :
            return "ITU-T Rec. H.262 | ISO/IEC 13818-2 Spatial Scalability";
        case 0x02 :
            return "ITU-T Rec. H.262 | ISO/IEC 13818-2 SNR Scalability";
        case 0x03 :
            return "ITU-T Rec. H.262 | ISO/IEC 13818-2 Temporal Scalability";
        case 0x04 :
            return "ITU-T Rec. H.262 | ISO/IEC 13818-2 Data partitioning";
        case 0x05 :
            return "ISO/IEC 13818-3 Extension bitstream";
        case 0x06 :
            return "ITU-T Rec.H222.0 | ISO/IEC 13818-1 Private Stream";
        case 0x07 :
            return "ITU-T Rec. H.262 | ISO/IEC 13818-2 Multi-view Profile";
        case 0x0f :
            return "Base layer";

        default:
            return "Reserved";

    }
}

int HierarchyDescriptor::getReserved1()
{
    return reserved1;
}

int HierarchyDescriptor::getHierarchy_type()
{
    return hierarchy_type;
}

int HierarchyDescriptor::getReserved2()
{
    return reserved2;
}

int HierarchyDescriptor::getHierarchy_layer_index()
{
    return hierarchy_layer_index;
}

int HierarchyDescriptor::getReserved3()
{
    return reserved3;
}

int HierarchyDescriptor::getHierarchy_embedded_layer_index()
{
    return hierarchy_embedded_layer_index;
}

int HierarchyDescriptor::getReserved4()
{
    return reserved4;
}

int HierarchyDescriptor::getHierarchy_channel()
{
    return hierarchy_channel;
}
