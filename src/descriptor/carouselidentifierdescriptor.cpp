/*
 *Original Author:	shko
 */

#include <carouselidentifierdescriptor.h>


CarouselIdentifierDescriptor::CarouselIdentifierDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      carouselId(Utils::getInt(buffer, offset + 2, 4, MASK_32BITS)),
      formatId(Utils::getInt(buffer, offset + 6, 1, MASK_8BITS))
{
    int t = offset + 7;

    if (formatId == 0x00)
    {
        moduleVersion = 0;
        moduleId = 0;
        blockSize = 0;
        moduleSize = 0;
        compressionMethod = 0;
        originalSize = 0;
        timeOut = 0;
        objectKeyLength = 0;
        objectKeyData.clear();


        privateDataByte.resize(descriptorLength - ((t-offset) - 2));
        memcpy(&privateDataByte[0], buffer + t, descriptorLength - ((t-offset) - 2));
    }
    if (formatId == 0x01)
    {
        moduleVersion = Utils::getInt(buffer, t, 1, MASK_8BITS);
        moduleId = Utils::getInt(buffer, t + 1, 2, MASK_16BITS);
        blockSize = Utils::getInt(buffer, t + 3, 2, MASK_16BITS);
        moduleSize = Utils::getInt(buffer, t + 5, 4, MASK_32BITS);
        compressionMethod = Utils::getInt(buffer, t + 9, 1, MASK_8BITS);
        originalSize = Utils::getInt(buffer, t + 10, 4, MASK_32BITS);
        timeOut = Utils::getInt(buffer, t + 14, 1, MASK_8BITS);
        objectKeyLength = Utils::getInt(buffer, t + 15, 1, MASK_8BITS);

        objectKeyData.resize(objectKeyLength);
        memcpy(&objectKeyData[0], buffer + t + 16, objectKeyLength);

        t = t + 16 + objectKeyLength;

        privateDataByte.resize(descriptorLength - ((t-offset)-2));
        memcpy(&privateDataByte[0], buffer + t, descriptorLength - ((t-offset)-2));
    }

}



int CarouselIdentifierDescriptor::getCarouselId()
{
    return carouselId;
}

int CarouselIdentifierDescriptor::getFormatId()
{
    return formatId;
}

int CarouselIdentifierDescriptor::getModuleVersion()
{
    return moduleVersion;
}

int CarouselIdentifierDescriptor::getModuleId()
{
    return moduleId;
}

int CarouselIdentifierDescriptor::getBlockSize()
{
    return blockSize;
}

int CarouselIdentifierDescriptor::getModuleSize()
{
    return moduleSize;
}

int CarouselIdentifierDescriptor::getCompressionMethod()
{
    return compressionMethod;
}

int CarouselIdentifierDescriptor::getOriginalSize()
{
    return originalSize;
}

int CarouselIdentifierDescriptor::getTimeOut()
{
    return timeOut;
}

int CarouselIdentifierDescriptor::getObjectKeyLength()
{
    return objectKeyLength;
}

const CharVector* CarouselIdentifierDescriptor::getObjectKeyData()
{
    return &objectKeyData;
}

const CharVector* CarouselIdentifierDescriptor::getPrivateDataByte()
{
    return &privateDataByte;
}


std::string CarouselIdentifierDescriptor::getFormatIDString(const int formatID)
{
    switch (formatID)
    {
        case 0x00 :
            return "standard boot";
        case 0x01 :
            return "enhanced boot";
        default:
            return "unknown value";
    }
}
