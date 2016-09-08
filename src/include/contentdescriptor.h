/*
 *Original Author:	shko
 */

#ifndef CONTENTDESCRIPTOR_H
#define CONTENTDESCRIPTOR_H

#include "descriptor.h"

class ContentDescriptor : public Descriptor
{
public:
    class Content
    {

    private:
        const int contentNibbleLevel1;
        const int contentNibbleLevel2;
        const int userByte;

    public:
        Content(const int contentNibbleLevel1, const int contentNibbleLevel2, const int userByte);
        virtual ~Content(void);

        int getContentNibbleLevel1();
        int getContentNibbleLevel2();
        int getUserByte();


    };


private:
    std::vector<Content*> contentVector;


public:
    ContentDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~ContentDescriptor(void);

    std::vector<ContentDescriptor::Content*> *getContentVector();

    static std::string getContentNibbleLevel1String(const int nibble1);
    static std::string getContentNibbleLevel2String(const int nibble1, const int nibble2);

};

typedef std::vector<ContentDescriptor::Content *> ContentVector;
typedef ContentVector::iterator ContentIterator;
typedef ContentVector::const_iterator ContentConstIterator;

#endif // CONTENTDESCRIPTOR_H
