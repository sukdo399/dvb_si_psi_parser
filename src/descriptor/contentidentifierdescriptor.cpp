/*
 *Original Author:	shko
 */

#include <contentidentifierdescriptor.h>


ContentIdentifierDescriptor::Crid::Crid(const int cridType, const int cridLocation, const int cridLength, CharVector cridByte, const int cridRef)
    : cridType(cridType),
      cridLocation(cridLocation),
      cridLength(cridLength),
      cridByte(cridByte),
      cridRef(cridRef)
{
    ;
}

ContentIdentifierDescriptor::Crid::~Crid()
{
    ;
}

int ContentIdentifierDescriptor::Crid::getCridType()
{
    return cridType;
}

int ContentIdentifierDescriptor::Crid::getCridLocation()
{
    return cridLocation;
}

int ContentIdentifierDescriptor::Crid::getCridLength()
{
    return cridLength;
}

const CharVector* ContentIdentifierDescriptor::Crid::getCridByte()
{
    return &cridByte;
}

int ContentIdentifierDescriptor::Crid::getCridRef()
{
    return cridRef;
}

ContentIdentifierDescriptor::ContentIdentifierDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent)
{

    int t = 0;

    while (t < descriptorLength)
    {
        const int type = Utils::getInt(buffer, offset + 2 + t, 1, 0xFC) >> 2;
        const int location = Utils::getInt(buffer, offset + 2 + t, 1, MASK_2BITS);
        int crid_len = 0;
        CharVector cridByte;
        int cridRef = 0;

        cridByte.clear();

        if (location == 0)
        {
            crid_len = Utils::getInt(buffer, offset + 3 + t, 1, MASK_8BITS);

            cridByte.resize(crid_len);
            memcpy(&cridByte[0], buffer + offset + 4 + t, crid_len);
            t += 2 + crid_len;
        }
        else if (location == 1)
        {
            cridRef = Utils::getInt(buffer, offset + 3 + t, 2, MASK_16BITS);
            t += 3;
        }
        else
        {
            t += 2;
        }

        Crid* crid = new Crid(type, location, crid_len, cridByte, cridRef);
        cridVector.push_back(crid);

    }
}

ContentIdentifierDescriptor::~ContentIdentifierDescriptor()
{
    for(CridIterator i = cridVector.begin(); i != cridVector.end(); ++i)
        delete *i;
}

std::vector<ContentIdentifierDescriptor::Crid*>* ContentIdentifierDescriptor::getCridVector()
{
    return &cridVector;
}

std::string ContentIdentifierDescriptor::getCridTypeString(const int type)
{
    switch (type)
    {
        case 0x00 :
            return "No type defined";
        case 0x01 :
            return "CRID references the item of content that this event is an instance of.";
        case 0x02 :
            return "CRID references a series that this event belongs to.";
        case 0x03 :
            return "CRID references a recommendation. This CRID can be a group or a single item of content.";
        default:
            if ((0x04 <= type) && (type <= 0x1F))
            {
                return "DVB reserved";
            }
            if ((0x20 <= type) && (type <= 0x3F))
            {
                return "User private";
            }
            return "Illegal value";

    }
}

std::string ContentIdentifierDescriptor::getCridLocationString(const int type)
{
    switch (type)
    {
        case 0x00 :
            return "Carried explicitly within descriptor";
        case 0x01 :
            return "Carried in Content Identifier Table (CIT)";
        case 0x02 :
            return "DVB reserved";
        case 0x03 :
            return "DVB reserved";
        default:
             return "Illegal value";
    }
}
