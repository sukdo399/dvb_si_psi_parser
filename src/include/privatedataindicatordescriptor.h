/*
 *Original Author:	shko
 */


#ifndef PRIVATEDATAINDICATORDESCRIPTOR_H
#define PRIVATEDATAINDICATORDESCRIPTOR_H

#include "descriptor.h"

class PrivateDataIndicatorDescriptor : public Descriptor
{


private:
    const int privateDataIndicator;

public:
    PrivateDataIndicatorDescriptor(const char* buffer, const int offset, const TableSection* parent);


    int getPrivateDataIndicator();

};


#endif // PRIVATEDATAINDICATORDESCRIPTOR_H
