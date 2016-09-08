/*
 *Original Author:	shko
 */

#include <enhancedac3descriptor.h>



EnhancedAC3Descriptor::EnhancedAC3Descriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      component_type_flag((Utils::getInt(buffer, offset + 2, 1, 0x80) >> 7) ? true:false),
      bsid_flag((Utils::getInt(buffer, offset + 2, 1, 0x40) >> 6) ? true:false),
      mainid_flag((Utils::getInt(buffer, offset + 2, 1, 0x20) >> 5) ? true:false),
      asvc_flag((Utils::getInt(buffer, offset + 2, 1, 0x10) >> 4) ? true:false),
      mixinfoexists((Utils::getInt(buffer, offset + 2, 1, 0x08) >> 3) ? true:false),
      substream1_flag((Utils::getInt(buffer, offset + 2, 1, 0x04) >> 2) ? true:false),
      substream2_flag((Utils::getInt(buffer, offset + 2, 1, 0x02) >> 1) ? true:false),
      substream3_flag((Utils::getInt(buffer, offset + 2, 1, 0x01)) ? true:false)


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

    if (substream1_flag == true)
    {
        substream1 = Utils::getInt(buffer, t++, 1, MASK_8BITS);
    }
    else
    {
        substream1 = 0;
    }

    if (substream2_flag == true)
    {
        substream2 = Utils::getInt(buffer, t++, 1, MASK_8BITS);
    }
    else
    {
        substream2 = 0;
    }

    if (substream3_flag == true)
    {
        substream3 = Utils::getInt(buffer, t++, 1, MASK_8BITS);
    }
    else
    {
        substream3 = 0;
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
bool EnhancedAC3Descriptor::getComponentTypeFlag()
{
    return component_type_flag;
}

bool EnhancedAC3Descriptor::getBsidFlag()
{
    return bsid_flag;
}

bool EnhancedAC3Descriptor::getMainidFlag()
{
    return mainid_flag;
}

bool EnhancedAC3Descriptor::getAsvcFlag()
{
    return asvc_flag;
}

bool EnhancedAC3Descriptor::getMixInfoExists()
{
    return mixinfoexists;
}

bool EnhancedAC3Descriptor::getSubStream1Flag()
{
    return substream1_flag;
}

bool EnhancedAC3Descriptor::getSubStream2Flag()
{
    return substream2_flag;
}

bool EnhancedAC3Descriptor::getSubStream3Flag()
{
    return substream3_flag;
}

int EnhancedAC3Descriptor::getComponentType()
{
    return component_type;
}

int EnhancedAC3Descriptor::getBsid()
{
    return bsid;
}

int EnhancedAC3Descriptor::getMainid()
{
    return mainid;
}

int EnhancedAC3Descriptor::getAsvc()
{
    return asvc;
}

int EnhancedAC3Descriptor::getSubStream1()
{
    return substream1;
}

int EnhancedAC3Descriptor::getSubStream2()
{
    return substream2;
}

int EnhancedAC3Descriptor::getSubStream3()
{
    return substream3;
}

const CharVector* EnhancedAC3Descriptor::getAdditionalInfo()
{
    return &additional_info;
}
