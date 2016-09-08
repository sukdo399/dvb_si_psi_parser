/*
 *Original Author:	shko
 */

#ifndef CAROUSELIDENTIFIERDESCRIPTOR_H
#define CAROUSELIDENTIFIERDESCRIPTOR_H

#include "descriptor.h"

class CarouselIdentifierDescriptor : public Descriptor
{

private:
    const int carouselId;
    const int formatId;

    int moduleVersion;
    int moduleId;
    int blockSize;
    int moduleSize;
    int compressionMethod;
    int originalSize;
    int timeOut;
    int objectKeyLength;
    CharVector objectKeyData;

    CharVector privateDataByte;

public:
    CarouselIdentifierDescriptor(const char* buffer, const int offset, const TableSection* parent);

    int getCarouselId();
    int getFormatId();

    int getModuleVersion();
    int getModuleId();
    int getBlockSize();
    int getModuleSize();
    int getCompressionMethod();
    int getOriginalSize();
    int getTimeOut();
    int getObjectKeyLength();
    const CharVector* getObjectKeyData();

    const CharVector* getPrivateDataByte();

    static std::string getFormatIDString(const int formatID);


};

#endif // CAROUSELIDENTIFIERDESCRIPTOR_H
