/*
 *Original Author:	shko
 */

#include "tablesectionextendedsyntax.h"

TableSectionExtendedSyntax::TableSectionExtendedSyntax(const char* raw_data) : TableSection(raw_data, 0)
{
    // TODO: not long format, error!!
    if (sectionSyntaxIndicator == 0)
    {
        //cout << "ERROR ! " << endl;
    }
}

TableSectionExtendedSyntax::TableSectionExtendedSyntax(const char* raw_data, const int siSpec) : TableSection(raw_data, siSpec)
{
    // TODO: not long format, error!!
    if (sectionSyntaxIndicator == 0)
    {
        //cout << "ERROR ! " << endl;
    }
}
