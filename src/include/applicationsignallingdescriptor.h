/*
 *Original Author:	shko
 */


#ifndef APPLICATIONSIGNALLINGDESCRIPTOR_H
#define APPLICATIONSIGNALLINGDESCRIPTOR_H

#include "descriptor.h"

class ApplicationSignallingDescriptor : public Descriptor
{
public:
    class ApplicationType
    {
    private:
        const int reserved1;
        const int applicationType;
        const int reserved2;
        const int aitVersionNumber;

    public:
        ApplicationType(const int reserved1, const int applicationType, const int reserved2, const int versionNumber);
        virtual ~ApplicationType(void);

        int getApplicationType();
        int getAitVersionNumber();
    };


private:
    std::vector<ApplicationType*> applicationTypeVector;



public:
    ApplicationSignallingDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~ApplicationSignallingDescriptor(void);

    virtual std::vector<ApplicationSignallingDescriptor::ApplicationType*>* getApplicationTypeVector();
};

typedef std::vector<ApplicationSignallingDescriptor::ApplicationType*> ApplicationTypeVector;
typedef ApplicationTypeVector::iterator ApplicationTypeIterator;
typedef ApplicationTypeVector::const_iterator ApplicationTypeConstIterator;

#endif // APPLICATIONSIGNALLINGDESCRIPTOR_H
