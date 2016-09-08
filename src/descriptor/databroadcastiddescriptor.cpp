/*
 *Original Author:	shko
 */

#include <databroadcastiddescriptor.h>


DataBroadcastIDDescriptor::DataBroadcastIDDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      dataBroadcastId(Utils::getInt(buffer, offset + 2, 2, MASK_16BITS))
{
    int t = offset + 4;

    selectorByte.resize(descriptorLength - ((t-offset) - 2));
    memcpy(&selectorByte[0], buffer + t, descriptorLength - ((t-offset) - 2));

    if (dataBroadcastId == 0x0005) //en 301192 7.2.1
    {
        ;
        // TODO:
    }
    else if (dataBroadcastId == 0x000a)
    {
        ;
        // TODO:
    } //IP/MAC_notification_info structure ETSI EN 301 192 V1.4.2
    else if (dataBroadcastId == 0x000b)
    {
        ;
        // TODO:

    } // MHP
    else if ((dataBroadcastId == 0x00f0) || (dataBroadcastId == 0x00f1))
    {
        ;
        // TODO:
    } //ETSI ES 202 184 V2.2.1 (2011-03) 9.3.2.1 data_broadcast_id_descriptor
    else if (dataBroadcastId == 0x0106)
    {
        ;
        // TODO:
    }


}



int DataBroadcastIDDescriptor::getDataBroadcastId()
{
    return dataBroadcastId;
}

const CharVector* DataBroadcastIDDescriptor::getSelectorByte()
{
    return &selectorByte;
}

