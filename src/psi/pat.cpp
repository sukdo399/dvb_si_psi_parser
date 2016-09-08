/*
 *Original Author:	shko
 */

#include <pat.h>

PAT::Program::Program(const int program_number, const int program_map_PID)
{

    InitInternalData();
    this->program_number = program_number;
    this->program_map_PID = program_map_PID;
}

int PAT::Program::getProgram_map_PID()
{
    return program_map_PID;
}

int PAT::Program::getProgram_number()
{
    return program_number;
}

void PAT::Program::InitInternalData()
{
    program_number = 0;
    program_map_PID = 0;
}

PAT::PAT(const char *raw_data)
    : TableSectionExtendedSyntax(raw_data, 0)
{
    InitInternalData();
    SetInternalData(raw_data);
}

PAT::PAT(const char *raw_data, const int siSpec)
    : TableSectionExtendedSyntax(raw_data, siSpec)
{
    InitInternalData();
    SetInternalData(raw_data);
}

PAT::~PAT()
{
    for(PATProgramIterator i = programVector.begin(); i != programVector.end(); ++i)
        delete *i;
}

std::vector<PAT::Program*> PAT::buildProgramVector(const char* data, const int i, const int programInfoLength)
{
    std::vector<Program*> r = std::vector<Program*>();
    int t = 0;
    while (t < programInfoLength)
    {
        Program* p = new Program(Utils::getInt(data, i + t, 2, MASK_16BITS), Utils::getInt(data, i + t + 2, 2, MASK_13BITS));
        t += 4;
        r.push_back(p);

    }

    return r;
}

int PAT::getTransportStreamId()
{
    return getTableIdExtension();
}

int PAT::getNumberOfPrograms()
{
    return programVector.size();
}

int PAT::getProgramNumber(const int i)
{
#if 1
    if(i >= programVector.size())
        return 0;

    Program *p = programVector.at(i);
    return p->getProgram_number();
#else
    return (Utils::getUnsignedByte(rawData[8 + (i*4)]) *256) + Utils::getUnsignedByte(rawData[9 + (i*4)]);
#endif
}

int PAT::getProgramMapPID(const int i)
{
#if 1
    if(i >= programVector.size())
        return 0;

    Program *p = programVector.at(i);
    return p->getProgram_map_PID();
#else
    return ((Utils::getUnsignedByte(rawData[10 + (i*4)])& 0x1F)*256) + Utils::getUnsignedByte(rawData[11 + (i*4)]);
#endif
}

std::vector<PAT::Program*>* PAT::getProgramVector()
{
    return &programVector;
}

void PAT::InitInternalData()
{
    programVector.clear();
}

void PAT::SetInternalData(const char* raw_data)
{
    const int programsLength = sectionLength - 9;
    programVector = buildProgramVector(raw_data, 8, programsLength);
}
