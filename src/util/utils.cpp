/*
 *Original Author:	shko
 */

#include "utils.h"

#ifdef DEFINE_DO_NOT_USE_C11
#include "stdio.h"
#include "stdarg.h"
#endif

#include <iostream>
Utils::Utils()
{
    // private because there is no reason for instantion
}


int Utils::getUnsignedByte(const char b)
{
    if (b >= 0)
    {
        return b;
    }
    return b + 256;
}

char Utils::getInt2UnsignedByte(const int b)
{
    if (b <= 127)
    {
        return static_cast<char>(b);
    }
    return static_cast<char>(b - 256);
}

int Utils::getInt(const char* bytes, const int offset, const int len, const int mask)
{
    int r = 0;
    for (int i = 0; i < len; i++)
    {
        r = (r << 8) | getUnsignedByte(bytes[offset + i]);
    }
    return (r&mask);
}

long long Utils::getLong(const char* bytes, const int offset, const int len, long long const mask)
{
    long long r = 0;
    for (int i = 0; i < len; i++)
    {
        r = (r << 8) | getUnsignedByte(bytes[offset + i]);
    }
    return (r&mask);
}

int Utils::getBit(const char b, const int i)
{
    return ((b & (0x80 >> (i - 1))));
}

int Utils::getBits(const char b, const int i, const int len)
{
    int mask = 0x00;

    for (int pos = i; pos < (i + len); ++pos)
    {
        mask |= 0x80 >> (pos - 1);
    }

    return (b & mask) >> (9 - i - len);
}

#if 0
char *Utils::getBytes(const char* b, const int offset, const int len)
{
    if (len == 0)
    {
        return new char[0];
    }
    return Utils::copyOfRange(b, offset, offset + len);
}

char *Utils::copyOfRange(const char* original, const int from, const int to)
{
    const int newLength = to - from;
    if (newLength < 0)
    {
        throw IllegalArgumentException(from + std::wstring(L" > ") + to);
    }
    const char copy[newLength];
    System::arraycopy(original, from, copy, 0, std::min(sizeof(original) / sizeof(original[0]) - from, newLength));
    return copy;
}
#endif

std::string Utils::getStreamTypeString(const int tag)
{
    if ((0x22 <= tag) && (tag <= 0x7e))
    {
        return "ITU-T Rec. H.222.0 | ISO/IEC 13818-1 Reserved";
    }

    if ((0x80 <= tag) && (tag <= 0xFF))
    {
        return "User Private";
    }

    switch (tag)
    {
    case 0x00:
        return "ITU-T | ISO/IEC Reserved";
    case 0x01:
        return "ISO/IEC 11172 Video";
    case 0x02:
        return "ITU-T Rec. H.262 | ISO/IEC 13818-2 Video or ISO/IEC 11172-2 constrained parameter video stream";
    case 0x03:
        return "ISO/IEC 11172 Audio";
    case 0x04:
        return "ISO/IEC 13818-3 Audio";
    case 0x05:
        return "ITU-T Rec. H.222.0 | ISO/IEC 13818-1 private_sections";
    case 0x06:
        return "ITU-T Rec. H.222.0 | ISO/IEC 13818-1 PES packets containing private data";
    case 0x07:
        return "ISO/IEC 13522 MHEG";
    case 0x08:
        return "ITU-T Rec. H.222.0 | ISO/IEC 13818-1 Annex A DSM-CC";
    case 0x09:
        return "ITU-T Rec. H.222.1";
    case 0x0A:
        return "ISO/IEC 13818-6 type A";
    case 0x0B:
        return "ISO/IEC 13818-6 type B";
    case 0x0C:
        return "ISO/IEC 13818-6 type C";
    case 0x0D:
        return "ISO/IEC 13818-6 type D";
    case 0x0E:
        return "ITU-T Rec. H.222.0 | ISO/IEC 13818-1 auxiliary";
    case 0x0F:
        return "ISO/IEC 13818-7 Audio with ADTS transport syntax";
    case 0x10:
        return "ISO/IEC 14496-2 Visual";
    case 0x11:
        return "ISO/IEC 14496-3 Audio with the LATM transport syntax as defined in ISO/IEC 14496-3 / AMD 1";
    case 0x12:
        return "ISO/IEC 14496-1 SL-packetized stream or FlexMux stream carried in PES packets";
    case 0x13:
        return "ISO/IEC 14496-1 SL-packetized stream or FlexMux stream carried in ISO/IEC14496_sections.";
    case 0x14:
        return "ISO/IEC 13818-6 Synchronized Download Protocol";

    // 29n9184t.doc Text of ISO/IEC 13818-1:2007/FPDAM 3.2 - Transport of Scalable Video over ITU-T Rec H.222.0 | ISO/IEC 13818-1
    // Amendment 3: Transport of Scalable Video over ITU-T Rec H.222.0 | ISO/IEC 13818-1
    // ISO/IEC 13818-1:2007/FPDAM 3.2
    // Amendment 5: Transport of JPEG 2000 Part 1 (ITU-T Rec T.800 | ISO/IEC 15444-1) video over ITU-T Rec H.222.0 | ISO/IEC 13818-1

    case 0x15:
        return "Metadata carried in PES packets";
    case 0x16:
        return "Metadata carried in metadata_sections";
    case 0x17:
        return "Metadata carried in ISO/IEC 13818-6 Data Carousel";
    case 0x18:
        return "Metadata carried in ISO/IEC 13818-6 Object Carousel";
    case 0x19:
        return "Metadata carried in ISO/IEC 13818-6 Synchronized Download Protocol";
    case 0x1A:
        return "IPMP stream (defined in ISO/IEC 13818-11, MPEG-2 IPMP)";
    case 0x1B:
        return "AVC video stream as defined in ITU-T Rec. H.264 | ISO/IEC 14496-10 Video";
    case 0x1C:
        return "ISO/IEC 14496-3 Audio, without using any additional transport syntax, such as DST, ALS and SLS";
    case 0x1D:
        return "ISO/IEC 14496-17 Text";
    case 0x1E:
        return "Auxiliary video stream as defined in ISO/IEC 23002-3";
    case 0x1F:
        return "SVC video sub-bitstream of a video stream as defined in the Annex G of ITU-T Rec. H.264 | ISO/IEC 14496-10 Video";

    case 0x20:
        return "MVC video sub-bitstream of an AVC video stream conforming to one or more profiles defined in Annex H of ITU-T Rec. H.264 | ISO/IEC 14496-10";
    case 0x21:
        return "J2K Video stream conforming to one or more profiles as defined in ITU-T Rec T.800 | ISO/IEC 15444-1";
    case 0x22:
        return "Additional view Rec. ITU-T H.262 | ISO/IEC 13818-2 video stream for service-compatible stereoscopic 3D services";
    case 0x23:
        return "Additional view Rec. ITU-T H.264 | ISO/IEC 14496-10 video stream conforming to one or more profiles defined in Annex A for service-compatible stereoscopic 3D services";
    case 0x7f:
        return "IPMP stream";

    default:
        return "illegal/unknown value";
    }
}


static unsigned int GetDigit(const char* ptrFormat, int &nIdx, int nFmtLen)
{
    if ((ptrFormat == NULL) || (nIdx >= nFmtLen))
    {
        return 0;
    }

    std::ostringstream oDigit;

    while (isdigit(ptrFormat[nIdx]) > 0)
    {
        oDigit << ptrFormat[nIdx];
        nIdx++;

        if ( nIdx >= nFmtLen )
        {
            break;
        }
    }

    return atoi (oDigit.str().c_str());
}

std::string::size_type Utils::strPrintf(std::string& rstr, const char *pFmt, ... )
{
    bool bFMT = false;
    int nExpChars = 0, nIdx = 0, nFmtLen = strlen(pFmt);

    if (nFmtLen <= 0)
    {
        return 0;
    }

    va_list arg;
    va_start(arg, pFmt);


    while(pFmt[nIdx])
    {
        switch (pFmt[nIdx])
        {
            case 's':
                if(bFMT)
                {
                    nExpChars += strlen((char*)va_arg(arg, char*));
                    bFMT = false;
                }
                break;
            case 'f':	// Decimal floating point
            case 'd':	// Signed decimal integer
            case 'i':	// Signed decimal integer
            case 'g':	// Use shorter %e or %f
            case 'G':	// Use shorter %E or %F
            case 'o':	// Signed octal
            case 'x':	// Unsigned hexadecimal integer
            case 'X':	// Unsigned hexadecimal integer (capital letters)
            case 'p':	// Prints the address of the argument in hexadecimal digits.
                nExpChars += 16;
                bFMT = false;
                break;

            case 'c': 	// char
                nExpChars++;
                bFMT = false;
                break;

            case '.':
                nIdx++;
                nExpChars += GetDigit (pFmt, nIdx, nFmtLen);
                nIdx--;
                break;

            case '%':
                if (nIdx > 0)
                {
                    bFMT = (pFmt[nIdx-1] == '%') ? false : true;
                }
                else
                {
                    bFMT = true;
                }

                nIdx++;
                nExpChars += GetDigit(pFmt, nIdx, nFmtLen);
                nIdx--;
                break;

            default:
                nExpChars++;
        }

        nIdx++;
        if(nIdx < 0 || nIdx >= nFmtLen)
        {
            break;
        }
    }

    va_end (arg);

    rstr.resize(nExpChars, ' ');

    va_start(arg, pFmt);

    int nPrnChars = vsprintf((char*)rstr.c_str(), pFmt, arg);

    if (nPrnChars >= 0 && nPrnChars <= nExpChars)
    {
        rstr.erase(nPrnChars);
    }

    va_end(arg);
    return rstr.length();
}

#if 0
std::string Utils::getBCD(const char* buffer, const int nibble_no, const int length)
{
    std::string strRet;

    for (int i = 0; i < length; i++)
    {
        const int byteNo = (nibble_no + i) / 2;
        const bool shift = ((nibble_no + i) % 2) == 0;
        int t;
        if (shift)
        {
            t = (Utils::getUnsignedByte(buffer[byteNo]) & 0xF0) >> 4;
        }
        else
        {
            t = (Utils::getUnsignedByte(buffer[byteNo]) & 0x0F);
        }
        if (t > 9)
        {
            return "Error parsing BCD";
        }
        std::cout << "test t: " << t << std::endl;
        // TODO: it not correct...
        (void)Utils::strPrintf(strRet, "%s%d", strRet.c_str(), t);
    }

    return strRet;
}
#endif

long int Utils::getBcdInt(long int val)
{
    long int retVal, index;
    long int i;

    retVal	= 0;
    index		= 1;

    for (i = 0; i < 8; i++)
    {
        retVal += (val & 0x0f) * index;
        val  = val >> 4;
        index *= 10;
    }

    return (retVal);
}
