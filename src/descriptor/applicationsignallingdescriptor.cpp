/*
 *Original Author:	shko
 */


#include <applicationsignallingdescriptor.h>


ApplicationSignallingDescriptor::ApplicationType::ApplicationType(const int reserved1, const int applicationType, const int reserved2, const int versionNumber)
    : reserved1(reserved1),
      applicationType(applicationType),
      reserved2(reserved2),
      aitVersionNumber(versionNumber)
{
    ;
}

ApplicationSignallingDescriptor::ApplicationType::~ApplicationType()
{
    ;
}

int ApplicationSignallingDescriptor::ApplicationType::getApplicationType()
{
    return applicationType;
}

int ApplicationSignallingDescriptor::ApplicationType::getAitVersionNumber()
{
    return aitVersionNumber;
}

ApplicationSignallingDescriptor::ApplicationSignallingDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
{

    int t = 0;
    while (t < descriptorLength)
    {
        const int reserved1 = Utils::getInt(buffer, offset + 2 + t, 1, MASK_4BITS_UP) >> 3;
        const int application_type = Utils::getInt(buffer, offset + 2 + t, 2, MASK_15BITS);
        const int reserved2 = Utils::getInt(buffer, offset + 4 + t, 1, MASK_4BITS_UP) >> 5;
        const int ait_version = Utils::getInt(buffer, offset + 4 + t, 1, MASK_5BITS);

        ApplicationType* application = new ApplicationType(reserved1, application_type, reserved2, ait_version);
        applicationTypeVector.push_back(application);
        t += 3;
    }
}

ApplicationSignallingDescriptor::~ApplicationSignallingDescriptor()
{
    for(ApplicationTypeIterator i = applicationTypeVector.begin(); i != applicationTypeVector.end(); ++i)
        delete *i;
}

std::vector<ApplicationSignallingDescriptor::ApplicationType*>* ApplicationSignallingDescriptor::getApplicationTypeVector()
{
    return &applicationTypeVector;
}
