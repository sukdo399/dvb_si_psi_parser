/*
 *Original Author:	shko
 */

#ifndef CELLLISTDESCRIPTOR_H
#define CELLLISTDESCRIPTOR_H

#include "descriptor.h"

class CellListDescriptor : public Descriptor
{
public:
    class Cell
    {
    public:
        class SubCell
        {
        private:
            const int cellIdExtension;
            const int subcellLatitude;
            const int subcellLongitude;
            const int subcellExtentOfLatitude;
            const int subcellExtentOfLongitude;


        public:
            SubCell(const int cellIdExtension, const int subcellLatitude, const int subcellLongitude, const int subcellExtentOfLatitude, const int subcellExtentOfLongitude);
            virtual ~SubCell(void);

            int getCellIdExtension();
            int getSubcellLatitude();
            int getSubcellLongitude();
            int getSubcellExtentOfLatitude();
            int getSubcellExtentOfLongitude();
        };

    private:
        const int cellId;
        const int cellLatitude;
        const int cellLongitude;
        const int cellExtentOfLatitude;
        const int cellExtentOfLongitude;
        const int subcellInfoLoopLength;

        std::vector<SubCell*> subCellVector;


    public:
        Cell(const int cellId, const int cellLatitude, const int cellLongitude, const int cellExtentOfLatitude, const int cellExtentOfLongitude, const int subcellInfoLoopLength);
        virtual ~Cell(void);

        int getCellId();
        int getCellLatitude();
        int getCellLongitude();
        int getCellExtentOfLatitude();
        int getCellExtentOfLongitude();
        int getSubcellInfoLoopLength();

        std::vector<CellListDescriptor::Cell::SubCell*>* getSubCellVector();

        void addSubCell(SubCell* s);

    };


private:
    std::vector<Cell*> cellVector;

public:
    CellListDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~CellListDescriptor(void);

    virtual std::vector<CellListDescriptor::Cell*>* getCellVector();



};

typedef std::vector<CellListDescriptor::Cell::SubCell *> SubCellVector;
typedef SubCellVector::iterator SubCellIterator;
typedef SubCellVector::const_iterator SubCellConstIterator;


typedef std::vector<CellListDescriptor::Cell *> CellVector;
typedef CellVector::iterator CellIterator;
typedef CellVector::const_iterator CellConstIterator;

#endif // CELLLISTDESCRIPTOR_H
