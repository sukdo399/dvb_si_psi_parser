/*
 *Original Author:	shko
 */

#ifndef HIERARCHYDESCRIPTOR_H
#define HIERARCHYDESCRIPTOR_H

#include "descriptor.h"

class HierarchyDescriptor : public Descriptor
{

    // ITU-T Rec. H.222.0 (2000 E)/ ISO/IEC 13818-1

private:
    const int reserved1;
    const int hierarchy_type;
    const int reserved2;
    const int hierarchy_layer_index;
    const int reserved3;
    const int hierarchy_embedded_layer_index;
    const int reserved4;
    const int hierarchy_channel;


public:
    HierarchyDescriptor(const char* buffer, const int offset, const TableSection* parent);


    int getReserved1();
    int getHierarchy_type();

    int getReserved2();
    int getHierarchy_layer_index();

    int getReserved3();
    int getHierarchy_embedded_layer_index();

    int getReserved4();
    int getHierarchy_channel();

    static std::string getHierarchyTypeString(const int hierarchyType);

};

#endif // HIERARCHYDESCRIPTOR_H
