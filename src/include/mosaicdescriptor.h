/*
 *Original Author:	shko
 */

#ifndef MOSAICDESCRIPTOR_H
#define MOSAICDESCRIPTOR_H

#include "descriptor.h"

class MosaicDescriptor : public Descriptor
{
public:
    class LogicalCell
    {
    private:
        const int logicalCellId;
        const int logicalCellPresentationInfo;
        const int elementaryCellFieldLength;
        //const std::string elementaryCellIds;
        IntVector elementaryCellIdVector;
        const int cellLinkageInfo;

        int bouquetId;
        int originalNetworkId;
        int transportStreamId;
        int serviceId;
        int eventId;

    public:
        LogicalCell(const int logical_cell_id, const int logical_cell_presentation_info, const int elementary_cell_field_length, std::string elementary_cell_ids, const int cell_linkage_info);
        virtual ~LogicalCell(void);

        int getLogicalCellId();
        int getLogicalCellPresentationInfo();
        //std::string getElementaryCellIds();
        IntVector* getElementaryCellIdVector();
        int getCellLinkageInfo();

        int getBouquetId();
        void setBouquetId(const int bouquetId);
        int getOriginalNetworkId();
        void setOriginalNetworkId(const int originalNetworkId);
        int getTransportStreamId();
        void setTransportStreamId(const int transportStreamId);
        int getServiceId();
        void setServiceId(const int serviceId);
        int getEventId();
        void setEventId(const int eventId);
    };


private:
    std::vector<LogicalCell*> logicalCellVector;

    const int mosaicEntryPoint;
    const int numberOfHorizontalElementaryCells;
    const int numberOfVerticalElementaryCells;


public:
    MosaicDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~MosaicDescriptor(void);

    std::vector<MosaicDescriptor::LogicalCell*>* getLogicalCellVector();

    int getMosaicEntryPoint();
    int getNumberOfHorizontalElementaryCells();
    int getNumberOfVerticalElementaryCells();

    static std::string getNumberOfElementaryCellsString(const int cells);
    static std::string getCodingOfLogicalCellPresentationInfoString(const int info);
    static std::string getCodingOfCellLinkageInfoString(const int info);

};
typedef IntVector ElementaryCellIdVector;
typedef ElementaryCellIdVector::iterator ElementaryCellIdIterator;
typedef ElementaryCellIdVector::const_iterator ElementaryCellIdConstIterator;

typedef std::vector<MosaicDescriptor::LogicalCell *> LogicalCellVector;
typedef LogicalCellVector::iterator LogicalCellIterator;
typedef LogicalCellVector::const_iterator LogicalCellConstIterator;


#endif // MOSAICDESCRIPTOR_H
