/*
 *Original Author:	shko
 */

#include <ac3descriptor.h>

AC3Descriptor::AC3Descriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      component_type_flag((Utils::getInt(buffer, offset + 2, 1, 0x80) >> 7) ? true : false),
      bsid_flag((Utils::getInt(buffer, offset + 2, 1, 0x40) >> 6) ? true : false),
      mainid_flag((Utils::getInt(buffer, offset + 2, 1, 0x20) >> 5) ? true : false),
      asvc_flag((Utils::getInt(buffer, offset + 2, 1, 0x10) >> 4) ? true : false),
      reserved_flags(Utils::getInt(buffer, offset + 2, 1, 0x0F))
{
    int t = offset + 3;

    if (component_type_flag == true)
    {
        component_type = Utils::getInt(buffer, t++, 1, MASK_8BITS);
    }
    else
    {
        component_type = 0;
    }

    if (bsid_flag == true)
    {
        bsid = Utils::getInt(buffer, t++, 1, MASK_8BITS);
    }
    else
    {
        bsid = 0;
    }

    if (mainid_flag == true)
    {
        mainid = Utils::getInt(buffer, t++, 1, MASK_8BITS);
    }
    else
    {
        mainid = 0;
    }

    if (asvc_flag == true)
    {
        asvc = Utils::getInt(buffer, t++, 1, MASK_8BITS);
    }
    else
    {
        asvc = 0;
    }

    if ((t-offset-1) <= descriptorLength)
    {
        additional_info.resize(descriptorLength - ((t-offset) - 2));
        memcpy(&additional_info[0], buffer+t, descriptorLength - ((t-offset) - 2));
    }
    else
    {
        additional_info.clear();
    }
}
bool AC3Descriptor::getComponentTypeFlag()
{
    return component_type_flag;
}

bool AC3Descriptor::getBsidFlag()
{
    return bsid_flag;
}

bool AC3Descriptor::getMainidFlag()
{
    return mainid_flag;
}

bool AC3Descriptor::getAsvcFlag()
{
    return asvc_flag;
}

int AC3Descriptor::getComponentType()
{
    return component_type;
}

int AC3Descriptor::getBsid()
{
    return bsid;
}

int AC3Descriptor::getMainid()
{
    return mainid;
}

int AC3Descriptor::getAsvc()
{
    return asvc;
}

const CharVector* AC3Descriptor::getAdditionalInfo()
{
    return &additional_info;
}
