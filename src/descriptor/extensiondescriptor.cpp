/*
 *Original Author:	shko
 */

#include <extensiondescriptor.h>


ExtensionDescriptor::ExtensionDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      descriptorTagExtension(Utils::getInt(buffer, offset + 2, 1, MASK_8BITS))
{
    int t = offset + 3;
    selectorByte.resize(descriptorLength - ((t-offset) - 2));
    memcpy(&selectorByte[0], buffer + t, descriptorLength - ((t-offset) - 2));
}

int ExtensionDescriptor::getDescriptorTagExtension()
{
    return descriptorTagExtension;
}

CharVector* ExtensionDescriptor::getSelectorByte()
{
    return &selectorByte;
}

std::string ExtensionDescriptor::getDescriptorTagExtensionString(int const descriptor_tag_extension)
{
    switch (descriptor_tag_extension)
    {
        case 0x0:
            return "image_icon_descriptor";
        case 0x1:
            return "cpcm_delivery_signalling_descriptor";
        case 0x2:
            return "CP_descriptor";
        case 0x3:
            return "CP_identifier_descriptor";
        case 0x4:
            return "T2_delivery_system_descriptor";
        case 0x5:
            return "SH_delivery_system_descriptor";
        case 0x6:
            return "supplementary_audio_descriptor";
        case 0x7:
            return "network_change_notify_descriptor";
        case 0x8:
            return "message_descriptor";
        case 0x9:
            return "target_region_descriptor";
        case 0xa:
            return "target_region_name_descriptor";
        case 0xb:
            return "service_relocated_descriptor";
        case 0xc:
            return "XAIT_PID_descriptor";
        case 0xd:
            return "C2_delivery_system_descriptor";
        case 0x10:
            return "video_depth_range_descriptor";
        case 0x11:
            return "T2MI_descriptor";
        default:
            return "reserved for future use";
    }
}
