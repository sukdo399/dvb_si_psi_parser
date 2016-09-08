/*
 *Original Author:	shko
 */

#ifndef EXTENDEDEVENTDESCRIPTOR_H
#define EXTENDEDEVENTDESCRIPTOR_H

#include "descriptor.h"

class ExtendedEventDescriptor : public Descriptor
{

public:
    class Item
    {
    private:
        const std::string itemDescription;
        const std::string item;


    public:
        Item(const std::string itemDescription, const std::string item);
        virtual ~Item(void);

        std::string getItemDescription();
        std::string getItem();

    };

private:
    const int descriptorNumber;
    const int lastDescriptorNumber;
    const std::string iso639LanguageCode;
    const int lengthOfItems;
    std::vector<Item*> itemVector; // TODO: const
    const int textlength;
    const std::string text;

public:
    ExtendedEventDescriptor(const char* buffer, const int offset, const TableSection* parent);
    virtual ~ExtendedEventDescriptor(void);

    int getDescriptorNumber();
    int getLastDescriptorNumber();
    std::string getIso639LanguageCode();
    int getLengthOfItems();
    std::vector<Item*>* getItemVector();
#if 0//for debugging. use text.length() to get textLength.
    int getTextLength();
#endif
    std::string getText();

};

// TODO: change naming...
typedef std::vector<ExtendedEventDescriptor::Item *> ItemVector;
typedef ItemVector::iterator ItemIterator;
typedef ItemVector::const_iterator ItemConstIterator;

#endif // EXTENDEDEVENTDESCRIPTOR_H
