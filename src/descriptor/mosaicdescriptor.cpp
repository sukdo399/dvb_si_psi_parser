/*
 *Original Author:	shko
 */

#include <mosaicdescriptor.h>


MosaicDescriptor::LogicalCell::LogicalCell(const int logical_cell_id, const int logical_cell_presentation_info, const int elementary_cell_field_length, std::string elementary_cell_ids, const int cell_linkage_info)
    : logicalCellId(logical_cell_id),
      logicalCellPresentationInfo(logical_cell_presentation_info),
      elementaryCellFieldLength(elementary_cell_field_length),
      //elementaryCellIds(elementary_cell_ids),
      cellLinkageInfo(cell_linkage_info)

{
    for(int i = 0; i < elementary_cell_field_length; i++)
        elementaryCellIdVector.push_back((int)(elementary_cell_ids.at(i) & 0x3F));
}

MosaicDescriptor::LogicalCell::~LogicalCell()
{
    ;
}

int MosaicDescriptor::LogicalCell::getLogicalCellId()
{
    return logicalCellId;
}

int MosaicDescriptor::LogicalCell::getLogicalCellPresentationInfo()
{
    return logicalCellPresentationInfo;
}

IntVector* MosaicDescriptor::LogicalCell::getElementaryCellIdVector()
{
    return &elementaryCellIdVector;
}

#if 0
std::string MosaicDescriptor::LogicalCell::getElementaryCellIds()
{
    return elementaryCellIds;
}
#endif


int MosaicDescriptor::LogicalCell::getCellLinkageInfo()
{
    return cellLinkageInfo;
}

int MosaicDescriptor::LogicalCell::getBouquetId()
{
    return bouquetId;
}

void MosaicDescriptor::LogicalCell::setBouquetId(const int bouquetId)
{
    this->bouquetId = bouquetId;
}

int MosaicDescriptor::LogicalCell::getOriginalNetworkId()
{
    return originalNetworkId;
}

void MosaicDescriptor::LogicalCell::setOriginalNetworkId(const int originalNetworkId)
{
    this->originalNetworkId = originalNetworkId;
}

int MosaicDescriptor::LogicalCell::getTransportStreamId()
{
    return transportStreamId;
}

void MosaicDescriptor::LogicalCell::setTransportStreamId(const int transportStreamId)
{
    this->transportStreamId = transportStreamId;
}

int MosaicDescriptor::LogicalCell::getServiceId()
{
    return serviceId;
}

void MosaicDescriptor::LogicalCell::setServiceId(const int serviceId)
{
    this->serviceId = serviceId;
}

int MosaicDescriptor::LogicalCell::getEventId()
{
    return eventId;
}

void MosaicDescriptor::LogicalCell::setEventId(const int eventId)
{
    this->eventId = eventId;
}



MosaicDescriptor::MosaicDescriptor(const char* buffer, const int offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent),
      mosaicEntryPoint(Utils::getInt(buffer, offset + 2, 1, 0x80) >> 7),
      numberOfHorizontalElementaryCells(Utils::getInt(buffer, offset + 2, 1, 0x70) >> 4),
      numberOfVerticalElementaryCells(Utils::getInt(buffer, offset + 2, 1, 0x07))
{


    int t = 1;
    while (t < descriptorLength)
    {
        const int logical_cell_id = Utils::getInt(buffer, offset + t + 2, 1, 0xFC) >> 2;
        const int logical_cell_presentation_info = Utils::getInt(buffer, offset + t + 3, 1, MASK_3BITS);
        const int elementary_cell_field_length = Utils::getInt(buffer, offset + t + 4, 1, MASK_8BITS);
        const std::string elementary_cell_ids = std::string((char*)&buffer[offset + t + 5], elementary_cell_field_length);
        const int cell_linkage_info = Utils::getInt(buffer, offset + t + 5 + elementary_cell_field_length, 1, MASK_8BITS);

        LogicalCell* s = new LogicalCell(logical_cell_id, logical_cell_presentation_info, elementary_cell_field_length, elementary_cell_ids, cell_linkage_info);

        {
            s->setBouquetId(0);
            s->setOriginalNetworkId(0);
            s->setTransportStreamId(0);
            s->setServiceId(0);
            s->setEventId(0);
        }

        t = t + 4 + elementary_cell_field_length;
        if (cell_linkage_info == 0x01)
        {
            s->setBouquetId(Utils::getInt(buffer, offset + t + 2, 2, MASK_16BITS));
            t = t + 2;
        }

        if (cell_linkage_info == 0x02)
        {
            s->setOriginalNetworkId(Utils::getInt(buffer, offset + t + 2, 2, MASK_16BITS));
            s->setTransportStreamId(Utils::getInt(buffer, offset + t + 4, 2, MASK_16BITS));
            s->setServiceId(Utils::getInt(buffer, offset + t + 6, 2, MASK_16BITS));
            t = t + 6;
        }


        if (cell_linkage_info == 0x03)
        {
            s->setOriginalNetworkId(Utils::getInt(buffer, offset + t + 2, 2, MASK_16BITS));
            s->setTransportStreamId(Utils::getInt(buffer, offset + t + 4, 2, MASK_16BITS));
            s->setServiceId(Utils::getInt(buffer, offset + t + 6, 2, MASK_16BITS));
            t = t + 6;
        }
        if (cell_linkage_info == 0x04)
        {
            s->setOriginalNetworkId(Utils::getInt(buffer, offset + t + 2, 2, MASK_16BITS));
            s->setTransportStreamId(Utils::getInt(buffer, offset + t + 4, 2, MASK_16BITS));
            s->setServiceId(Utils::getInt(buffer, offset + t + 6, 2, MASK_16BITS));
            s->setEventId(Utils::getInt(buffer, offset + t + 8, 2, MASK_16BITS));
            t = t + 8;
        }
        logicalCellVector.push_back(s);
    }
}

MosaicDescriptor::~MosaicDescriptor()
{
    for(LogicalCellIterator i = logicalCellVector.begin(); i != logicalCellVector.end(); ++i)
        delete *i;
}

std::vector<MosaicDescriptor::LogicalCell*>* MosaicDescriptor::getLogicalCellVector()
{
    return &logicalCellVector;
}

int MosaicDescriptor::getMosaicEntryPoint()
{
    return mosaicEntryPoint;
}

int MosaicDescriptor::getNumberOfHorizontalElementaryCells()
{
    return numberOfHorizontalElementaryCells;
}

int MosaicDescriptor::getNumberOfVerticalElementaryCells()
{
    return numberOfVerticalElementaryCells;
}

std::string MosaicDescriptor::getNumberOfElementaryCellsString(const int cells)
{
    switch (cells)
    {
        case 0x0:
            return "one cell";
        case 0x1:
            return "two cells";
        case 0x2:
            return "three cells";
        case 0x3:
            return "four cells";
        case 0x4:
            return "five cells";
        case 0x5:
            return "six cells";
        case 0x6:
            return "seven cells";
        case 0x7:
            return "eight cells";
        default:
            return "illegal value";
    }
}

std::string MosaicDescriptor::getCodingOfLogicalCellPresentationInfoString(const int info)
{
    switch (info)
    {
        case 0x0:
            return "undefined";
        case 0x1:
            return "video";
        case 0x2:
            return "still picture";
        case 0x3:
            return "graphics/text";
        default:
            return "reserved for future use";
    }
}

std::string MosaicDescriptor::getCodingOfCellLinkageInfoString(const int info)
{
    switch (info)
    {
        case 0x0:
            return "undefined";
        case 0x1:
            return "bouquet related";
        case 0x2:
            return "service related";
        case 0x3:
            return "other mosaic related";
        case 0x4:
            return "event related";
        default:
            return "reserved for future use";
    }
}
