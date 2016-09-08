/*
 *Original Author:	shko
 */

#include <systemclockdescriptor.h>


SystemClockDescriptor::SystemClockDescriptor(const char *buffer, const int offset, const TableSection *parent)
    : Descriptor(buffer, offset, parent),
      externalClockReferenceIndicator(Utils::Utils::getInt(buffer,offset + 2,1,0x80) >> 7),
      reserved(Utils::getInt(buffer,offset + 2, 1, 0x40) >> 6),
      clockAccuracyInteger(Utils::getInt(buffer,offset + 2, 1, MASK_6BITS)),
      clockAccuracyExponent(Utils::getInt(buffer, offset + 3, 1, 0xE0) >> 5),
      reserved2(Utils::getInt(buffer, offset + 3, 1, MASK_5BITS))

{
    ;
}

int SystemClockDescriptor::getExternalClockReferenceIndicator()
{
  return externalClockReferenceIndicator;
}


int SystemClockDescriptor::getReserved()
{
  return reserved;
}

int SystemClockDescriptor::getClockAccuracyInteger()
{
    return clockAccuracyInteger;
}

int SystemClockDescriptor::getClockAccuracyExponent()
{
    return clockAccuracyExponent;
}

int SystemClockDescriptor::getReserved2()
{
    return reserved2;
}

