/*
 *Original Author:	shko
 */

#ifndef FTACONTENTMANAGEMENTDESCRIPTOR_H
#define FTACONTENTMANAGEMENTDESCRIPTOR_H

#include "descriptor.h"

class FTAContentManagementDescriptor : public Descriptor
{
private:
    const int doNotScramble;
    const int controlRemoteAccessOverInternet;
    const int doNotApplyRevocation;

public:
    FTAContentManagementDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getDoNotScramble();
    int getControlRemoteAccessOverInternet();
    int getDoNotApplyRevocation();
};

#endif // FTACONTENTMANAGEMENTDESCRIPTOR_H
