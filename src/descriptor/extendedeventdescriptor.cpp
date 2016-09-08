/*
 *Original Author:	shko
 */

#include <extendedeventdescriptor.h>

ExtendedEventDescriptor::Item::Item(const std::string itemDescription, const std::string item)
    : itemDescription(std::string(itemDescription))
    , item(std::string(item))
{
    ;
}


ExtendedEventDescriptor::Item::~Item(void)
{
    ;
}

std::string ExtendedEventDescriptor::Item::getItemDescription()
{
    return itemDescription;
}

std::string ExtendedEventDescriptor::Item::getItem()
{
    return item;
}


ExtendedEventDescriptor::ExtendedEventDescriptor(const char* buffer, int const offset, const TableSection* parent)
    : Descriptor(buffer, offset,parent)
    , descriptorNumber(Utils::getInt(buffer, offset + 2, 1, MASK_4BITS_UP) >> 4)
    , lastDescriptorNumber(Utils::getInt(buffer, offset + 2, 1, MASK_4BITS))
    , iso639LanguageCode(std::string((char *)&buffer[offset + 3], 3))
    , lengthOfItems(Utils::getInt(buffer, offset + 6, 1, MASK_8BITS))
    , textlength(Utils::getInt(buffer, offset + 7 + lengthOfItems, 1, MASK_8BITS))
    , text(std::string((char *)&buffer[offset + 7 + lengthOfItems + 1], textlength))

{
    int t = offset + 7;
    while (t < (lengthOfItems + offset + 7))
    {
        const int item_description_length = Utils::getInt(buffer, t, 1, MASK_8BITS);
        const std::string item_descripton = std::string((char *)&buffer[t+1], item_description_length);
        const int item_length = Utils::getInt(buffer, t + 1 + item_description_length, 1, MASK_8BITS);
        const std::string item = std::string((char *)&buffer[t + 1 + item_description_length + 1], item_length);

        Item* i = new Item(item_descripton,item); // TODO: const
        itemVector.push_back(i);

        t += 2 + item_description_length + item_length;
    }


}

ExtendedEventDescriptor::~ExtendedEventDescriptor(void)
{
    for(ItemIterator i = itemVector.begin(); i != itemVector.end(); ++i)
        delete *i;
}

std::string ExtendedEventDescriptor::getIso639LanguageCode()
{
    return iso639LanguageCode;
}


int ExtendedEventDescriptor::getDescriptorNumber()
{
    return descriptorNumber;
}

int ExtendedEventDescriptor::getLastDescriptorNumber()
{
    return lastDescriptorNumber;
}

int ExtendedEventDescriptor::getLengthOfItems()
{
    return lengthOfItems;
}

std::vector<ExtendedEventDescriptor::Item*>* ExtendedEventDescriptor::getItemVector()
{
    return &itemVector;
}

#if 0//for debugging. use text.length() to get textLength.
int ExtendedEventDescriptor::getTextLength()
{
    return textlength;
}
#endif

std::string ExtendedEventDescriptor::getText()
{
    return text;
}
