/*
 *Original Author:	shko
 */

#ifndef TABLESECTION_H
#define TABLESECTION_H

#include "common.h"
#include "crc32.h"
#include "sispec.h"
#include "tableid.h"

class TableSection
{

protected:
    char *rawData;

private:
    void InitInternalData();
    void tableSectionInner(const char* raw_data);

    /* common section data */
protected:
    int tableId;

    // TODO: short section.
    int sectionSyntaxIndicator;
    int privateIndicator;
    int sectionLength;

    // TODO: long section.
    /* used if b_syntax_indicator is true */
    int tableIdExtension;
    int version;
    int currentNext;
    int sectionNumber;
    int sectionLastNumber;
    long long crc;
    bool crc_error;

    const int siSpec; // for private descriptor. originally private_data_specifier was used

public:
    TableSection(const char* raw_data);
    TableSection(const char* raw_data, const int siSpec);
    virtual ~TableSection(void);

    const char *getRaw_data();

    int getTableId();
    int getSectionSyntaxIndicator();
    int getPrivateIndicator();
    int getSectionLength();
    int getTableIdExtension();
    int getVersionNumber();
    int getCurrentNextIndicator();
    int getSectionNumber();
    int getLastSectionNumber();
    long long getCrc();
    bool getCrcError();

    int getSiSpec(); // for private descriptor. private_data_specifier...

    static std::string getTableType(const int tableId);

};

typedef std::vector<TableSection *> TableSectionVector;
typedef TableSectionVector::iterator TableSectionIterator;
typedef TableSectionVector::const_iterator TableSectionConstIterator;

#endif // TABLESECTION_H
