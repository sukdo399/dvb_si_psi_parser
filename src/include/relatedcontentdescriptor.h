/*
 *Original Author:	shko
 */

#ifndef RELATEDCONTENTDESCRIPTOR_H
#define RELATEDCONTENTDESCRIPTOR_H

#include "descriptor.h"

class RelatedContentDescriptor : public Descriptor
{

public:
    RelatedContentDescriptor(const char* buffer, const int offset, const TableSection* parent);

};


#endif // RELATEDCONTENTDESCRIPTOR_H
