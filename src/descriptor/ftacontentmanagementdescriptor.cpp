/*
 *Original Author:	shko
 */

#include <ftacontentmanagementdescriptor.h>


FTAContentManagementDescriptor::FTAContentManagementDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      doNotScramble(Utils::getInt(buffer, offset + 2, 1, MASK_4BITS) >> 3),
      controlRemoteAccessOverInternet(Utils::getInt(buffer, offset + 2 , 1, 0x06) >> 1),
      doNotApplyRevocation(Utils::getInt(buffer, offset + 2 , 1, MASK_1BIT))
{
    ;
}

int FTAContentManagementDescriptor::getDoNotScramble()
{
    return doNotScramble;
}

int FTAContentManagementDescriptor::getControlRemoteAccessOverInternet()
{
    return controlRemoteAccessOverInternet;
}

int FTAContentManagementDescriptor::getDoNotApplyRevocation()
{
    return doNotApplyRevocation;
}
