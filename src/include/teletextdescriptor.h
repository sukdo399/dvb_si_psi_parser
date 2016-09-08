/*
 *Original Author:	shko
 */

#ifndef TELETEXTDESCRIPTOR_H
#define TELETEXTDESCRIPTOR_H

#include "descriptor.h"

class TeletextDescriptor : public Descriptor
{
public:
    class Teletext
    {

    private:
        const std::string iso639LanguageCode;
        const int teletextType;
        const int teletextMagazineNumber;
        const int teletextPageNumber;


    public:
        Teletext(const std::string &lCode, const int tType, const int tMagazine, const int tPage);
        virtual ~Teletext(void);

        std::string getIso639LanguageCode();
        int getTeletextType();
        int getTeletextMagazineNumber();
        int getTeletextPageNumber();

    };


private:
    std::vector<Teletext*> teletextVector;


public:
    TeletextDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~TeletextDescriptor(void);

    std::vector<Teletext*>* getTeletextVector();

    static std::string getTeletextTypeString(const int type);

};

typedef std::vector<TeletextDescriptor::Teletext *> TeletextVector;
typedef TeletextVector::iterator TeletextIterator;
typedef TeletextVector::const_iterator TeletextConstIterator;

#endif // TELETEXTDESCRIPTOR_H
