/*
 *Original Author:	shko
 */

#include <celllistdescriptor.h>


CellListDescriptor::Cell::SubCell::SubCell(const int cellIdExtension, const int subcellLatitude, const int subcellLongitude, const int subcellExtentOfLatitude, const int subcellExtentOfLongitude)
    : cellIdExtension(cellIdExtension),
      subcellLatitude(subcellLatitude),
      subcellLongitude(subcellLongitude),
      subcellExtentOfLatitude(subcellExtentOfLatitude),
      subcellExtentOfLongitude(subcellExtentOfLongitude)
{
    ;
}

CellListDescriptor::Cell::SubCell::~SubCell()
{
    ;
}

int CellListDescriptor::Cell::SubCell::getCellIdExtension()
{
    return cellIdExtension;
}

int CellListDescriptor::Cell::SubCell::getSubcellLatitude()
{
    return subcellLatitude;
}

int CellListDescriptor::Cell::SubCell::getSubcellLongitude()
{
    return subcellLongitude;
}

int CellListDescriptor::Cell::SubCell::getSubcellExtentOfLatitude()
{
    return subcellExtentOfLatitude;
}

int CellListDescriptor::Cell::SubCell::getSubcellExtentOfLongitude()
{
    return subcellExtentOfLongitude;
}



//
CellListDescriptor::Cell::Cell(const int cellId, const int cellLatitude, const int cellLongitude, const int cellExtentOfLatitude, const int cellExtentOfLongitude, const int subcellInfoLoopLength)
    : cellId(cellId),
      cellLatitude(cellLatitude),
      cellLongitude(cellLongitude),
      cellExtentOfLatitude(cellExtentOfLatitude),
      cellExtentOfLongitude(cellExtentOfLongitude),
      subcellInfoLoopLength(subcellInfoLoopLength)
{
    ;
}

CellListDescriptor::Cell::~Cell()
{
    for(SubCellIterator i = subCellVector.begin(); i != subCellVector.end(); ++i)
        delete *i;
}

void CellListDescriptor::Cell::addSubCell(SubCell* s)
{
    subCellVector.push_back(s);
}

int CellListDescriptor::Cell::getCellId()
{
    return cellId;
}

int CellListDescriptor::Cell::getCellLatitude()
{
    return cellLatitude;
}

int CellListDescriptor::Cell::getCellLongitude()
{
    return cellLongitude;
}

int CellListDescriptor::Cell::getCellExtentOfLatitude()
{
    return cellExtentOfLatitude;
}

int CellListDescriptor::Cell::getCellExtentOfLongitude()
{
    return cellExtentOfLongitude;
}

int CellListDescriptor::Cell::getSubcellInfoLoopLength()
{
    return subcellInfoLoopLength;
}

std::vector<CellListDescriptor::Cell::SubCell*>* CellListDescriptor::Cell::getSubCellVector()
{
    return &subCellVector;
}

//
CellListDescriptor::CellListDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
{
    int t = 0;
    while ((t + 9) < descriptorLength)
    {

        const int cell_id = Utils::Utils::getInt(buffer,offset + t + 2, 2, MASK_16BITS);
        const int cell_latitude = Utils::getInt(buffer,offset + t + 4, 2, MASK_16BITS);
        const int cell_longitude = Utils::getInt(buffer,offset + t + 6, 2, MASK_16BITS);
        const int cell_extent_of_latitude = Utils::getInt(buffer,offset + t + 8, 2, 0xFFF0) >> 4;
        const int cell_extent_of_longitude = Utils::getInt(buffer,offset + t + 9, 2, MASK_12BITS);
        const int subcell_info_loop_length = Utils::getInt(buffer,offset + t + 11, 1, MASK_8BITS);

        Cell* cell = new Cell(cell_id, cell_latitude, cell_longitude,cell_extent_of_latitude,cell_extent_of_longitude, subcell_info_loop_length);
        cellVector.push_back(cell);

        t += 10;
        int r = 0;
        while (r < subcell_info_loop_length)
        {
            const int cell_id_extension = Utils::getInt(buffer,offset + t + 2 + r, 1, MASK_8BITS);
            const int subcell_latitude = Utils::getInt(buffer,offset + t + 3 + r, 2, MASK_16BITS);
            const int subcell_longitude = Utils::getInt(buffer,offset + t + 5 + r, 2, MASK_16BITS);
            const int subcell_extent_of_latitude = Utils::getInt(buffer,offset + t + 7 + r, 2, 0xFFF0) >> 4;
            const int subcell_extent_of_longitude = Utils::getInt(buffer,offset + t + 8 + r, 2, MASK_12BITS);

            Cell::SubCell* s = new Cell::SubCell(cell_id_extension,subcell_latitude,subcell_longitude,subcell_extent_of_latitude,subcell_extent_of_longitude);
            cell->addSubCell(s);
            r += 8;
        }
        t += r;
    }
}

CellListDescriptor::~CellListDescriptor()
{
    for(CellIterator i = cellVector.begin(); i != cellVector.end(); ++i)
        delete *i;
}

std::vector<CellListDescriptor::Cell*>* CellListDescriptor::getCellVector()
{
    return &cellVector;
}
