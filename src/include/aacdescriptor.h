/*
 *Original Author:	shko
 */

#ifndef AACDESCRIPTOR_H
#define AACDESCRIPTOR_H

#include "descriptor.h"



class AACDescriptor : public Descriptor
{


private:
    const int profile_and_level;
    const int aac_type_flag;

    int aac_type;
    CharVector additional_info;

public:
    AACDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getProfileAndLevel();
    int getAacType();
    const CharVector* getAdditionalInfo();

    static std::string getProfileLevelString(const int profile_and_level);

};


#endif // AACDESCRIPTOR_H
