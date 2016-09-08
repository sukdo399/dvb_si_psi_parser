/*
 *Original Author:	shko
 */

#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include <common.h>
#include <tablesection.h>
#include <descriptortag.h>

class Descriptor
{
protected:

    const int descriptorTag;
    const int descriptorLength;

    CharVector privateDataByte;
    int privateDataByteOffset;

    const TableSection* parentTableSection;

public:
    Descriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~Descriptor(void);

    int getDescriptorLength();
    int getDescriptorTag();

    const CharVector* getPrivateDataByte();

    /// should be overrid when private descriptors used
    std::string getDescriptorname();
    static std::string getDescriptorname(const int tag);


};

// use map or hash if necessary
typedef std::vector<Descriptor *> DescriptorVector;
typedef DescriptorVector::iterator DescriptorIterator;
typedef DescriptorVector::const_iterator DescriptorConstIterator;


#endif // DESCRIPTOR_H
