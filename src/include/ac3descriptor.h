/*
 *Original Author:	shko
 */

#ifndef AC3DESCRIPTOR_H
#define AC3DESCRIPTOR_H

#include "descriptor.h"

class AC3Descriptor : public Descriptor
{

private:
    const bool component_type_flag;
    const bool bsid_flag;
    const bool mainid_flag;
    const bool asvc_flag;
    const int reserved_flags;

    int component_type;
    int bsid;
    int mainid;
    int asvc;
    CharVector additional_info;


public:
    AC3Descriptor(const char* buffer, const int offset, const TableSection* parent);

    bool getComponentTypeFlag();
    bool getBsidFlag();
    bool getMainidFlag();
    bool getAsvcFlag();

    int getComponentType();
    int getBsid();
    int getMainid();
    int getAsvc();
    const CharVector* getAdditionalInfo();



};


#endif // AC3DESCRIPTOR_H
