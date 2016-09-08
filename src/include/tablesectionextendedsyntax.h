/*
 *Original Author:	shko
 */

#ifndef TABLESECTIONEXTENDEDSYNTAX_H
#define TABLESECTIONEXTENDEDSYNTAX_H

#include <tablesection.h>

class TableSectionExtendedSyntax : public TableSection
{
public:
    TableSectionExtendedSyntax(const char* raw_data);
    TableSectionExtendedSyntax(const char* raw_data, const int spec);
};

#endif // TABLESECTIONEXTENDEDSYNTAX_H
