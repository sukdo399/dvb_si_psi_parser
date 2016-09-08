/*
 *Original Author:	shko
 */

#include <registrationdescriptor.h>

RegistrationDescriptor::RegistrationDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
{
    formatIdentifier.resize(4);
    memcpy(&formatIdentifier[0], buffer + offset + 2, 4);

    additionalIdentificationInfo.resize(descriptorLength - (6 - 2));
    memcpy(&additionalIdentificationInfo[0], buffer + offset + 6, descriptorLength - (6 - 2));

}


const CharVector* RegistrationDescriptor::getFormatIdentifier()
{
    return &formatIdentifier;
}

const CharVector* RegistrationDescriptor::getAdditionalIdentificationInfo()
{
    return &additionalIdentificationInfo;
}
