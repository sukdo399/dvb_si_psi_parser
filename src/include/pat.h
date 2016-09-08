/*
 *Original Author:	shko
 */

#ifndef PAT_H
#define PAT_H

#include "tablesectionextendedsyntax.h"
#include "descriptorbuilder.h"

class PAT : public TableSectionExtendedSyntax
{
public:
    class Program
    {
    private:
        int program_number;
        int program_map_PID;

    public:
        Program(const int program_number, const int program_map_PID);
        int getProgram_map_PID();
        int getProgram_number();

    private:
        void InitInternalData();
    };


private:
    std::vector<Program*> programVector;

public:
    PAT(const char* raw_data);
    PAT(const char* raw_data, const int siSpec);
    virtual ~PAT(void);

    virtual std::vector<Program*> buildProgramVector(const char* data, const int i, const int programInfoLength);

    virtual int getTransportStreamId();
    virtual int getNumberOfPrograms();
    virtual int getProgramNumber(const int i);
    virtual int getProgramMapPID(const int i);

    virtual std::vector<Program*>* getProgramVector();


private:
    void InitInternalData();
    void SetInternalData(const char* raw_data);
};

typedef std::vector<PAT::Program*> PATProgramVector;
typedef PATProgramVector::iterator PATProgramIterator;
typedef PATProgramVector::const_iterator PATProgramConstIterator;

#endif // PAT_H
