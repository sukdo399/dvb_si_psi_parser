/*
 *Original Author:	shko
 */

#ifndef REGISTRATIONDESCRIPTOR_H
#define REGISTRATIONDESCRIPTOR_H

#include "descriptor.h"

class RegistrationDescriptor : public Descriptor
{

private:

    CharVector formatIdentifier;
    CharVector additionalIdentificationInfo;

public:
    RegistrationDescriptor(const char* buffer, const int offset, const TableSection* parent);

    const CharVector* getFormatIdentifier();
    const CharVector* getAdditionalIdentificationInfo();
};

#endif // REGISTRATIONDESCRIPTOR_H
