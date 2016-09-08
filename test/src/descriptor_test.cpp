/*
 *Original Author:	shko
 */

#include "descriptor_test.h"
#include <gtest.h>

//#include <iostream>


/* subtitlingDescriptor */
TEST(DescriptorTest, Subtitiling)
{

    SubtitlingDescriptor *descriptor = new SubtitlingDescriptor((char *) subtitlingDescriptor1, 0, nullptr);
    const SubtitleVector *subtitleVector = descriptor->getSubtitleVector();
    SubtitleConstIterator subtitle = subtitleVector->begin();

    // 1st.
    std::string lancode = (*subtitle)->getIso639LanguageCode();
    int subtitleType = (*subtitle)->getSubtitlingType();
    int compositionPageId = (*subtitle)->getCompositionPageId();
    int ancillaryPageId = (*subtitle)->getAncillaryPageId();
    EXPECT_STREQ(eng.c_str(), lancode.c_str());
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 5, 1, MASK_8BITS), subtitleType);
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 6, 2, MASK_16BITS), compositionPageId);
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 8, 2, MASK_16BITS), ancillaryPageId);


    // 2nd.
    subtitle++;
    lancode = (*subtitle)->getIso639LanguageCode();
    subtitleType = (*subtitle)->getSubtitlingType();
    compositionPageId = (*subtitle)->getCompositionPageId();
    ancillaryPageId = (*subtitle)->getAncillaryPageId();
    EXPECT_STREQ(fra.c_str(), lancode.c_str());
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 13, 1, MASK_8BITS), subtitleType);
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 14, 2, MASK_16BITS), compositionPageId);
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 16, 2, MASK_16BITS), ancillaryPageId);


    // 3rd
    subtitle++;
    lancode = (*subtitle)->getIso639LanguageCode();
    subtitleType = (*subtitle)->getSubtitlingType();
    compositionPageId = (*subtitle)->getCompositionPageId();
    ancillaryPageId = (*subtitle)->getAncillaryPageId();
    EXPECT_STREQ(deu.c_str(), lancode.c_str());
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 21, 1, MASK_8BITS), subtitleType);
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 22, 2, MASK_16BITS), compositionPageId);
    EXPECT_EQ(Utils::getInt(&subtitlingDescriptor1[0], 24, 2, MASK_16BITS), ancillaryPageId);

    // end
    subtitle++;
    EXPECT_EQ(subtitleVector->end(), subtitle);

    delete(descriptor);

}


/* networkNameDescriptor */
TEST(DescriptorTest, NetworkName)
{
    NetworkNameDescriptor *descriptor = new NetworkNameDescriptor((char *) networkNameDescriptor1, 0, nullptr);
    std::string networkName = descriptor->getNetworkName();
    EXPECT_STREQ(stringTest.c_str(), networkName.c_str());
    delete descriptor;

    descriptor = new NetworkNameDescriptor((char *) networkNameDescriptor2, 0, nullptr);
    networkName = descriptor->getNetworkName();
    EXPECT_EQ(0x00, networkName.length());
    delete descriptor;

}


/* serviceListDescriptor */
TEST(DescriptorTest, ServiceList)
{
//serviceListDescriptor1
    ServiceListDescriptor *descriptor = new ServiceListDescriptor((char *) serviceListDescriptor1, 0, nullptr);
    const ServiceVector *serviceVector = descriptor->getServiceVector();
    ServiceConstIterator iter = serviceVector->begin();

    // 1st
    int serviceId = (*iter)->getServiceID();
    int serviceType = (*iter)->getServiceType();
    EXPECT_EQ(Utils::getInt(&serviceListDescriptor1[0], 2, 2, MASK_16BITS), serviceId);
    EXPECT_EQ(Utils::getInt(&serviceListDescriptor1[0], 4, 1, MASK_8BITS), serviceType);

    //2nd
    iter++;
    serviceId = (*iter)->getServiceID();
    serviceType = (*iter)->getServiceType();
    EXPECT_EQ(Utils::getInt(&serviceListDescriptor1[0], 5, 2, MASK_16BITS), serviceId);
    EXPECT_EQ(Utils::getInt(&serviceListDescriptor1[0], 7, 1, MASK_8BITS), serviceType);

    //3rd
    iter++;
    serviceId = (*iter)->getServiceID();
    serviceType = (*iter)->getServiceType();
    EXPECT_EQ(Utils::getInt(&serviceListDescriptor1[0], 8, 2, MASK_16BITS), serviceId);
    EXPECT_EQ(Utils::getInt(&serviceListDescriptor1[0], 10, 1, MASK_8BITS), serviceType);

    //end
    iter++;
    EXPECT_EQ(serviceVector->end(), iter);
    delete descriptor;


}

/* serviceListDescriptor */
TEST(DescriptorTest, ServiceList2)
{
//serviceListDescriptor2
    ServiceListDescriptor *descriptor2 = new ServiceListDescriptor((char *) serviceListDescriptor2, 0, nullptr);
    const ServiceVector *serviceVector2 = descriptor2->getServiceVector();
    ServiceConstIterator iter2 = serviceVector2->begin();
    EXPECT_EQ(serviceVector2->end(), iter2);
    delete descriptor2;
}

/* serviceDescriptor */
TEST(DescriptorTest, Service)
{
    //serviceDescriptor1
    ServiceDescriptor *descriptor1 = new ServiceDescriptor((char *) serviceDescriptor1, 0, nullptr);
    int serviceType1 = descriptor1->getServiceType();
    std::string providerName1 = descriptor1->getServiceProviderName();
    std::string serviceName1 = descriptor1->getServiceName();
    EXPECT_EQ(Utils::getInt(&serviceDescriptor1[0], 2, 1, MASK_8BITS), serviceType1);
    EXPECT_STREQ(stringTest.c_str(), providerName1.c_str());
    EXPECT_STREQ(stringTest.c_str(), serviceName1.c_str());
    delete descriptor1;

    //serviceDescriptor2
    ServiceDescriptor *descriptor2 = new ServiceDescriptor((char *) serviceDescriptor2, 0, nullptr);
    int serviceType2 = descriptor2->getServiceType();
    std::string providerName2 = descriptor2->getServiceProviderName();
    std::string serviceName2 = descriptor2->getServiceName();
    EXPECT_EQ(Utils::getInt(&serviceDescriptor2[0], 2, 1, MASK_8BITS), serviceType2);
    EXPECT_EQ(Utils::getInt(&serviceDescriptor2[0], 3, 1, MASK_8BITS), providerName2.length());
    EXPECT_STREQ(stringTest.c_str(), serviceName2.c_str());
    delete descriptor2;

    //serviceDescriptor3
    ServiceDescriptor *descriptor3 = new ServiceDescriptor((char *) serviceDescriptor3, 0, nullptr);
    int serviceType3 = descriptor3->getServiceType();
    std::string providerName3 = descriptor3->getServiceProviderName();
    std::string serviceName3 = descriptor3->getServiceName();
    EXPECT_EQ(Utils::getInt(&serviceDescriptor3[0], 2, 1, MASK_8BITS), serviceType3);
    EXPECT_STREQ(stringTest.c_str(), providerName3.c_str());
    EXPECT_EQ(Utils::getInt(&serviceDescriptor3[0], 4+providerName3.length(), 1, MASK_8BITS), serviceName3.length());
    delete descriptor3;

    //serviceDescriptor4
    ServiceDescriptor *descriptor4 = new ServiceDescriptor((char *) serviceDescriptor4, 0, nullptr);
    int serviceType4 = descriptor4->getServiceType();
    std::string providerName4 = descriptor4->getServiceProviderName();
    std::string serviceName4 = descriptor4->getServiceName();
    EXPECT_EQ(Utils::getInt(&serviceDescriptor4[0], 2, 1, MASK_8BITS), serviceType4);
    EXPECT_EQ(Utils::getInt(&serviceDescriptor4[0], 3, 1, MASK_8BITS), providerName4.length());
    EXPECT_EQ(Utils::getInt(&serviceDescriptor4[0], 4+providerName4.length(), 1, MASK_8BITS), serviceName4.length());
    delete descriptor4;

}


/* shortEventDescriptor */
TEST(DescriptorTest, ShortEvent)
{
    // shortEventDescriptor1
    ShortEventDescriptor *descriptor1 = new ShortEventDescriptor((char *) shortEventDescriptor1, 0, nullptr);
    std::string lancode1 = descriptor1->getIso639LanguageCode();
    std::string eventName1 = descriptor1->getEventName();
    std::string text1 = descriptor1->getText();
    EXPECT_STREQ(eng.c_str(), lancode1.c_str());
    EXPECT_STREQ(stringTest.c_str(), eventName1.c_str());
    EXPECT_STREQ(stringTest.c_str(), text1.c_str());
    delete descriptor1;

}

/* shortEventDescriptor */
TEST(DescriptorTest, ShortEvent2)
{
    // shortEventDescriptor2
    ShortEventDescriptor *descriptor2 = new ShortEventDescriptor((char *) shortEventDescriptor2, 0, nullptr);
    std::string lancode2 = descriptor2->getIso639LanguageCode();
    std::string eventName2 = descriptor2->getEventName();
    std::string text2 = descriptor2->getText();
    EXPECT_STREQ(eng.c_str(), lancode2.c_str());
    EXPECT_EQ(Utils::getInt(&shortEventDescriptor2[0], 5, 1, MASK_8BITS), eventName2.length());
    EXPECT_STREQ(stringTest.c_str(), text2.c_str());
    delete descriptor2;

}

/* shortEventDescriptor */
TEST(DescriptorTest, ShortEvent3)
{
    // shortEventDescriptor3
    ShortEventDescriptor *descriptor3 = new ShortEventDescriptor((char *) shortEventDescriptor3, 0, nullptr);
    std::string lancode3 = descriptor3->getIso639LanguageCode();
    std::string eventName3 = descriptor3->getEventName();
    std::string text3 = descriptor3->getText();
    EXPECT_STREQ(eng.c_str(), lancode3.c_str());
    EXPECT_STREQ(stringTest.c_str(), eventName3.c_str());
    EXPECT_EQ(Utils::getInt(&shortEventDescriptor3[0], 6 + eventName3.length(), 1, MASK_8BITS), text3.length());
    delete descriptor3;
}

/* shortEventDescriptor */
TEST(DescriptorTest, ShortEvent4)
{
    // shortEventDescriptor4
    ShortEventDescriptor *descriptor4 = new ShortEventDescriptor((char *) shortEventDescriptor4, 0, nullptr);
    std::string lancode4 = descriptor4->getIso639LanguageCode();
    std::string eventName4 = descriptor4->getEventName();
    std::string text4 = descriptor4->getText();
    EXPECT_STREQ(eng.c_str(), lancode4.c_str());
    EXPECT_EQ(Utils::getInt(&shortEventDescriptor4[0], 5, 1, MASK_8BITS), eventName4.length());
    EXPECT_EQ(Utils::getInt(&shortEventDescriptor4[0], 6 + eventName4.length(), 1, MASK_8BITS), text4.length());
    delete descriptor4;
}

/* extendedEventDescriptor */
TEST(DescriptorTest, ExtendedEvent)
{

// extendedEventDescriptor1
    ExtendedEventDescriptor *descriptor1 = new ExtendedEventDescriptor((char *) extendedEventDescriptor1, 0, nullptr);
    int descriptorNumber1 = descriptor1->getDescriptorNumber();
    int lastDescriptorNumber1 = descriptor1->getLastDescriptorNumber();
    std::string lang1 = descriptor1->getIso639LanguageCode();
    EXPECT_EQ((extendedEventDescriptor1[2] >> 4) & MASK_4BITS, descriptorNumber1);
    EXPECT_EQ(extendedEventDescriptor1[2] & MASK_4BITS, lastDescriptorNumber1);
    EXPECT_STREQ(eng.c_str(), lang1.c_str());
    EXPECT_EQ(extendedEventDescriptor1[6], descriptor1->getLengthOfItems());

    // 1st item.
    const ItemVector* itemVector1 = descriptor1->getItemVector();
    ItemConstIterator iter1 = itemVector1->begin();
    std::string itemDescription1 = (*iter1)->getItemDescription();
    std::string item1 = (*iter1)->getItem();
    EXPECT_STREQ(stringTest.c_str(), itemDescription1.c_str());
    EXPECT_STREQ(stringTest.c_str(), item1.c_str());

    // 2nd item
    iter1++;
    itemDescription1 = (*iter1)->getItemDescription();
    item1 = (*iter1)->getItem();
    EXPECT_STREQ(stringTest.c_str(), itemDescription1.c_str());
    EXPECT_STREQ(stringTest.c_str(), item1.c_str());

    // 3rd item
    iter1++;
    itemDescription1 = (*iter1)->getItemDescription();
    item1 = (*iter1)->getItem();
    EXPECT_STREQ(stringTest.c_str(), itemDescription1.c_str());
    EXPECT_STREQ(stringTest.c_str(), item1.c_str());

    // end
    iter1++;
    EXPECT_EQ(iter1, itemVector1->end());

    // text
    std::string text1 = descriptor1->getText();
    EXPECT_EQ(0x0B, text1.length());
    EXPECT_STREQ(stringTest.c_str(), text1.c_str());

    delete descriptor1;

}

/* extendedEventDescriptor */
TEST(DescriptorTest, ExtendedEvent2)
{
// extendedEventDescriptor2
    ExtendedEventDescriptor *descriptor2 = new ExtendedEventDescriptor((char *) extendedEventDescriptor2, 0, nullptr);
    int descriptorNumber2 = descriptor2->getDescriptorNumber();
    int lastDescriptorNumber2 = descriptor2->getLastDescriptorNumber();
    std::string lang2 = descriptor2->getIso639LanguageCode();
    EXPECT_EQ((extendedEventDescriptor2[2] >> 4) & MASK_4BITS, descriptorNumber2);
    EXPECT_EQ(extendedEventDescriptor2[2] & MASK_4BITS, lastDescriptorNumber2);
    EXPECT_STREQ(eng.c_str(), lang2.c_str());
    EXPECT_EQ(extendedEventDescriptor2[6], descriptor2->getLengthOfItems());

    // 1st item.
    const ItemVector* itemVector2 = descriptor2->getItemVector();
    ItemConstIterator iter2 = itemVector2->begin();
    std::string itemDescription2 = (*iter2)->getItemDescription();
    std::string item2 = (*iter2)->getItem();
    EXPECT_STREQ(stringTest.c_str(), itemDescription2.c_str());
    EXPECT_STREQ(stringTest.c_str(), item2.c_str());

    // 2nd item
    iter2++;
    itemDescription2 = (*iter2)->getItemDescription();
    item2 = (*iter2)->getItem();
    EXPECT_STREQ(stringTest.c_str(), itemDescription2.c_str());
    EXPECT_STREQ(stringTest.c_str(), item2.c_str());

    // 3rd item
    iter2++;
    itemDescription2 = (*iter2)->getItemDescription();
    item2 = (*iter2)->getItem();
    EXPECT_STREQ(stringTest.c_str(), itemDescription2.c_str());
    EXPECT_STREQ(stringTest.c_str(), item2.c_str());

    // end
    iter2++;
    EXPECT_EQ(iter2, itemVector2->end());

    // text
    std::string text2 = descriptor2->getText();
    EXPECT_EQ(0x00, text2.length());

    delete descriptor2;

}

/* extendedEventDescriptor */
TEST(DescriptorTest, ExtendedEvent3)
{
// extendedEventDescriptor3
    ExtendedEventDescriptor *descriptor3 = new ExtendedEventDescriptor((char *) extendedEventDescriptor3, 0, nullptr);
    int descriptorNumber3 = descriptor3->getDescriptorNumber();
    int lastDescriptorNumber3 = descriptor3->getLastDescriptorNumber();
    std::string lang3 = descriptor3->getIso639LanguageCode();
    EXPECT_EQ((extendedEventDescriptor3[2] >> 4) & MASK_4BITS, descriptorNumber3);
    EXPECT_EQ(extendedEventDescriptor3[2] & MASK_4BITS, lastDescriptorNumber3);
    EXPECT_STREQ(eng.c_str(), lang3.c_str());
    EXPECT_EQ(extendedEventDescriptor3[6], descriptor3->getLengthOfItems());

    // end.
    const ItemVector* itemVector3 = descriptor3->getItemVector();
    ItemConstIterator iter3 = itemVector3->begin();
    EXPECT_EQ(iter3, itemVector3->end());

    // text
    std::string text3 = descriptor3->getText();
    EXPECT_EQ(0x0B, text3.length());
    EXPECT_STREQ(stringTest.c_str(), text3.c_str());

    delete descriptor3;
}

/* extendedEventDescriptor */
TEST(DescriptorTest, ExtendedEvent4)
{
// extendedEventDescriptor4
    ExtendedEventDescriptor *descriptor4 = new ExtendedEventDescriptor((char *) extendedEventDescriptor4, 0, nullptr);
    int descriptorNumber4 = descriptor4->getDescriptorNumber();
    int lastDescriptorNumber4 = descriptor4->getLastDescriptorNumber();
    std::string lang4 = descriptor4->getIso639LanguageCode();
    EXPECT_EQ((extendedEventDescriptor4[2] >> 4) & MASK_4BITS, descriptorNumber4);
    EXPECT_EQ(extendedEventDescriptor4[2] & MASK_4BITS, lastDescriptorNumber4);
    EXPECT_STREQ(eng.c_str(), lang4.c_str());
    EXPECT_EQ(extendedEventDescriptor4[6], descriptor4->getLengthOfItems());

    // end.
    const ItemVector* itemVector4 = descriptor4->getItemVector();
    ItemConstIterator iter4 = itemVector4->begin();
    EXPECT_EQ(iter4, itemVector4->end());

    // text
    std::string text4 = descriptor4->getText();
    EXPECT_EQ(0x00, text4.length());

    delete descriptor4;
}

/* parentalRatingDescriptor */
TEST(DescriptorTest, ParentalRating)
{
// parentalRatingDescriptor1
    ParentalRatingDescriptor* descriptor = new ParentalRatingDescriptor((char *) parentalRatingDescriptor1, 0, nullptr);
    RatingVector* ratings = descriptor->getRatingVector();
    RatingConstIterator iter = ratings->begin();

    // 1st
    std::string countrycode = (*iter)->getCountryCode();
    int rate = (*iter)->getRating();
    EXPECT_STREQ(eng.c_str(), countrycode.c_str());
    EXPECT_EQ(parentalRatingDescriptor1[5], rate);

    // 2nd
    iter++;
    countrycode = (*iter)->getCountryCode();
    rate = (*iter)->getRating();
    EXPECT_STREQ(fra.c_str(), countrycode.c_str());
    EXPECT_EQ(parentalRatingDescriptor1[9], rate);

    // 3nd
    iter++;
    countrycode = (*iter)->getCountryCode();
    rate = (*iter)->getRating();
    EXPECT_STREQ(deu.c_str(), countrycode.c_str());
    EXPECT_EQ(parentalRatingDescriptor1[13], rate);

    // end
    iter++;
    EXPECT_EQ(ratings->end(), iter);

    delete(descriptor);

}

/* parentalRatingDescriptor */
TEST(DescriptorTest, ParentalRating2)
{
// parentalRatingDescriptor2
    ParentalRatingDescriptor* descriptor2 = new ParentalRatingDescriptor((char *) parentalRatingDescriptor2, 0, nullptr);
    RatingVector* ratings2 = descriptor2->getRatingVector();
    RatingConstIterator iter2 = ratings2->begin();

    //end
    EXPECT_EQ(ratings2->end(), iter2);

    delete(descriptor2);
}

/* localTimeOffsetDescriptor */
TEST(DescriptorTest, LocalTimeOffset)
{
    LocalTimeOffsetDescriptor* descriptor = new LocalTimeOffsetDescriptor((char*) localTimeOffsetDescriptor1, 0, nullptr);
    const LocalTimeOffsetVector *offsets = descriptor->getLocalOffsetVector();
    LocalTimeOffsetConstIterator iter = offsets->begin();

    // 1st.
    std::string countryCode = (*iter)->getCountryCode();
    int regionId = (*iter)->getCountryRegionId();
    int polarity = (*iter)->getLocalTimeOffsetPolarity();
    int timeOffset = (*iter)->getLocalTimeOffset();
    int timeOfChangeMjd = (*iter)->getTimeOfChangeMjd();
    int timeOfChangeBcd = (*iter)->getTimeOfChangeBcd();
    int nextTimeOffset = (*iter)->getNextTimeOffset();
    EXPECT_STREQ(eng.c_str(), countryCode.c_str());
    EXPECT_EQ((localTimeOffsetDescriptor1[5] >> 2) & 0x3F, regionId);
    EXPECT_EQ(localTimeOffsetDescriptor1[5] & MASK_1BIT, polarity);
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 6, 2, MASK_16BITS)), timeOffset);
    EXPECT_EQ(Utils::getInt(&localTimeOffsetDescriptor1[0], 8, 2, MASK_16BITS), timeOfChangeMjd);
    // TODO: should be checked...
    // r16(&localTimeOffsetDescriptor1[10]) << 8 | localTimeOffsetDescriptor1[12]
    // 	timeOfChangeBcd = (buffer[8] << 16) | UINT16(&buffer[9]);
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 10, 3, MASK_24BITS)), timeOfChangeBcd);
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 13, 2, MASK_16BITS)), nextTimeOffset);

    // 2nd.
    iter++;
    countryCode = (*iter)->getCountryCode();
    regionId = (*iter)->getCountryRegionId();
    polarity = (*iter)->getLocalTimeOffsetPolarity();
    timeOffset = (*iter)->getLocalTimeOffset();
    timeOfChangeMjd = (*iter)->getTimeOfChangeMjd();
    timeOfChangeBcd = (*iter)->getTimeOfChangeBcd();
    nextTimeOffset = (*iter)->getNextTimeOffset();
    EXPECT_STREQ(fra.c_str(), countryCode.c_str());
    EXPECT_EQ((localTimeOffsetDescriptor1[18] >> 2) & 0x3F, regionId);
    EXPECT_EQ(localTimeOffsetDescriptor1[18] & MASK_1BIT, polarity);
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 19, 2, MASK_16BITS)), timeOffset);
    EXPECT_EQ(Utils::getInt(&localTimeOffsetDescriptor1[0], 21, 2, MASK_16BITS), timeOfChangeMjd);
    // TODO: should be checked...
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 23, 3, MASK_24BITS)), timeOfChangeBcd);
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 26, 2, MASK_16BITS)), nextTimeOffset);

    // 3rd.
    iter++;
    countryCode = (*iter)->getCountryCode();
    regionId = (*iter)->getCountryRegionId();
    polarity = (*iter)->getLocalTimeOffsetPolarity();
    timeOffset = (*iter)->getLocalTimeOffset();
    timeOfChangeMjd = (*iter)->getTimeOfChangeMjd();
    timeOfChangeBcd = (*iter)->getTimeOfChangeBcd();
    nextTimeOffset = (*iter)->getNextTimeOffset();
    EXPECT_STREQ(deu.c_str(), countryCode.c_str());
    EXPECT_EQ((localTimeOffsetDescriptor1[31] >> 2) & 0x3F, regionId);
    EXPECT_EQ(localTimeOffsetDescriptor1[31] & MASK_1BIT, polarity);
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 32, 2, MASK_16BITS)), timeOffset);
    EXPECT_EQ(Utils::getInt(&localTimeOffsetDescriptor1[0], 34, 2, MASK_16BITS), timeOfChangeMjd);
    // TODO: should be checked...
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 36, 3, MASK_24BITS)), timeOfChangeBcd);
    EXPECT_EQ(Utils::getBcdInt(Utils::getInt(&localTimeOffsetDescriptor1[0], 39, 2, MASK_16BITS)), nextTimeOffset);

    // end.
    iter++;
    EXPECT_EQ(offsets->end(), iter);

    delete(descriptor);

}

/* satelliteDeliverySystemDescriptor */
TEST(DescriptorTest, SatelliteDeliverySystem)
{
    SatelliteDeliverySystemDescriptor* descriptor = new SatelliteDeliverySystemDescriptor((char *) satelliteDeliverySystemDescriptor1, 0, nullptr);
    long int frequency = descriptor->getFrequency();
    long int orbitalPosition = descriptor->getOrbitalPosition();
    int westEastFlag = descriptor->getWestEastFlag();
    int polarization = descriptor->getPolarization();
    int modulation = descriptor->getModulationType();
    long int symbolRate = descriptor->getSymbol_rate();
    int fecInner = descriptor->getFEC_inner();
    EXPECT_EQ(12345678, frequency);
    // TODO: should be checked.
    //EXPECT_EQ(0x9ABC, orbitalPosition);
    EXPECT_EQ(10122, orbitalPosition);
    EXPECT_EQ((0xDE & 0x80) >> 7, westEastFlag);
    EXPECT_EQ((0xDE & 0x60) >> 5, polarization);
    EXPECT_EQ((0xDE & 0x03), modulation);
    EXPECT_EQ(1012345, symbolRate);
    EXPECT_EQ(0x6, fecInner);

    delete descriptor;

}


/* cableDeliverySystemDescriptor */
TEST(DescriptorTest, CableDeliverySystem)
{
    CableDeliverySystemDescriptor *descriptor = new CableDeliverySystemDescriptor((char *) cableDeliverySystemDescriptor1, 0, nullptr);
    long int frequency = descriptor->getFrequency();
    int fecOuter = descriptor->getFEC_outer();
    int modulation = descriptor->getModulation();
    long int symbolRate = descriptor->getSymbol_rate();
    int fecInner = descriptor->getFEC_inner();
    EXPECT_EQ(12345678, frequency);
    EXPECT_EQ(0xC, fecOuter);
    EXPECT_EQ(0xDE, modulation);
    EXPECT_EQ(1012345, symbolRate);
    EXPECT_EQ(0x6, fecInner);

    delete descriptor;

}


/* terrestrialDeliverySystemDescriptor */
TEST(DescriptorTest, TerrestrialDeliverySystem)
{
    TerrestrialDeliverySystemDescriptor *descriptor = new TerrestrialDeliverySystemDescriptor((char *) terrestrialDeliverySystemDescriptor1, 0, nullptr);
    long int centralFrequency = descriptor->getCentreFrequency();
    int bandwidth = descriptor->getBandwidth();
    int constellation = descriptor->getConstellation();
    int hierarchyInformation = descriptor->getHierarchyInformation();
    int codeRateHpStream = descriptor->getCodeRateHPStream();
    int codeRateLpStream = descriptor->getCodeRateLPStream();
    int guardInterval = descriptor->getGuardInterval();
    int transmissionMode = descriptor->getTransmissionMode();
    int otherFrequencyFlag = descriptor->getOtherFrequencyFlag();
    EXPECT_EQ(Utils::getInt(&terrestrialDeliverySystemDescriptor1[0], 2, 4, MASK_32BITS), centralFrequency);
    EXPECT_EQ((terrestrialDeliverySystemDescriptor1[6] >> 5) & 0x07, bandwidth);
    EXPECT_EQ((terrestrialDeliverySystemDescriptor1[7] >> 6) & 0x03, constellation);
    EXPECT_EQ((terrestrialDeliverySystemDescriptor1[7] >> 3) & 0x07, hierarchyInformation);
    EXPECT_EQ(terrestrialDeliverySystemDescriptor1[7] & 0x07, codeRateHpStream);
    EXPECT_EQ((terrestrialDeliverySystemDescriptor1[8] >> 5) & 0x07, codeRateLpStream);
    EXPECT_EQ((terrestrialDeliverySystemDescriptor1[8] >> 3) & 0x03, guardInterval);
    EXPECT_EQ((terrestrialDeliverySystemDescriptor1[8] >> 1) & 0x03, transmissionMode);
    EXPECT_EQ(terrestrialDeliverySystemDescriptor1[8] & 0x01, otherFrequencyFlag);
    delete(descriptor);

}


/* bouquetNameDescriptor */
TEST(DescriptorTest, BouquetName)
{
    BouquetNameDescriptor *descriptor = new BouquetNameDescriptor((char *) bouquetNameDescriptor1, 0, nullptr);
    std::string bouquetName = descriptor->getBouquetName();
    EXPECT_STREQ(stringTest.c_str(), bouquetName.c_str());
    delete descriptor;

    descriptor = new BouquetNameDescriptor((char *) bouquetNameDescriptor2, 0, nullptr);
    bouquetName = descriptor->getBouquetName();
    EXPECT_EQ(0x00, bouquetName.length());
    delete descriptor;

}


/* countryAvailabilityDescriptor */
TEST(DescriptorTest, CountryAvailabilityName)
{
    //countryAvailabilityDescriptor1
    CountryAvailabilityDescriptor *descriptor = new CountryAvailabilityDescriptor((char *) countryAvailabilityDescriptor1, 0, nullptr);
    int countryAvailabilityFlag = descriptor->getCountryAvailabilityFlag();
    EXPECT_EQ((0x80 & 0x80) >> 7, countryAvailabilityFlag);
    const CountryVector *list = descriptor->getCountryVector();

    CountryConstIterator code = list->begin();
    std::string countryCode = (*code)->getCountryCode();
    EXPECT_STREQ(eng.c_str(), countryCode.c_str());

    code++;
    countryCode = (*code)->getCountryCode();
    EXPECT_STREQ(fra.c_str(), countryCode.c_str());

    code++;
    countryCode = (*code)->getCountryCode();
    EXPECT_STREQ(deu.c_str(), countryCode.c_str());

    code++;
    EXPECT_EQ(list->end(), code);

    delete descriptor;


}

/* countryAvailabilityDescriptor */
TEST(DescriptorTest, CountryAvailabilityName2)
{

    //countryAvailabilityDescriptor2
    CountryAvailabilityDescriptor* descriptor2 = new CountryAvailabilityDescriptor((char *) countryAvailabilityDescriptor2, 0, nullptr);
    int countryAvailabilityFlag2 = descriptor2->getCountryAvailabilityFlag();
    EXPECT_EQ((0x00 & 0x80) >> 7, countryAvailabilityFlag2);
    const CountryVector *list2 = descriptor2->getCountryVector();

    CountryConstIterator code2 = list2->begin();
    EXPECT_EQ(list2->end(), code2);

    delete descriptor2;
}

/* linkageDescriptor */
TEST(DescriptorTest, Linkage)
{
// linkageDescriptor1
    LinkageDescriptor *descriptor1 = new LinkageDescriptor((char *) linkageDescriptor1, 1, nullptr);
    int transportStreamId1 = descriptor1->getTransportStreamId();
    int originalNetworkId1 = descriptor1->getOriginalNetworkId();
    int serviceId1 = descriptor1->getServiceId();
    int linkageType1 = descriptor1->getLinkageType();
    const CharVector *privateData1 = descriptor1->getPrivateDataByte();
    CharVector a;
    a.resize(privateData1->size()+1);
    a.assign(privateData1->begin(), privateData1->end());

    char temp1[] = {0x10, 0x12, 0x34, 0x56, 0x78, 0x00};

    EXPECT_EQ(Utils::getInt(&linkageDescriptor1[1], 2, 2, MASK_16BITS), transportStreamId1);
    EXPECT_EQ(Utils::getInt(&linkageDescriptor1[1], 4, 2, MASK_16BITS), originalNetworkId1);
    EXPECT_EQ(Utils::getInt(&linkageDescriptor1[1], 6, 2, MASK_16BITS), serviceId1);
    EXPECT_EQ(linkageDescriptor1[1+8], linkageType1);
    EXPECT_EQ(5, privateData1->size());
    EXPECT_STREQ(temp1, a.data());

    delete(descriptor1);

}

/* linkageDescriptor */
TEST(DescriptorTest, Linkage2)
{
// linkageDescriptor2
    LinkageDescriptor *descriptor2 = new LinkageDescriptor((char *) linkageDescriptor2, 2, nullptr);
    int transportStreamId2 = descriptor2->getTransportStreamId();
    int originalNetworkId2 = descriptor2->getOriginalNetworkId();
    int serviceId2 = descriptor2->getServiceId();
    int linkageType2 = descriptor2->getLinkageType();
    const CharVector *privateData2 = descriptor2->getPrivateDataByte();
    CharVector a;
    a.resize(privateData2->size()+1);
    a.assign(privateData2->begin(), privateData2->end());

    char temp2[] = {0xF0, 0x56, 0x78, 0x00};

    EXPECT_EQ(Utils::getInt(&linkageDescriptor2[2], 2, 2, MASK_16BITS), transportStreamId2);
    EXPECT_EQ(Utils::getInt(&linkageDescriptor2[2], 4, 2, MASK_16BITS), originalNetworkId2);
    EXPECT_EQ(Utils::getInt(&linkageDescriptor2[2], 6, 2, MASK_16BITS), serviceId2);
    EXPECT_EQ(linkageDescriptor2[2+8], linkageType2);
    EXPECT_EQ(3, privateData2->size());
    EXPECT_STREQ(temp2, a.data());
    delete(descriptor2);

}


/* linkageDescriptor */
TEST(DescriptorTest, Linkage3)
{
// linkageDescriptor3
    LinkageDescriptor *descriptor3 = new LinkageDescriptor((char *) linkageDescriptor3, 3, nullptr);
    int transportStreamId3 = descriptor3->getTransportStreamId();
    int originalNetworkId3 = descriptor3->getOriginalNetworkId();
    int serviceId3 = descriptor3->getServiceId();
    int linkageType3 = descriptor3->getLinkageType();
    const CharVector *privateData3 = descriptor3->getPrivateDataByte();
    CharVector a;
    a.resize(privateData3->size()+1);
    a.assign(privateData3->begin(), privateData3->end());
    char temp3[] = {0x11, 0x12, 0x34, 0x00};

    EXPECT_EQ(Utils::getInt(&linkageDescriptor3[3], 2, 2, MASK_16BITS), transportStreamId3);
    EXPECT_EQ(Utils::getInt(&linkageDescriptor3[3], 4, 2, MASK_16BITS), originalNetworkId3);
    EXPECT_EQ(Utils::getInt(&linkageDescriptor3[3], 6, 2, MASK_16BITS), serviceId3);
    EXPECT_EQ(linkageDescriptor3[3+8], linkageType3);
    EXPECT_EQ(3, privateData3->size());
    EXPECT_STREQ(temp3, a.data());

    delete(descriptor3);


}


/* linkageDescriptor */
TEST(DescriptorTest, Linkage4)
{
// linkageDescriptor4
    LinkageDescriptor *descriptor4 = new LinkageDescriptor((char *) linkageDescriptor4, 4, nullptr);
    int transportStreamId4 = descriptor4->getTransportStreamId();
    int originalNetworkId4 = descriptor4->getOriginalNetworkId();
    int serviceId4 = descriptor4->getServiceId();
    int linkageType4 = descriptor4->getLinkageType();
    const CharVector *privateData4 = descriptor4->getPrivateDataByte();
    CharVector a;
    a.resize(privateData4->size()+1);
    a.assign(privateData4->begin(), privateData4->end());

    char temp4[] = {0xF1, 0x00};

    EXPECT_EQ(Utils::getInt(&linkageDescriptor4[4], 2, 2, MASK_16BITS), transportStreamId4);
    EXPECT_EQ(Utils::getInt(&linkageDescriptor4[4], 4, 2, MASK_16BITS), originalNetworkId4);
    EXPECT_EQ(Utils::getInt(&linkageDescriptor4[4], 6, 2, MASK_16BITS), serviceId4);
    EXPECT_EQ(linkageDescriptor4[4+8], linkageType4);
    EXPECT_EQ(1, privateData4->size());
    EXPECT_STREQ(temp4, a.data());
    delete(descriptor4);
}

/* componentDescriptor */
TEST(DescriptorTest, Component)
{
// componentDescriptor1
    ComponentDescriptor *descriptor1 = new ComponentDescriptor((char *) componentDescriptor1, 0, nullptr);
    int streamContent1 = descriptor1->getStreamContent();
    int componentType1 = descriptor1->getComponentType();
    int componentTag1 = descriptor1->getComponentTag();
    std::string code1 = descriptor1->getIso639LanguageCode();
    std::string text1 = descriptor1->getText();
    EXPECT_EQ(componentDescriptor1[2] & 0x0F, streamContent1);
    EXPECT_EQ(componentDescriptor1[3], componentType1);
    EXPECT_EQ(componentDescriptor1[4], componentTag1);
    EXPECT_STREQ(eng.c_str(), code1.c_str());
    EXPECT_STREQ(stringTest.c_str(), text1.c_str());
    delete(descriptor1);

}

/* componentDescriptor */
TEST(DescriptorTest, Component2)
{
// componentDescriptor2
    ComponentDescriptor *descriptor2 = new ComponentDescriptor((char *) componentDescriptor2, 0, nullptr);
    int streamContent2 = descriptor2->getStreamContent();
    int componentType2 = descriptor2->getComponentType();
    int componentTag2 = descriptor2->getComponentTag();
    std::string code2 = descriptor2->getIso639LanguageCode();
    std::string text2 = descriptor2->getText();
    EXPECT_EQ(componentDescriptor2[2] & 0x0F, streamContent2);
    EXPECT_EQ(componentDescriptor2[3], componentType2);
    EXPECT_EQ(componentDescriptor2[4], componentTag2);
    EXPECT_STREQ(eng.c_str(), code2.c_str());
    EXPECT_EQ(0, text2.length());
    delete(descriptor2);

}

/* timeShiftedServiceDescriptor */
TEST(DescriptorTest, TimeShiftedService)
{
    TimeShiftedServiceDescriptor *descriptor = new TimeShiftedServiceDescriptor((char *) timeShiftedServiceDescriptor1, 0, nullptr);
    int referenceServiceId = descriptor->getReferenceServiceId();
    EXPECT_EQ(0x5aa5, referenceServiceId);
    delete descriptor;
}

/* timeShiftedEventDescriptor */
TEST(DescriptorTest, TimeShiftedEvent)
{
    TimeShiftedEventDescriptor *descriptor = new TimeShiftedEventDescriptor((char *) timeShiftedEventDescriptor1, 0, nullptr);
    int referenceServiceId = descriptor->getReferenceServiceId();
    int referenceEventId = descriptor->getReferenceEventId();

    EXPECT_EQ(0x5aa5, referenceServiceId);
    EXPECT_EQ(0x55aa, referenceEventId);
    delete descriptor;
}

/* streamIdentifierDescriptor */
TEST(DescriptorTest, StreamIdentifier)
{
    StreamIdentifierDescriptor *descriptor = new StreamIdentifierDescriptor((char *) streamIdentifierDescriptor1, 0, nullptr);
    int componentTag = descriptor->getComponentTag();
    EXPECT_EQ(0x5A, componentTag);
    delete descriptor;

}

/* caIdentifierDescriptor */
TEST(DescriptorTest, CaIdentifier)
{

//    caIdentifierDescriptor1
    CaIdentifierDescriptor *descriptor = new CaIdentifierDescriptor((char *) caIdentifierDescriptor1, 0, nullptr);
    const CaSystemIdVector *systemIds = descriptor->getCaSystemIdVector();
    CaSystemIdConstIterator systemId = systemIds->begin();
    EXPECT_EQ(0x1234, (*systemId)->getCaSystemId());
    systemId++;
    EXPECT_EQ(0x5678, (*systemId)->getCaSystemId());
    systemId++;
    EXPECT_EQ(0x9ABC, (*systemId)->getCaSystemId());
    systemId++;
    EXPECT_EQ(systemIds->end(), systemId);
    delete(descriptor);

}

/* caIdentifierDescriptor */
TEST(DescriptorTest, CaIdentifier2)
{
//    caIdentifierDescriptor2
    CaIdentifierDescriptor *descriptor2 = new CaIdentifierDescriptor((char *) caIdentifierDescriptor2, 0, nullptr);
    const CaSystemIdVector *systemIds2 = descriptor2->getCaSystemIdVector();
    CaSystemIdConstIterator systemId2 = systemIds2->begin();
    EXPECT_EQ(systemIds2->end(), systemId2);

    delete(descriptor2);
}

/* ContentDescriptor */
TEST(DescriptorTest, Content)
{
// caIdentifierDescriptor1
    ContentDescriptor *descriptor = new ContentDescriptor((char *) contentDescriptor1, 0, nullptr);
    const ContentVector* nibbles = descriptor->getContentVector();
    ContentConstIterator nibble = nibbles->begin();
    int contentNibbleLevel1 = (*nibble)->getContentNibbleLevel1();
    int contentNibbleLevel2 = (*nibble)->getContentNibbleLevel2();
    char userByte = (*nibble)->getUserByte();
    EXPECT_EQ((contentDescriptor1[2] >> 4) & 0x0F, contentNibbleLevel1);
    EXPECT_EQ(contentDescriptor1[2] & 0x0F, contentNibbleLevel2);
    EXPECT_EQ(contentDescriptor1[3], userByte);

    nibble++;
    contentNibbleLevel1 = (*nibble)->getContentNibbleLevel1();
    contentNibbleLevel2 = (*nibble)->getContentNibbleLevel2();
    userByte = (*nibble)->getUserByte();
    EXPECT_EQ((contentDescriptor1[4] >> 4) & 0x0F, contentNibbleLevel1);
    EXPECT_EQ(contentDescriptor1[4] & 0x0F, contentNibbleLevel2);
    EXPECT_EQ(contentDescriptor1[5], userByte);

    nibble++;
    contentNibbleLevel1 = (*nibble)->getContentNibbleLevel1();
    contentNibbleLevel2 = (*nibble)->getContentNibbleLevel2();
    userByte = (*nibble)->getUserByte();
    EXPECT_EQ((contentDescriptor1[6] >> 4) & 0x0F, contentNibbleLevel1);
    EXPECT_EQ(contentDescriptor1[6] & 0x0F, contentNibbleLevel2);
    EXPECT_EQ(contentDescriptor1[7], userByte);

    nibble++;
    EXPECT_EQ(nibbles->end(), nibble);
    delete(descriptor);

}

/* ContentDescriptor */
TEST(DescriptorTest, Content2)
{
// caIdentifierDescriptor2
    ContentDescriptor *descriptor2 = new ContentDescriptor((char *) contentDescriptor2, 0, nullptr);
    const ContentVector* nibbles2 = descriptor2->getContentVector();
    ContentConstIterator nibble2 = nibbles2->begin();
    EXPECT_EQ(nibble2, nibbles2->end());

    delete(descriptor2);
}

/* privateDataSpecifierDescriptor */
TEST(DescriptorTest, PrivateDataSpecifier)
{
    PrivateDataSpecifierDescriptor *descriptor = new PrivateDataSpecifierDescriptor((char *) privateDataSpecifierDescriptor1, 0, nullptr);
    int privateDataSpecifier = descriptor->getPrivateDataSpecifier();
    EXPECT_EQ(0x5AA555AA, privateDataSpecifier);
    delete descriptor;
}

/* serviceMoveDescriptor */
TEST(DescriptorTest, ServiceMove)
{
    ServiceMoveDescriptor *descriptor = new ServiceMoveDescriptor((char *) serviceMoveDescriptor1, 0, nullptr);
    int newOriginalNetwork = descriptor->getNewOriginalNetworkId();
    int newTransportStreamId = descriptor->getNewTransportStreamId();
    int newServiceId = descriptor->getNewServiceId();
    EXPECT_EQ(0x1234, newOriginalNetwork);
    EXPECT_EQ(0x5678, newTransportStreamId);
    EXPECT_EQ(0x9abc, newServiceId);
    delete(descriptor);
}

/* frequencyListDescriptor */
TEST(DescriptorTest, FrequencyList)
{
// frequencyListDescriptor1
    FrequencyListDescriptor *descriptor = new FrequencyListDescriptor((char *) frequencyListDescriptor1, 0, nullptr);
    int codingType = descriptor->getCodingType();
    const CentreFrequencyVector* vector = descriptor->getCentreFrequencyVector();
    CentreFrequencyConstIterator iter = vector->begin();

    EXPECT_EQ(frequencyListDescriptor1[2] & 0x03, codingType);

    EXPECT_EQ(0x3456789A, (*iter)->getCentreFrequency());

    iter++;
    EXPECT_EQ(0xbcdef012, (*iter)->getCentreFrequency());

    iter++;
    EXPECT_EQ(0x3456789a, (*iter)->getCentreFrequency());

    iter++;
    EXPECT_EQ(vector->end(), iter);

    delete(descriptor);


}

/* frequencyListDescriptor */
TEST(DescriptorTest, FrequencyList2)
{
// frequencyListDescriptor2
    FrequencyListDescriptor *descriptor2 = new FrequencyListDescriptor((char *) frequencyListDescriptor2, 0, nullptr);
    int codingType2 = descriptor2->getCodingType();
    const CentreFrequencyVector* vector2 = descriptor2->getCentreFrequencyVector();
    CentreFrequencyConstIterator iter2 = vector2->begin();

    EXPECT_EQ(frequencyListDescriptor2[2] & 0x03, codingType2);
    EXPECT_EQ(vector2->end(), iter2);

    delete(descriptor2);
}

/* partialTransportStreamDescriptor */
TEST(DescriptorTest, PartialTransportStream)
{

    PartialTransportStreamDescriptor *descriptor = new PartialTransportStreamDescriptor((char *) partialTransportStreamDescriptor1, 0, nullptr);
    int peakRate = descriptor->getPeakRate();
    int minimumOverallSmoothingRate = descriptor->getMinimumOverallSmoothingRate();
    int maximumOverallSmoothingBuffer = descriptor->getMaximumOverallSmoothingBuffer();

    EXPECT_EQ(0x1AA555, peakRate);
    EXPECT_EQ(0x2A5AA5, minimumOverallSmoothingRate);
    EXPECT_EQ(0x15AA, maximumOverallSmoothingBuffer);
    delete(descriptor);
}

/* nvodReferenceDescriptor */
TEST(DescriptorTest, NvodReference)
{
// nvodReferenceDescriptor1
    NvodReferenceDescriptor *descriptor = new NvodReferenceDescriptor((char *) nvodReferenceDescriptor1, 0, nullptr);
    const NvodServiceVector *nvods = descriptor->getNvodServiceVector();
    NvodServiceConstIterator i = nvods->begin();

    int transportStreamId = (*i)->getTransportStreamId();
    int originalNetworkId = (*i)->getOriginalNetworkId();
    int serviceId = (*i)->getServiceId();
    EXPECT_EQ(0x1234, transportStreamId);
    EXPECT_EQ(0x5678, originalNetworkId);
    EXPECT_EQ(0x9ABC, serviceId);

    i++;
    transportStreamId = (*i)->getTransportStreamId();
    originalNetworkId = (*i)->getOriginalNetworkId();
    serviceId = (*i)->getServiceId();
    EXPECT_EQ(0xDEF0, transportStreamId);
    EXPECT_EQ(0x1234, originalNetworkId);
    EXPECT_EQ(0x5678, serviceId);

    i++;
    transportStreamId = (*i)->getTransportStreamId();
    originalNetworkId = (*i)->getOriginalNetworkId();
    serviceId = (*i)->getServiceId();
    EXPECT_EQ(0x9ABC, transportStreamId);
    EXPECT_EQ(0xDEF0, originalNetworkId);
    EXPECT_EQ(0x1234, serviceId);

    i++;
    EXPECT_EQ(nvods->end(), i);

    delete(descriptor);

}

/* nvodReferenceDescriptor */
TEST(DescriptorTest, NvodReference2)
{
// nvodReferenceDescriptor2
    NvodReferenceDescriptor *descriptor2 = new NvodReferenceDescriptor((char *) nvodReferenceDescriptor2, 0, nullptr);
    const NvodServiceVector *nvods2 = descriptor2->getNvodServiceVector();

    NvodServiceConstIterator i2 = nvods2->begin();
    EXPECT_EQ(nvods2->end(), i2);

    delete(descriptor2);
}

/* teletextDescriptor */
TEST(DescriptorTest, Teletext)
{
// teletextDescriptor1
    TeletextDescriptor *descriptor = new TeletextDescriptor((char *) teletextDescriptor1, 0, nullptr);
    const TeletextVector *teletextVector = descriptor->getTeletextVector();
    TeletextConstIterator i = teletextVector->begin();

    std::string code = (* i)->getIso639LanguageCode();
    int type = (* i)->getTeletextType();
    int magazine = (* i)->getTeletextMagazineNumber();
    int pageNumber = (* i)->getTeletextPageNumber();
    EXPECT_STREQ(eng.c_str(), code.c_str());
    EXPECT_EQ((0x12 & 0xF8) >> 3, type);
    EXPECT_EQ(0x12 & 0x07, magazine);
    EXPECT_EQ(0x34, pageNumber);

    i++;
    code = (* i)->getIso639LanguageCode();
    type = (* i)->getTeletextType();
    magazine = (* i)->getTeletextMagazineNumber();
    pageNumber = (* i)->getTeletextPageNumber();
    EXPECT_STREQ(fra.c_str(), code.c_str());
    EXPECT_EQ((0x56 & 0xF8) >> 3, type);
    EXPECT_EQ(0x56 & 0x07, magazine);
    EXPECT_EQ(0x78, pageNumber);

    i++;
    code = (* i)->getIso639LanguageCode();
    type = (* i)->getTeletextType();
    magazine = (* i)->getTeletextMagazineNumber();
    pageNumber = (* i)->getTeletextPageNumber();
    EXPECT_STREQ(deu.c_str(), code.c_str());
    EXPECT_EQ((0x9A & 0xF8) >> 3, type);
    EXPECT_EQ(0x9A & 0x07, magazine);
    EXPECT_EQ(0xbc, pageNumber);

    i++;
    EXPECT_EQ(teletextVector->end(), i);

    delete descriptor;


}

/* teletextDescriptor */
TEST(DescriptorTest, Teletext2)
{
// teletextDescriptor2
    TeletextDescriptor *descriptor2 = new TeletextDescriptor((char *) teletextDescriptor2, 0, nullptr);
    const TeletextVector *teletextVector2 = descriptor2->getTeletextVector();
    TeletextConstIterator i2 = teletextVector2->begin();

    i2 = teletextVector2->begin();
    EXPECT_EQ(teletextVector2->end(), i2);

    delete descriptor2;
}

/* multilingualNetworkNameDescriptor */
TEST(DescriptorTest, MultilingualNetworkName)
{
// multilingualNetworkNameDescriptor1
    MultilingualNetworkNameDescriptor *descriptor = new MultilingualNetworkNameDescriptor((char *) multilingualNetworkNameDescriptor1, 0, nullptr);
    MultilingualNetworkNameVector *names = descriptor->getMultilingualNetworkNameVector();
    MultilingualNetworkNameConstIterator i = names->begin();

    std::string code = (* i)->getIso639LanguageCode();
    std::string name = (* i)->getNetworkName();
    EXPECT_STREQ(eng.c_str(), code.c_str());
    EXPECT_STREQ(stringTestEng.c_str(), name.c_str());

    i++;
    code = (* i)->getIso639LanguageCode();
    name = (* i)->getNetworkName();
    EXPECT_STREQ(fra.c_str(), code.c_str());
    EXPECT_STREQ(stringTestFra.c_str(), name.c_str());

    i++;
    code = (* i)->getIso639LanguageCode();
    name = (* i)->getNetworkName();
    EXPECT_STREQ(deu.c_str(), code.c_str());
    EXPECT_STREQ(stringTestDeu.c_str(), name.c_str());

    i++;
    EXPECT_EQ(names->end(), i);

    delete descriptor;


}

/* multilingualNetworkNameDescriptor */
TEST(DescriptorTest, MultilingualNetworkName2)
{
// multilingualNetworkNameDescriptor2
    MultilingualNetworkNameDescriptor *descriptor2 = new MultilingualNetworkNameDescriptor((char *) multilingualNetworkNameDescriptor2, 0, nullptr);
    MultilingualNetworkNameVector *names2 = descriptor2->getMultilingualNetworkNameVector();
    MultilingualNetworkNameConstIterator i2 = names2->begin();

    i2 = names2->begin();
    EXPECT_EQ(names2->end(), i2);

    delete descriptor2;
}

/* multilingualBouquetNameDescriptor */
TEST(DescriptorTest, MultilingualBouquetName)
{
// multilingualBouquetNameDescriptor1
    MultilingualBouquetNameDescriptor *descriptor = new MultilingualBouquetNameDescriptor((char *) multilingualBouquetNameDescriptor1, 0, nullptr);
    MultilingualBouquetNameVector *names = descriptor->getMultilingualBouquetNameVector();
    MultilingualBouquetNameConstIterator i = names->begin();

    std::string code = (* i)->getIso639LanguageCode();
    std::string name = (* i)->getBouquetName();
    EXPECT_STREQ(eng.c_str(), code.c_str());
    EXPECT_STREQ(stringTestEng.c_str(), name.c_str());

    i++;
    code = (* i)->getIso639LanguageCode();
    name = (* i)->getBouquetName();
    EXPECT_STREQ(fra.c_str(), code.c_str());
    EXPECT_STREQ(stringTestFra.c_str(), name.c_str());

    i++;
    code = (* i)->getIso639LanguageCode();
    name = (* i)->getBouquetName();
    EXPECT_STREQ(deu.c_str(), code.c_str());
    EXPECT_STREQ(stringTestDeu.c_str(), name.c_str());

    i++;
    EXPECT_EQ(names->end(), i);

    delete descriptor;

}

/* multilingualBouquetNameDescriptor */
TEST(DescriptorTest, MultilingualBouquetName2)
{
// multilingualBouquetNameDescriptor2
    MultilingualBouquetNameDescriptor *descriptor2 = new MultilingualBouquetNameDescriptor((char *) multilingualBouquetNameDescriptor2, 0, nullptr);
    MultilingualBouquetNameVector *names2 = descriptor2->getMultilingualBouquetNameVector();
    MultilingualBouquetNameConstIterator i2 = names2->begin();

    EXPECT_EQ(names2->end(), i2);

    delete descriptor2;

}

/* multilingualServiceNameDescriptor */
TEST(DescriptorTest, MultilingualServiceName)
{

// multilingualServiceNameDescriptor1
    MultilingualServiceNameDescriptor *descriptor = new MultilingualServiceNameDescriptor((char *) multilingualServiceNameDescriptor1, 0, nullptr);
    MultilingualServiceNameVector *names = descriptor->getMultilingualServiceNameVector();

    MultilingualServiceNameConstIterator i = names->begin();
    std::string code = (* i)->getIso639LanguageCode();
    std::string provider = (* i)->getServiceProviderName();
    std::string name = (* i)->getServiceName();
    EXPECT_STREQ(eng.c_str(), code.c_str());
    EXPECT_STREQ(stringTest.c_str(), provider.c_str());
    EXPECT_STREQ(stringTestEng.c_str(), name.c_str());

    i++;
    code = (* i)->getIso639LanguageCode();
    provider = (* i)->getServiceProviderName();
    name = (* i)->getServiceName();
    EXPECT_STREQ(fra.c_str(), code.c_str());
    EXPECT_STREQ(stringTest.c_str(), provider.c_str());
    EXPECT_STREQ(stringTestFra.c_str(), name.c_str());

    i++;
    code = (* i)->getIso639LanguageCode();
    provider = (* i)->getServiceProviderName();
    name = (* i)->getServiceName();
    EXPECT_STREQ(deu.c_str(), code.c_str());
    EXPECT_STREQ(stringTest.c_str(), provider.c_str());
    EXPECT_STREQ(stringTestDeu.c_str(), name.c_str());

    i++;
    EXPECT_EQ(names->end(), i);

    delete descriptor;
}


/* multilingualServiceNameDescriptor */
TEST(DescriptorTest, MultilingualServiceName2)
{
// multilingualServiceNameDescriptor2
    MultilingualServiceNameDescriptor *descriptor2 = new MultilingualServiceNameDescriptor((char *) multilingualServiceNameDescriptor2, 0, nullptr);
    MultilingualServiceNameVector *names2 = descriptor2->getMultilingualServiceNameVector();

    MultilingualServiceNameConstIterator i2 = names2->begin();
    EXPECT_EQ(names2->end(), i2);

    delete descriptor2;
}

/* mosaicDescriptor */
TEST(DescriptorTest, Mosaic)
{
    MosaicDescriptor *descriptor = new MosaicDescriptor((char *) mosaicDescriptor1, 0, nullptr);
    int mosaicEntryPoint = descriptor->getMosaicEntryPoint();
    int numberOfHorizontalElementaryCells = descriptor->getNumberOfHorizontalElementaryCells();
    int numberOfVerticalElementaryCells = descriptor->getNumberOfVerticalElementaryCells();
    EXPECT_EQ((mosaicDescriptor1[2] >> 7) & 0x01, mosaicEntryPoint);
    EXPECT_EQ((mosaicDescriptor1[2] >> 4) & 0x07, numberOfHorizontalElementaryCells);
    EXPECT_EQ(mosaicDescriptor1[2] & 0x07, numberOfVerticalElementaryCells);

    LogicalCellVector *cells = descriptor->getLogicalCellVector();
    LogicalCellConstIterator cell = cells->begin();

    int logicalCellId = (*cell)->getLogicalCellId();
    int logicalCellPresentationInfo = (*cell)->getLogicalCellPresentationInfo();
    EXPECT_EQ(logicalCellId, (mosaicDescriptor1[3] >> 2) & 0x3F);
    EXPECT_EQ(logicalCellPresentationInfo, mosaicDescriptor1[4] & 0x07);

    ElementaryCellIdVector *fields = (*cell)->getElementaryCellIdVector();
    ElementaryCellIdIterator field = fields->begin();
    EXPECT_EQ(mosaicDescriptor1[6] & 0x3F, *field);
    field++;
    EXPECT_EQ(mosaicDescriptor1[7] & 0x3F, *field);
    field++;
    EXPECT_EQ(mosaicDescriptor1[8] & 0x3F, *field);
    field++;
    EXPECT_EQ(fields->end(), field);


    int cellLinkageInfo = (*cell)->getCellLinkageInfo();
    int bouquetId = (*cell)->getBouquetId();
    EXPECT_EQ(mosaicDescriptor1[9], cellLinkageInfo);
    EXPECT_EQ(0xF012, bouquetId);


    cell++;
    logicalCellId = (*cell)->getLogicalCellId();
    logicalCellPresentationInfo = (*cell)->getLogicalCellPresentationInfo();
    EXPECT_EQ((mosaicDescriptor1[12] >> 2) & 0x3F, logicalCellId);
    EXPECT_EQ(mosaicDescriptor1[13] & 0x07, logicalCellPresentationInfo);

    fields = (*cell)->getElementaryCellIdVector();
    field = fields->begin();
    EXPECT_EQ(fields->end(), field);

    cellLinkageInfo = (*cell)->getCellLinkageInfo();
    int originalNetworkId = (*cell)->getOriginalNetworkId();
    int transportStreamId = (*cell)->getTransportStreamId();
    int serviceId = (*cell)->getServiceId();
    EXPECT_EQ(mosaicDescriptor1[15], cellLinkageInfo);
    EXPECT_EQ(0x789a, originalNetworkId);
    EXPECT_EQ(0xbcde, transportStreamId);
    EXPECT_EQ(0xf012, serviceId);

    cell++;
    logicalCellId = (*cell)->getLogicalCellId();
    logicalCellPresentationInfo = (*cell)->getLogicalCellPresentationInfo();
    EXPECT_EQ((mosaicDescriptor1[22] >> 2) & 0x3F, logicalCellId);
    EXPECT_EQ(mosaicDescriptor1[23] & 0x07, logicalCellPresentationInfo);

    fields = (*cell)->getElementaryCellIdVector();
    field = fields->begin();
    EXPECT_EQ(fields->end(), field);

    cellLinkageInfo = (*cell)->getCellLinkageInfo();
    originalNetworkId = (*cell)->getOriginalNetworkId();
    transportStreamId = (*cell)->getTransportStreamId();
    serviceId = (*cell)->getServiceId();
    EXPECT_EQ(mosaicDescriptor1[25], cellLinkageInfo);
    EXPECT_EQ(0x789a, originalNetworkId);
    EXPECT_EQ(0xbcde, transportStreamId);
    EXPECT_EQ(0xf012, serviceId);

    cell++;
    logicalCellId = (*cell)->getLogicalCellId();
    logicalCellPresentationInfo = (*cell)->getLogicalCellPresentationInfo();
    EXPECT_EQ((mosaicDescriptor1[32] >> 2) & 0x3F, logicalCellId);
    EXPECT_EQ(mosaicDescriptor1[33] & 0x07, logicalCellPresentationInfo);

    fields = (*cell)->getElementaryCellIdVector();
    field = fields->begin();
    EXPECT_EQ(fields->end(), field);

    cellLinkageInfo = (*cell)->getCellLinkageInfo();
    originalNetworkId = (*cell)->getOriginalNetworkId();
    transportStreamId = (*cell)->getTransportStreamId();
    serviceId = (*cell)->getServiceId();
    int eventId = (*cell)->getEventId();
    EXPECT_EQ(mosaicDescriptor1[35], cellLinkageInfo);
    EXPECT_EQ(0x789a, originalNetworkId);
    EXPECT_EQ(0xbcde, transportStreamId);
    EXPECT_EQ(0xf012, serviceId);
    EXPECT_EQ(0x3456, eventId);

    cell++;
    EXPECT_EQ(cell, cells->end());

    delete(descriptor);

}

/* telephoneDescriptor */
TEST(DescriptorTest, Telephone)
{
    TelephoneDescriptor *descriptor = new TelephoneDescriptor((char *) telephoneDescriptor1, 0, nullptr);
    int foreignAvailability = descriptor->getForeignAvailability();
    int connectionType = descriptor->getConnectionType();
    const std::string countryPrefix = descriptor->getCountryPrefix();
    const std::string internationalAreaCode = descriptor->getInternationalAreaCode();
    const std::string operatorCode = descriptor->getOperatorCode();
    const std::string nationalAreaCode = descriptor->getNationalAreaCode();
    const std::string coreNumber = descriptor->getCoreNumber();

    EXPECT_EQ(telephoneDescriptor1[2] & 0x20, foreignAvailability);
    EXPECT_EQ(telephoneDescriptor1[2] & 0x1F, connectionType);

#if 0
    const int countryPrefixLength = descriptor->getCountryPrefixLength();
    const int internationalAreaCodeLength = descriptor->getInternationalAreaCodeLength();
    const int operatorCodeLength = descriptor->getOperatorCodeLength();
    const int nationalAreaCodeLength = descriptor->getNationalAreaCodeLength();
    const int coreNumberLength = descriptor->getCoreNumberLength();

    EXPECT_EQ(2, countryPrefixLength);
    EXPECT_EQ(1, internationalAreaCodeLength);
    EXPECT_EQ(2, operatorCodeLength);
    EXPECT_EQ(1, nationalAreaCodeLength);
    EXPECT_EQ(6, coreNumberLength);
#endif

    char temp1[] = {0x33, 0x34, 0x00};
    EXPECT_STREQ(temp1, countryPrefix.c_str()); //2
    char temp2[] = {0x35, 0x00};
    EXPECT_STREQ(temp2, internationalAreaCode.c_str()); //1
    char temp3[] = {0x36, 0x37, 0x00};
    EXPECT_STREQ(temp3, operatorCode.c_str()); //2
    char temp4[] = {0x38, 0x00};
    EXPECT_STREQ(temp4, nationalAreaCode.c_str()); //1
    char temp5[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x00};
    EXPECT_STREQ(temp5, coreNumber.c_str()); //6

    delete(descriptor);
}

/* multilingualComponentDescriptor */
TEST(DescriptorTest, MultilingualComponent)
{
// multilingualComponentDescriptor1
    MultilingualComponentDescriptor *descriptor = new MultilingualComponentDescriptor((char *) multilingualComponentDescriptor1, 0, nullptr);
    int tag = descriptor->getComponentTag();
    EXPECT_EQ(multilingualComponentDescriptor1[2], tag);
    TextDescriptionVector *components = descriptor->getTextDescriptionVector();

    TextDescriptionConstIterator i = components->begin();
    std::string code = (* i)->getIso639LanguageCode();
    std::string text = (* i)->getTextDescription();
    EXPECT_STREQ(eng.c_str(), code.c_str());
    EXPECT_STREQ(stringTestEng.c_str(), text.c_str());

    i++;
    code = (* i)->getIso639LanguageCode();
    text = (* i)->getTextDescription();
    EXPECT_STREQ(fra.c_str(), code.c_str());
    EXPECT_STREQ(stringTestFra.c_str(), text.c_str());

    i++;
    code = (* i)->getIso639LanguageCode();
    text = (* i)->getTextDescription();
    EXPECT_STREQ(deu.c_str(), code.c_str());
    EXPECT_STREQ(stringTestDeu.c_str(), text.c_str());

    i++;
    EXPECT_EQ(i, components->end());

    delete descriptor;

}

/* multilingualComponentDescriptor */
TEST(DescriptorTest, MultilingualComponent2)
{
// multilingualComponentDescriptor2
    MultilingualComponentDescriptor *descriptor2 = new MultilingualComponentDescriptor((char *) multilingualComponentDescriptor2, 0, nullptr);
    int tag2 = descriptor2->getComponentTag();
    EXPECT_EQ(multilingualComponentDescriptor1[2], tag2);
    TextDescriptionVector *components2 = descriptor2->getTextDescriptionVector();

    TextDescriptionConstIterator i2 = components2->begin();
    EXPECT_EQ(components2->end(), i2);

    delete descriptor2;

}

/* pdcDescriptor */
TEST(DescriptorTest, Pdc)
{
    PDCDescriptor *descriptor = new PDCDescriptor((char *) pdcDescriptor1, 0, nullptr);
    int programmeIdentificationLabel = descriptor->getProgrammeIdentificationLabel();
    EXPECT_EQ(0xaa555, programmeIdentificationLabel);
    delete descriptor;
}

/* ancillaryDataDescriptor */
TEST(DescriptorTest, AncillaryData)
{
    AncillaryDataDescriptor *descriptor = new AncillaryDataDescriptor((char *) ancillaryDataDescriptor1, 0, nullptr);
    int ancillaryDataIdentifier = descriptor->getAncillaryDataIdentifier();
    EXPECT_EQ(0x5a, ancillaryDataIdentifier);
    delete descriptor;

}

/* shortSmoothingBufferDescriptor */
TEST(DescriptorTest, ShortSmoothingBuffer)
{
    ShortSmoothingBufferDescriptor *descriptor = new ShortSmoothingBufferDescriptor((char*) shortSmoothingBufferDescriptor, 0, nullptr);
    int sb_size = descriptor->getSbSize();
    int sb_leak_rate = descriptor->getSbLeakRate();
    EXPECT_EQ(1, sb_size);
    EXPECT_EQ(10, sb_leak_rate);
    delete descriptor;
}

/* dataBroadcastDescriptor */
TEST(DescriptorTest, DataBroadcast)
{
    DataBroadcastDescriptor* descriptor = new DataBroadcastDescriptor((char*) dataBroadcastDescriptor, 2, nullptr);
    int broadcastId = descriptor->getDataBroadcastId();
    int componentTag = descriptor->getComponentTag();
    const CharVector *selector_byte = descriptor->getSelectorByte();
    CharVector a;
    a.resize(selector_byte->size()+1);
    a.assign(selector_byte->begin(), selector_byte->end());

    std::string languageCode = descriptor->getIso639LanguageCode();
    std::string text = descriptor->getText();

    EXPECT_EQ(0x1122, broadcastId);
    EXPECT_EQ(78, componentTag);
    char temp[] = {0x42, 0x59, 0x22, 0x54, 0x45, 0x00};
    EXPECT_EQ(5, selector_byte->size());
    EXPECT_STREQ(temp, a.data());

    EXPECT_STREQ("eng", languageCode.c_str());
    EXPECT_STREQ("Some text", text.c_str());

    delete descriptor;
}

/* dataBroadcastIdDescriptor */
TEST(DescriptorTest, DataBroadcastId)
{
    DataBroadcastIDDescriptor* descriptor = new DataBroadcastIDDescriptor((char*) dataBroadcastIdDescriptor, 0, nullptr);
    int broadcastId = descriptor->getDataBroadcastId();
    const CharVector *selector_byte = descriptor->getSelectorByte();
    CharVector a;
    a.resize(selector_byte->size()+1);
    a.assign(selector_byte->begin(), selector_byte->end());

    EXPECT_EQ(0x1122, broadcastId);
    char temp[] = {0x55, 0x4E, 0x49, 0x58, 0x00};
    EXPECT_EQ(4, selector_byte->size());
    EXPECT_STREQ(temp, a.data());

    delete descriptor;
}

TEST(DescriptorTest, DataBroadcastIdStuff)
{
    DataBroadcastIDDescriptor* descriptor = new DataBroadcastIDDescriptor((char*) dataBroadcastIdDescriptorStuff, 1, nullptr);
    int broadcastId = descriptor->getDataBroadcastId();
    const CharVector *selector_byte = descriptor->getSelectorByte();
    CharVector a;
    a.resize(selector_byte->size()+1);
    a.assign(selector_byte->begin(), selector_byte->end());

    EXPECT_EQ(0x1122, broadcastId);
    char temp[] = {0x55, 0x4E, 0x49, 0x58, 0x00};
    EXPECT_EQ(4, selector_byte->size());
    EXPECT_STREQ(temp, a.data());

    delete descriptor;
}

/* ac3Descriptor */
TEST(DescriptorTest, Ac3)
{
    AC3Descriptor* descriptor = new AC3Descriptor((char*) ac3Descriptor, 0, nullptr);
    int componentType = descriptor->getComponentType();
    int bsid = descriptor->getBsid();
    int mainid = descriptor->getMainid();
    int asvc = descriptor->getAsvc();
    const CharVector *additionalInfo = descriptor->getAdditionalInfo();
    CharVector a;
    a.resize(additionalInfo->size()+1);
    a.assign(additionalInfo->begin(), additionalInfo->end());


    EXPECT_EQ(10, componentType);
    EXPECT_EQ(20, bsid);
    EXPECT_EQ(30, mainid);
    EXPECT_EQ(40, asvc);
    EXPECT_EQ(4, additionalInfo->size());
    EXPECT_STREQ("UNIX", a.data());


    delete descriptor;


}

/* enhancedAc3Descriptor */
TEST(DescriptorTest, EnhancedAc3)
{
    EnhancedAC3Descriptor* descriptor = new EnhancedAC3Descriptor((char*) enhancedAc3Descriptor, 0, nullptr);
    int componentType = descriptor->getComponentType();
    int bsid = descriptor->getBsid();
    int mainid = descriptor->getMainid();
    int asvc = descriptor->getAsvc();
    bool mixinfoexists = descriptor->getMixInfoExists();
    const CharVector *additionalInfo = descriptor->getAdditionalInfo();
    CharVector a;
    a.resize(additionalInfo->size()+1);
    a.assign(additionalInfo->begin(), additionalInfo->end());

    int substream1 = descriptor->getSubStream1();
    int substream2 = descriptor->getSubStream2();
    int substream3 = descriptor->getSubStream3();

    EXPECT_EQ(10, componentType);
    EXPECT_EQ(20, bsid);
    EXPECT_EQ(30, mainid);
    EXPECT_EQ(40, asvc);
    EXPECT_TRUE(mixinfoexists);
    EXPECT_EQ(50, substream1);
    EXPECT_EQ(60, substream2);
    EXPECT_EQ(70, substream3);
    EXPECT_EQ(4, additionalInfo->size());
    EXPECT_STREQ("UNIX", a.data());


    delete descriptor;

}

/* aacDescriptor */
TEST(DescriptorTest, Aac)
{
    AACDescriptor* descriptor = new AACDescriptor((char*) aacDescriptor, 0, nullptr);
    int profileAndLevel = descriptor->getProfileAndLevel();
    int aacType = descriptor->getAacType();
    const CharVector *additionalInfo = descriptor->getAdditionalInfo();
    CharVector a;
    a.resize(additionalInfo->size()+1);
    a.assign(additionalInfo->begin(), additionalInfo->end());
    EXPECT_EQ(0x14, profileAndLevel);
    EXPECT_EQ(0x1f, aacType);
    EXPECT_EQ(4, additionalInfo->size());
    EXPECT_STREQ("UNIX", a.data());

    delete descriptor;
}

TEST(DescriptorTest, Aac2)
{
    AACDescriptor* descriptor = new AACDescriptor((char*) aacDescriptor2, 2, nullptr);
    int profileAndLevel = descriptor->getProfileAndLevel();
    int aacType = descriptor->getAacType();
    const CharVector *additionalInfo = descriptor->getAdditionalInfo();
    CharVector a;
    a.resize(additionalInfo->size()+1);
    a.assign(additionalInfo->begin(), additionalInfo->end());
    EXPECT_EQ(0x14, profileAndLevel);
    EXPECT_EQ(0x1f, aacType);
    EXPECT_EQ(1, additionalInfo->size());
    EXPECT_STREQ("U", a.data());

    delete descriptor;
}


// 13818-1

/* videoStreamDescriptor */
TEST(DescriptorTest, VideoStream1)
{
    VideoStreamDescriptor* descriptor = new VideoStreamDescriptor((char*) videoStreamDescriptor1, 0, nullptr);
    bool multipleFrameRateFlag = descriptor->getMultipleFrameRateFlag();
    int frameRateCode = descriptor->getFrameRateCode();
    bool mpeg1onlyFlag = descriptor->getMpeg1OnlyFlag();
    bool constraintParamFlag = descriptor->getConstrainedParameterFlag();
    bool stillPicFlag = descriptor->getStillPictureFlag();

    EXPECT_TRUE(multipleFrameRateFlag);
    EXPECT_EQ(3, frameRateCode);
    EXPECT_TRUE(mpeg1onlyFlag);
    EXPECT_TRUE(constraintParamFlag);
    EXPECT_TRUE(stillPicFlag);

    delete descriptor;
}

/* videoStreamDescriptor */
TEST(DescriptorTest, VideoStream2)
{
    VideoStreamDescriptor* descriptor = new VideoStreamDescriptor((char*) videoStreamDescriptor2, 0, nullptr);
    bool multipleFrameRateFlag = descriptor->getMultipleFrameRateFlag();
    int frameRateCode = descriptor->getFrameRateCode();
    bool mpeg1onlyFlag = descriptor->getMpeg1OnlyFlag();
    bool constraintParamFlag = descriptor->getConstrainedParameterFlag();
    bool stillPicFlag = descriptor->getStillPictureFlag();

    int profile = descriptor->getProfileAndLevelIndication();
    int chromaFormat = descriptor->getChromaFormat();
    bool frameRateExtFlag = descriptor->getFrameRateExtensionFlag();

    EXPECT_TRUE(multipleFrameRateFlag);
    EXPECT_EQ(4, frameRateCode);
    EXPECT_FALSE(mpeg1onlyFlag);
    EXPECT_TRUE(constraintParamFlag);
    EXPECT_TRUE(stillPicFlag);

    EXPECT_EQ(72, profile);
    EXPECT_EQ(2, chromaFormat);
    EXPECT_FALSE(frameRateExtFlag);

    delete descriptor;

}

/* audioStreamDescriptor */
TEST(DescriptorTest, AudioStream)
{
    AudioStreamDescriptor* descriptor = new AudioStreamDescriptor((char*) audioStreamDescriptor, 0, nullptr);
    bool freeFormatFlag = descriptor->getFreeFormatFlag();
    int id = descriptor->getId();
    int layer = descriptor->getLayer();
    int variableRateAudioIndicator = descriptor->getVariableRateAudioIndicator();

    EXPECT_TRUE(freeFormatFlag);
    EXPECT_EQ(1, id);
    EXPECT_EQ(2, layer);
    EXPECT_EQ(1, variableRateAudioIndicator);

    delete descriptor;
}

/* hierarchyDescriptor */
TEST(DescriptorTest, Hierarchy)
{
    HierarchyDescriptor* descriptor = new HierarchyDescriptor((char*) hierarchyDescriptor, 0, nullptr);
    int type = descriptor->getHierarchy_type();
    int layerIndex = descriptor->getHierarchy_layer_index();
    int embeddedLayerIndex = descriptor->getHierarchy_embedded_layer_index();
    int channel = descriptor->getHierarchy_channel();

    EXPECT_EQ(1, type);
    EXPECT_EQ(6, layerIndex);
    EXPECT_EQ(7, embeddedLayerIndex);
    EXPECT_EQ(8, channel);

    delete descriptor;
}

/* registrationDescriptor */
TEST(DescriptorTest, Registration)
{
    RegistrationDescriptor* desc = new RegistrationDescriptor((char*) registrationDescriptor, 1, nullptr);

    const CharVector *identifier = desc->getFormatIdentifier();
    CharVector a;
    a.resize(identifier->size()+1);
    a.assign(identifier->begin(), identifier->end());
    EXPECT_EQ(4, identifier->size());
    EXPECT_STREQ("TEST", a.data());

    const CharVector *additional = desc->getAdditionalIdentificationInfo();
    CharVector b;
    b.resize(additional->size()+1);
    b.assign(additional->begin(), additional->end());
    EXPECT_EQ(4, additional->size());
    EXPECT_STREQ("UNIX", b.data());

    delete desc;

}

/* dataStreamAlignmentDescriptor */
TEST(DescriptorTest, DataStreamAlignment)
{
    DataStreamAlignmentDescriptor* desc = new DataStreamAlignmentDescriptor((char*) dataStreamAlignmentDescriptor, 0, nullptr);
    int type = desc->getAlignmentType();

    EXPECT_EQ(0x02, type);

    delete desc;

}

/* targetBackgroundGridDescriptor */
TEST(DescriptorTest, TargetBackgroundGrid)
{
    TargetBackGroundDescriptor* desc = new TargetBackGroundDescriptor((char*) targetBackgroundGridDescriptor, 0, nullptr);
    int hor = desc->getHorizontalSize();
    int ver = desc->getVerticalSize();
    int aspect = desc->getAspectRatioInformation();

    EXPECT_EQ(720, hor);
    EXPECT_EQ(576, ver);
    EXPECT_EQ(7, aspect);

    delete desc;
}

/* videoWindowDescriptor */
TEST(DescriptorTest, VideoWindow)
{
    VideoWindowDescriptor* desc = new VideoWindowDescriptor((char*) videoWindowDescriptor, 0, nullptr);
    int hor = desc->getHorizontalOffset();
    int ver = desc->getVerticalOffset();
    int win = desc->getWindowPriority();

    EXPECT_EQ(1024, hor);
    EXPECT_EQ(768, ver);
    EXPECT_EQ(15, win);

    delete desc;

}

/* conditionalAccessDescriptor */
TEST(DescriptorTest, ConditionalAccess)
{
    ConditionalAccessDescriptor* desc = new ConditionalAccessDescriptor((char*) caDescriptor, 0, nullptr);
    int sysid = desc->getCaSystemID();
    int pid = desc->getCaPID();
    const CharVector *privateData = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateData->size()+1);
    a.assign(privateData->begin(), privateData->end());


    EXPECT_EQ(0xb000, sysid);
    EXPECT_EQ(1234, pid);
    EXPECT_EQ(4, privateData->size());
    EXPECT_STREQ("TEST", a.data());


    delete desc;

}

TEST(DescriptorTest, ConditionalAccessStuff1)
{
    ConditionalAccessDescriptor* desc = new ConditionalAccessDescriptor((char*) caDescriptorStuff, 1, nullptr);
    int sysid = desc->getCaSystemID();
    int pid = desc->getCaPID();
    const CharVector *privateData = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateData->size()+1);
    a.assign(privateData->begin(), privateData->end());


    EXPECT_EQ(0xb000, sysid);
    EXPECT_EQ(1234, pid);
    EXPECT_EQ(4, privateData->size());
    EXPECT_STREQ("TEST", a.data());


    delete desc;

}
TEST(DescriptorTest, ConditionalAccessStuff2)
{
    ConditionalAccessDescriptor* desc = new ConditionalAccessDescriptor((char*) caDescriptorStuff2, 1, nullptr);
    int sysid = desc->getCaSystemID();
    int pid = desc->getCaPID();
    const CharVector *privateData = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateData->size()+1);
    a.assign(privateData->begin(), privateData->end());


    EXPECT_EQ(0xb000, sysid);
    EXPECT_EQ(1234, pid);
    EXPECT_EQ(1, privateData->size());
    EXPECT_STREQ("T", a.data());


    delete desc;

}
/* iso639LanguageDescriptor */
TEST(DescriptorTest, Iso639Language)
{
    ISO639LanguageDescriptor *descriptor = new ISO639LanguageDescriptor((char *) iso639LanguageDescriptor, 0, nullptr);
    const LanguageVector *languageVector = descriptor->getLanguageVector();
    LanguageConstIterator language = languageVector->begin();

    // 1st.
    std::string lancode = (*language)->getIso639LanguageCode();
    int audioType = (*language)->getAudioType();
    EXPECT_STREQ("eng", lancode.c_str());
    EXPECT_EQ(0, audioType);

    // 2nd.
    language++;
    lancode = (*language)->getIso639LanguageCode();
    audioType = (*language)->getAudioType();
    EXPECT_STREQ("eng", lancode.c_str());
    EXPECT_EQ(1, audioType);

    // 3
    language++;
    lancode = (*language)->getIso639LanguageCode();
    audioType = (*language)->getAudioType();
    EXPECT_STREQ("eng", lancode.c_str());
    EXPECT_EQ(2, audioType);

    // 4
    language++;
    lancode = (*language)->getIso639LanguageCode();
    audioType = (*language)->getAudioType();
    EXPECT_STREQ("eng", lancode.c_str());
    EXPECT_EQ(3, audioType);

    // 5
    language++;
    lancode = (*language)->getIso639LanguageCode();
    audioType = (*language)->getAudioType();
    EXPECT_STREQ("bul", lancode.c_str());
    EXPECT_EQ(4, audioType);

    // 6
    language++;
    lancode = (*language)->getIso639LanguageCode();
    audioType = (*language)->getAudioType();
    EXPECT_STREQ("bul", lancode.c_str());
    EXPECT_EQ(0, audioType);


    language++;
    EXPECT_EQ(languageVector->end(), language);

    delete descriptor;

}

/* systemClockDescriptor */
TEST(DescriptorTest, SystemClock)
{
    SystemClockDescriptor* desc = new SystemClockDescriptor((char*) systemClockDescriptor, 0, nullptr);
    int ext = desc->getExternalClockReferenceIndicator();
    int cloInt = desc->getClockAccuracyInteger();
    int cloExp = desc->getClockAccuracyExponent();

    EXPECT_EQ(1, ext);
    EXPECT_EQ(60, cloInt);
    EXPECT_EQ(4, cloExp);

    delete desc;

}

/* multiplexBufferUtilizationDescriptor */
TEST(DescriptorTest, MultiplexBufferUtilization)
{
    MultiplexBufferUtilizationDescriptor* desc = new MultiplexBufferUtilizationDescriptor((char*) multiplexBufferUtilizationDescriptor, 0, nullptr);
    bool boundFlag = desc->getBoundValidFlag();
    int lBound = desc->getLtwOffsetLowerBound();
    int uBound = desc->getLtwOffsetUpperBound();

    EXPECT_TRUE(boundFlag);
    EXPECT_EQ(1234, lBound);
    EXPECT_EQ(5678, uBound);

    delete desc;
}

/* copyrightDescriptor */
TEST(DescriptorTest, Copyright)
{
    CopyrightDescriptor* desc = new CopyrightDescriptor((char*) copyrightDescriptor, 0, nullptr);
    int identifier = desc->getCopyrightIdentifier();
    const CharVector *addi = desc->getAdditionalCopyrightInfo();
    CharVector a;
    a.resize(addi->size()+1);
    a.assign(addi->begin(), addi->end());

    EXPECT_EQ(0x12345678, identifier);

    char temp[] = {0x41, 0x42, 0x43, 0x44, 0x00};
    EXPECT_STREQ(temp, a.data());

    delete desc;
}

TEST(DescriptorTest, CopyrightStuff)
{
    CopyrightDescriptor* desc = new CopyrightDescriptor((char*) copyrightDescriptorStuff, 1, nullptr);
    int identifier = desc->getCopyrightIdentifier();
    const CharVector *addi = desc->getAdditionalCopyrightInfo();
    CharVector a;
    a.resize(addi->size()+1);
    a.assign(addi->begin(), addi->end());

    EXPECT_EQ(0x12345678, identifier);

    char temp[] = {0x41, 0x42, 0x43, 0x44, 0x00};
    EXPECT_STREQ(temp, a.data());

    delete desc;
}

TEST(DescriptorTest, CopyrightStuff2)
{
    CopyrightDescriptor* desc = new CopyrightDescriptor((char*) copyrightDescriptorStuff2, 1, nullptr);
    int identifier = desc->getCopyrightIdentifier();
    const CharVector *addi = desc->getAdditionalCopyrightInfo();
    CharVector a;
    a.resize(addi->size()+1);
    a.assign(addi->begin(), addi->end());

    EXPECT_EQ(0x12345678, identifier);

    char temp[] = {0x00};
    EXPECT_STREQ(temp, a.data());
    EXPECT_EQ(0, addi->size());

    delete desc;
}
/* maximumBitrateDescriptor */
TEST(DescriptorTest, MaximumBitrate)
{
    MaximumBitrateDescriptor* desc = new MaximumBitrateDescriptor((char*) maximumBitrateDescriptor, 0, nullptr);
    int maxBitrate = desc->getMaximumBitrate();

    EXPECT_EQ(123456, maxBitrate);

    delete desc;

}

/* privateDataIndicatorDescriptor */
TEST(DescriptorTest, PrivateDataIndicator)
{
    PrivateDataIndicatorDescriptor* desc = new PrivateDataIndicatorDescriptor((char*) privateDataIndicatorDescriptor, 0, nullptr);
    int pri = desc->getPrivateDataIndicator();

    EXPECT_EQ(0xaabbccdd, pri);

    delete desc;
}

/* smoothingBufferDescriptor */
TEST(DescriptorTest, SmoothingBuffer)
{
    SmoothingBufferDescriptor* desc = new SmoothingBufferDescriptor((char*) smoothingBufferDescriptor, 0, nullptr);
    int tag = desc->getDescriptorTag();
    int len = desc->getDescriptorLength();
    int sbLeak = desc->getSbLeakRate();
    int sbSize = desc->getSbSize();

    EXPECT_EQ(0x10, tag);
    EXPECT_EQ(0x06, len);
    EXPECT_EQ(112233, sbLeak);
    EXPECT_EQ(4112233, sbSize);

    delete desc;
}

/* stdDescriptor */
TEST(DescriptorTest, Std)
{
    STDDescriptor* desc = new STDDescriptor((char*) stdDescriptor, 0, nullptr);
    bool leakValid = desc->getLeakValidFlag();

    EXPECT_TRUE(leakValid);

    delete desc;
}

/* avcVideoDescriptor */
TEST(DescriptorTest, AvcVideo)
{
    AVCVideoDescriptor* desc = new AVCVideoDescriptor((char*) avcVideoDescriptor, 0, nullptr);
    int profileIdc = desc->getProfileIdc();
    bool set0Flag = desc->getConstraintSet0Flag();
    bool set1Flag = desc->getConstraintSet1Flag();
    bool set2Flag = desc->getConstraintSet2Flag();
    int compatibleFlags = desc->getAvcCompatibleFlags();
    int levelIdc = desc->getLevelIdc();
    int stillPresent = desc->getAvcStillPresent();
    bool AVC24hour = desc->getAvc24hourPictureFlag();

    EXPECT_EQ(0x12, profileIdc);
    EXPECT_TRUE(set0Flag);
    EXPECT_TRUE(set1Flag);
    EXPECT_FALSE(set2Flag);
    EXPECT_EQ(0x0a, compatibleFlags);
    EXPECT_EQ(0x34, levelIdc);
    EXPECT_EQ(1, stillPresent);
    EXPECT_TRUE(AVC24hour);

    delete desc;

}

/* cellListDescriptor */
TEST(DescriptorTest, CellList)
{
    CellListDescriptor* desc = new CellListDescriptor((char*) cellListDescriptor, 0, nullptr);
    const CellVector* cells = desc->getCellVector();
    CellConstIterator cell = cells->begin();

    EXPECT_EQ(3, cells->size());

// 1st
    int cellId = (*cell)->getCellId();
    int cellLatitude = (*cell)->getCellLatitude();
    int cellLongitude = (*cell)->getCellLongitude();
    int cellExtentOfLatitude = (*cell)->getCellExtentOfLatitude();
    int cellExtentOfLongitude = (*cell)->getCellExtentOfLongitude();
    int subcellInfoLoopLength = (*cell)->getSubcellInfoLoopLength();
    EXPECT_EQ(1234, cellId);
    EXPECT_EQ(4567, cellLatitude);
    EXPECT_EQ(5678, cellLongitude);
    EXPECT_EQ(123, cellExtentOfLatitude);
    EXPECT_EQ(345, cellExtentOfLongitude);
    EXPECT_EQ(0, subcellInfoLoopLength);

// 2nd
    cell++;
    cellId = (*cell)->getCellId();
    cellLatitude = (*cell)->getCellLatitude();
    cellLongitude = (*cell)->getCellLongitude();
    cellExtentOfLatitude = (*cell)->getCellExtentOfLatitude();
    cellExtentOfLongitude = (*cell)->getCellExtentOfLongitude();
    subcellInfoLoopLength = (*cell)->getSubcellInfoLoopLength();
    EXPECT_EQ(4456, cellId);
    EXPECT_EQ(5567, cellLatitude);
    EXPECT_EQ(6678, cellLongitude);
    EXPECT_EQ(1234, cellExtentOfLatitude);
    EXPECT_EQ(1234, cellExtentOfLongitude);
    EXPECT_EQ(24, subcellInfoLoopLength);

        //subcell
        const SubCellVector* subcells = (*cell)->getSubCellVector();
        SubCellConstIterator subcell = subcells->begin();

        EXPECT_EQ(3, subcells->size());

        //1st
        int cellIdExtension = (*subcell)->getCellIdExtension();
        int subcellLatitude = (*subcell)->getSubcellLatitude();
        int subcellLongitude = (*subcell)->getSubcellLongitude();
        int subcellExtentOfLatitude = (*subcell)->getSubcellExtentOfLatitude();
        int subcellExtentOfLongitude = (*subcell)->getSubcellExtentOfLongitude();
        EXPECT_EQ(0, cellIdExtension);
        EXPECT_EQ(4386, subcellLatitude);
        EXPECT_EQ(13124, subcellLongitude);
        EXPECT_EQ(1383, subcellExtentOfLatitude);
        EXPECT_EQ(2202, subcellExtentOfLongitude);

        //2nd
        subcell++;
        cellIdExtension = (*subcell)->getCellIdExtension();
        subcellLatitude = (*subcell)->getSubcellLatitude();
        subcellLongitude = (*subcell)->getSubcellLongitude();
        subcellExtentOfLatitude = (*subcell)->getSubcellExtentOfLatitude();
        subcellExtentOfLongitude = (*subcell)->getSubcellExtentOfLongitude();
        EXPECT_EQ(1, cellIdExtension);
        EXPECT_EQ(8755, subcellLatitude);
        EXPECT_EQ(17493, subcellLongitude);
        EXPECT_EQ(1656, subcellExtentOfLatitude);
        EXPECT_EQ(2475, subcellExtentOfLongitude);

        //3rd
        subcell++;
        cellIdExtension = (*subcell)->getCellIdExtension();
        subcellLatitude = (*subcell)->getSubcellLatitude();
        subcellLongitude = (*subcell)->getSubcellLongitude();
        subcellExtentOfLatitude = (*subcell)->getSubcellExtentOfLatitude();
        subcellExtentOfLongitude = (*subcell)->getSubcellExtentOfLongitude();
        EXPECT_EQ(2, cellIdExtension);
        EXPECT_EQ(8755, subcellLatitude);
        EXPECT_EQ(17493, subcellLongitude);
        EXPECT_EQ(1656, subcellExtentOfLatitude);
        EXPECT_EQ(2475, subcellExtentOfLongitude);

        //end
        subcell++;
        EXPECT_EQ(subcell, subcells->end());
// 3rd
    cell++;
    cellId = (*cell)->getCellId();
    cellLatitude = (*cell)->getCellLatitude();
    cellLongitude = (*cell)->getCellLongitude();
    cellExtentOfLatitude = (*cell)->getCellExtentOfLatitude();
    cellExtentOfLongitude = (*cell)->getCellExtentOfLongitude();
    subcellInfoLoopLength = (*cell)->getSubcellInfoLoopLength();
    EXPECT_EQ(65535, cellId);
    EXPECT_EQ(61166, cellLatitude);
    EXPECT_EQ(56797, cellLongitude);
    EXPECT_EQ(1929, cellExtentOfLatitude);
    EXPECT_EQ(2748, cellExtentOfLongitude);
    EXPECT_EQ(8, subcellInfoLoopLength);

        //subcell
        subcells = (*cell)->getSubCellVector();
        subcell = subcells->begin();

        EXPECT_EQ(1, subcells->size());

        //1st
        cellIdExtension = (*subcell)->getCellIdExtension();
        subcellLatitude = (*subcell)->getSubcellLatitude();
        subcellLongitude = (*subcell)->getSubcellLongitude();
        subcellExtentOfLatitude = (*subcell)->getSubcellExtentOfLatitude();
        subcellExtentOfLongitude = (*subcell)->getSubcellExtentOfLongitude();
        EXPECT_EQ(0, cellIdExtension);
        EXPECT_EQ(4386, subcellLatitude);
        EXPECT_EQ(13124, subcellLongitude);
        EXPECT_EQ(1383, subcellExtentOfLatitude);
        EXPECT_EQ(2202, subcellExtentOfLongitude);

        //end
        subcell++;
        EXPECT_EQ(subcell, subcells->end());




// end
    cell++;
    EXPECT_EQ(cell, cells->end());

    delete desc;
}

/* s2SatelliteDeliverySystemDescriptor */
TEST(DescriptorTest, S2SatelliteDeliverySystem)
{
    S2SatelliteDeliverySystemDescriptor *desc = new S2SatelliteDeliverySystemDescriptor((char*)s2SatelliteDeliverySystemDescriptor, 0, nullptr);
    int scramblingSequenceSelector = desc->getScramblingSequenceSelector();
    bool multipleInputStreamFlag = desc->getmultipleInputStreamFlag();
    int backwardsCompatibilityIndicator = desc->getBackwardsCompatibilityIndicator();
    int scramblingSequenceIndex = desc->getScramblingSequenceIndex();
    int inputStreamidentifier = desc->getInputStreamidentifier();

    EXPECT_EQ(1, scramblingSequenceSelector);
    EXPECT_TRUE(multipleInputStreamFlag);
    EXPECT_EQ(1, backwardsCompatibilityIndicator);
    EXPECT_EQ(76770, scramblingSequenceIndex);
    EXPECT_EQ(12, inputStreamidentifier);

    delete desc;

}

/* defaultAuthorityDescriptor */
TEST(DescriptorTest, DefaultAuthority)
{
    DefaultAuthorityDescriptor* desc = new DefaultAuthorityDescriptor((char*)defaultAuthorityDescriptor, 0, nullptr);
    const CharVector *def = desc->getDefaultAuthorityByte();
    CharVector a;
    a.resize(def->size()+1);
    a.assign(def->begin(), def->end());
    EXPECT_EQ(4, def->size());
    char temp[] = {0xF1, 0x12, 0x23, 0x65, 0x00};
    EXPECT_STREQ(temp, a.data());

    delete desc;
}

TEST(DescriptorTest, DefaultAuthorityStuff)
{
    DefaultAuthorityDescriptor* desc = new DefaultAuthorityDescriptor((char*)defaultAuthorityDescriptorStuff, 2, nullptr);
    const CharVector *def = desc->getDefaultAuthorityByte();
    CharVector a;
    a.resize(def->size()+1);
    a.assign(def->begin(), def->end());
    EXPECT_EQ(4, def->size());
    char temp[] = {0xF1, 0x12, 0x23, 0x65, 0x00};
    EXPECT_STREQ(temp, a.data());

    delete desc;
}
/* contentIdentifierDescriptor */
TEST(DescriptorTest, ContentIdentifier)
{
    ContentIdentifierDescriptor* desc = new ContentIdentifierDescriptor((char*) contentIdentifierDescriptor, 0, nullptr);
    const CridVector *crids = desc->getCridVector();
    CridConstIterator crid = crids->begin();

    //1st
    int cridType = (*crid)->getCridType();
    int cridLocation = (*crid)->getCridLocation();
    const CharVector *cridByte = (*crid)->getCridByte();
    CharVector a;
    a.resize(cridByte->size() + 1);
    a.assign(cridByte->begin(), cridByte->end());

    EXPECT_EQ(0x01, cridType);
    EXPECT_EQ(0, cridLocation);
    EXPECT_EQ(4, cridByte->size());
    char temp[] = {0xF1, 0x12, 0x23, 0x65, 0x00};
    EXPECT_STREQ(temp, a.data());

    //2nd
    crid++;
    cridType = (*crid)->getCridType();
    cridLocation = (*crid)->getCridLocation();
    int cridRef = (*crid)->getCridRef();
    EXPECT_EQ(0x02, cridType);
    EXPECT_EQ(1, cridLocation);
    EXPECT_EQ(0xABCD, cridRef);


    //end
    crid++;
    EXPECT_EQ(crids->end(), crid);

    delete desc;
}

/* relatedContentDescriptor */
TEST(DescriptorTest, RelatedContent)
{
    RelatedContentDescriptor *desc = new RelatedContentDescriptor((char*)relatedContentDescriptor, 0, nullptr);
    int tag = desc->getDescriptorTag();
    int len = desc->getDescriptorLength();
    const CharVector *pri = desc->getPrivateDataByte();
    CharVector a;
    a.resize(pri->size() + 1);
    a.assign(pri->begin(), pri->end());
    char ttt[] = {0xf1, 0x12, 0x23, 0x00};

    EXPECT_EQ(0x74, tag);
    EXPECT_EQ(0x03, len);
    EXPECT_EQ(3, pri->size());
    EXPECT_STREQ(ttt, a.data());

    delete desc;

}

/* ftaContentManagementDescriptor */
TEST(DescriptorTest, FtaContentManagement)
{
    FTAContentManagementDescriptor *desc = new FTAContentManagementDescriptor((char*)ftaContentManagementDescriptor, 0, nullptr);
    int doNotScramble = desc->getDoNotScramble();
    int cont = desc->getControlRemoteAccessOverInternet();
    int donotApply = desc->getDoNotApplyRevocation();

    EXPECT_EQ(0, doNotScramble);
    EXPECT_EQ(1, cont);
    EXPECT_EQ(1, donotApply);

    delete desc;
}

/* carouselIdentifierDescriptor */
TEST(DescriptorTest, CarouselIdentifier1)
{
    CarouselIdentifierDescriptor *desc = new CarouselIdentifierDescriptor((char*)carouselIdentifierDescriptor, 0, nullptr);
    int carouselId = desc->getCarouselId();
    int formatId = desc->getFormatId();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    char temp[] = {0xab, 0xcd, 0x00};

    EXPECT_EQ(0x12345678, carouselId);
    EXPECT_EQ(0x00, formatId);
    EXPECT_EQ(2, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());

    //
        int moduleVersion = desc->getModuleVersion();
        int moduleId = desc->getModuleId();
        int blockSize = desc->getBlockSize();
        int moduleSize = desc->getModuleSize();
        int compressionMethod = desc->getCompressionMethod();
        int originalSize = desc->getOriginalSize();
        int timeout = desc->getTimeOut();
        int objectKeyLength = desc->getObjectKeyLength();
        const CharVector* objectKeyData = desc->getObjectKeyData();
        CharVector b;
        b.resize(objectKeyData->size() + 1);
        b.assign(objectKeyData->begin(), objectKeyData->end());
        char temp2[] = {0x00};

        EXPECT_EQ(0, moduleVersion);
        EXPECT_EQ(0, moduleId);
        EXPECT_EQ(0, blockSize);
        EXPECT_EQ(0, moduleSize);
        EXPECT_EQ(0, compressionMethod);
        EXPECT_EQ(0, originalSize);
        EXPECT_EQ(0, timeout);
        EXPECT_EQ(0, objectKeyLength);
        EXPECT_EQ(0, objectKeyData->size());
        EXPECT_STREQ(temp2, b.data());


    //
    delete desc;

}

TEST(DescriptorTest, CarouselIdentifierStuff1)
{
    CarouselIdentifierDescriptor *desc = new CarouselIdentifierDescriptor((char*)carouselIdentifierDescriptorStuff, 2, nullptr);
    int carouselId = desc->getCarouselId();
    int formatId = desc->getFormatId();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    char temp[] = {0xab, 0xcd, 0x00};

    EXPECT_EQ(0x12345678, carouselId);
    EXPECT_EQ(0x00, formatId);
    EXPECT_EQ(2, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());

    //
        int moduleVersion = desc->getModuleVersion();
        int moduleId = desc->getModuleId();
        int blockSize = desc->getBlockSize();
        int moduleSize = desc->getModuleSize();
        int compressionMethod = desc->getCompressionMethod();
        int originalSize = desc->getOriginalSize();
        int timeout = desc->getTimeOut();
        int objectKeyLength = desc->getObjectKeyLength();
        const CharVector* objectKeyData = desc->getObjectKeyData();
        CharVector b;
        b.resize(objectKeyData->size() + 1);
        b.assign(objectKeyData->begin(), objectKeyData->end());
        char temp2[] = {0x00};

        EXPECT_EQ(0, moduleVersion);
        EXPECT_EQ(0, moduleId);
        EXPECT_EQ(0, blockSize);
        EXPECT_EQ(0, moduleSize);
        EXPECT_EQ(0, compressionMethod);
        EXPECT_EQ(0, originalSize);
        EXPECT_EQ(0, timeout);
        EXPECT_EQ(0, objectKeyLength);
        EXPECT_EQ(0, objectKeyData->size());
        EXPECT_STREQ(temp2, b.data());


    //
    delete desc;

}


TEST(DescriptorTest, CarouselIdentifier2)
{
    CarouselIdentifierDescriptor *desc = new CarouselIdentifierDescriptor((char*)carouselIdentifierDescriptor2, 0, nullptr);
    int carouselId = desc->getCarouselId();
    int formatId = desc->getFormatId();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    char temp[] = {0xab, 0xcd, 0x00};

    EXPECT_EQ(0x56781211, carouselId);
    EXPECT_EQ(0x01, formatId);
    EXPECT_EQ(2, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());

//
    int moduleVersion = desc->getModuleVersion();
    int moduleId = desc->getModuleId();
    int blockSize = desc->getBlockSize();
    int moduleSize = desc->getModuleSize();
    int compressionMethod = desc->getCompressionMethod();
    int originalSize = desc->getOriginalSize();
    int timeout = desc->getTimeOut();
    int objectKeyLength = desc->getObjectKeyLength();
    const CharVector* objectKeyData = desc->getObjectKeyData();
    CharVector b;
    b.resize(objectKeyData->size() + 1);
    b.assign(objectKeyData->begin(), objectKeyData->end());
    char temp2[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x00};

    EXPECT_EQ(0x01, moduleVersion);
    EXPECT_EQ(0x02ab, moduleId);
    EXPECT_EQ(0x1021, blockSize);
    EXPECT_EQ(0xabcdff97, moduleSize);
    EXPECT_EQ(0x09, compressionMethod);
    EXPECT_EQ(0xffffffff, originalSize);
    EXPECT_EQ(0xDE, timeout);
    EXPECT_EQ(0x05, objectKeyLength);
    EXPECT_EQ(0x05, objectKeyData->size());
    EXPECT_STREQ(temp2, b.data());


//
    delete desc;

}


TEST(DescriptorTest, CarouselIdentifierStuff2)
{
    CarouselIdentifierDescriptor *desc = new CarouselIdentifierDescriptor((char*)carouselIdentifierDescriptorStuff2, 1, nullptr);
    int carouselId = desc->getCarouselId();
    int formatId = desc->getFormatId();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    char temp[] = {0xab, 0xcd, 0x00};

    EXPECT_EQ(0x56781211, carouselId);
    EXPECT_EQ(0x01, formatId);
    EXPECT_EQ(2, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());

//
    int moduleVersion = desc->getModuleVersion();
    int moduleId = desc->getModuleId();
    int blockSize = desc->getBlockSize();
    int moduleSize = desc->getModuleSize();
    int compressionMethod = desc->getCompressionMethod();
    int originalSize = desc->getOriginalSize();
    int timeout = desc->getTimeOut();
    int objectKeyLength = desc->getObjectKeyLength();
    const CharVector* objectKeyData = desc->getObjectKeyData();
    CharVector b;
    b.resize(objectKeyData->size() + 1);
    b.assign(objectKeyData->begin(), objectKeyData->end());
    char temp2[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x00};

    EXPECT_EQ(0x01, moduleVersion);
    EXPECT_EQ(0x02ab, moduleId);
    EXPECT_EQ(0x1021, blockSize);
    EXPECT_EQ(0xabcdff97, moduleSize);
    EXPECT_EQ(0x09, compressionMethod);
    EXPECT_EQ(0xffffffff, originalSize);
    EXPECT_EQ(0xDE, timeout);
    EXPECT_EQ(0x05, objectKeyLength);
    EXPECT_EQ(0x05, objectKeyData->size());
    EXPECT_STREQ(temp2, b.data());


//
    delete desc;

}

TEST(DescriptorTest, CarouselIdentifierStuff3)
{
    CarouselIdentifierDescriptor *desc = new CarouselIdentifierDescriptor((char*)carouselIdentifierDescriptorStuff3, 1, nullptr);
    int carouselId = desc->getCarouselId();
    int formatId = desc->getFormatId();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    char temp[] = {0xab, 0x00};

    EXPECT_EQ(0x56781211, carouselId);
    EXPECT_EQ(0x01, formatId);
    EXPECT_EQ(1, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());

//
    int moduleVersion = desc->getModuleVersion();
    int moduleId = desc->getModuleId();
    int blockSize = desc->getBlockSize();
    int moduleSize = desc->getModuleSize();
    int compressionMethod = desc->getCompressionMethod();
    int originalSize = desc->getOriginalSize();
    int timeout = desc->getTimeOut();
    int objectKeyLength = desc->getObjectKeyLength();
    const CharVector* objectKeyData = desc->getObjectKeyData();
    CharVector b;
    b.resize(objectKeyData->size() + 1);
    b.assign(objectKeyData->begin(), objectKeyData->end());
    char temp2[] = {0x01, 0x02, 0x03, 0x04, 0x00};

    EXPECT_EQ(0x01, moduleVersion);
    EXPECT_EQ(0x02ab, moduleId);
    EXPECT_EQ(0x1021, blockSize);
    EXPECT_EQ(0xabcdff97, moduleSize);
    EXPECT_EQ(0x09, compressionMethod);
    EXPECT_EQ(0xffffffff, originalSize);
    EXPECT_EQ(0xDE, timeout);
    EXPECT_EQ(0x04, objectKeyLength);
    EXPECT_EQ(0x04, objectKeyData->size());
    EXPECT_STREQ(temp2, b.data());


//
    delete desc;

}


/* associationTagDescriptor */
TEST(DescriptorTest, AssociationTag)
{
    AssociationTagDescriptor* desc = new AssociationTagDescriptor((char*)associationTagDescriptor, 0, nullptr);

    int associationTag = desc->getAssociationTag();
    int use = desc->getUse();
    int selectorLength = desc->getSelectorLength();
    int transactionId = desc->getTransactionId();
    int timeout = desc->getTimeout();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    const CharVector* selectorByte = desc->getSelectorByte();
    CharVector b;
    b.resize(selectorByte->size() + 1);
    b.assign(selectorByte->begin(), selectorByte->end());

    EXPECT_EQ(0x1122, associationTag);
    EXPECT_EQ(0x0000, use);
    EXPECT_EQ(0x02, selectorLength);
    EXPECT_EQ(0x12345678, transactionId);
    EXPECT_EQ(0x11223344, timeout);
    char temp[] = {0x99, 0x88, 0x00};
    EXPECT_EQ(2, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());
    char temp2[] = {0x00};
    EXPECT_EQ(0, selectorByte->size());
    EXPECT_STREQ(temp2, b.data());

    delete desc;

}

TEST(DescriptorTest, AssociationTagStuff)
{
    AssociationTagDescriptor* desc = new AssociationTagDescriptor((char*)associationTagDescriptorStuff, 2, nullptr);

    int associationTag = desc->getAssociationTag();
    int use = desc->getUse();
    int selectorLength = desc->getSelectorLength();
    int transactionId = desc->getTransactionId();
    int timeout = desc->getTimeout();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    const CharVector* selectorByte = desc->getSelectorByte();
    CharVector b;
    b.resize(selectorByte->size() + 1);
    b.assign(selectorByte->begin(), selectorByte->end());

    EXPECT_EQ(0x1122, associationTag);
    EXPECT_EQ(0x0000, use);
    EXPECT_EQ(0x02, selectorLength);
    EXPECT_EQ(0x12345678, transactionId);
    EXPECT_EQ(0x11223344, timeout);
    char temp[] = {0x99, 0x00};
    EXPECT_EQ(1, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());
    char temp2[] = {0x00};
    EXPECT_EQ(0, selectorByte->size());
    EXPECT_STREQ(temp2, b.data());

    delete desc;

}

TEST(DescriptorTest, AssociationTag2)
{
    AssociationTagDescriptor* desc = new AssociationTagDescriptor((char*)associationTagDescriptor2, 0, nullptr);

    int associationTag = desc->getAssociationTag();
    int use = desc->getUse();
    int selectorLength = desc->getSelectorLength();
    int transactionId = desc->getTransactionId();
    int timeout = desc->getTimeout();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    const CharVector* selectorByte = desc->getSelectorByte();
    CharVector b;
    b.resize(selectorByte->size() + 1);
    b.assign(selectorByte->begin(), selectorByte->end());

    EXPECT_EQ(0x7842, associationTag);
    EXPECT_EQ(0x0001, use);
    EXPECT_EQ(0x03, selectorLength);
    EXPECT_EQ(0, transactionId);
    EXPECT_EQ(0, timeout);
    char temp[] = {0x99, 0x88, 0xff, 0x99, 0x00};
    EXPECT_EQ(4, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());
    char temp2[] = {0x00};
    EXPECT_EQ(0, selectorByte->size());
    EXPECT_STREQ(temp2, b.data());

    delete desc;

}

TEST(DescriptorTest, AssociationTagStuff2)
{
    AssociationTagDescriptor* desc = new AssociationTagDescriptor((char*)associationTagDescriptorStuff2, 2, nullptr);

    int associationTag = desc->getAssociationTag();
    int use = desc->getUse();
    int selectorLength = desc->getSelectorLength();
    int transactionId = desc->getTransactionId();
    int timeout = desc->getTimeout();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    const CharVector* selectorByte = desc->getSelectorByte();
    CharVector b;
    b.resize(selectorByte->size() + 1);
    b.assign(selectorByte->begin(), selectorByte->end());

    EXPECT_EQ(0x7842, associationTag);
    EXPECT_EQ(0x0001, use);
    EXPECT_EQ(0x03, selectorLength);
    EXPECT_EQ(0, transactionId);
    EXPECT_EQ(0, timeout);
    char temp[] = {0x99, 0x88, 0xff, 0x99, 0x00};
    EXPECT_EQ(4, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());
    char temp2[] = {0x00};
    EXPECT_EQ(0, selectorByte->size());
    EXPECT_STREQ(temp2, b.data());

    delete desc;

}

TEST(DescriptorTest, AssociationTag3)
{
    AssociationTagDescriptor* desc = new AssociationTagDescriptor((char*)associationTagDescriptor3, 0, nullptr);

    int associationTag = desc->getAssociationTag();
    int use = desc->getUse();
    int selectorLength = desc->getSelectorLength();
    int transactionId = desc->getTransactionId();
    int timeout = desc->getTimeout();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    const CharVector* selectorByte = desc->getSelectorByte();
    CharVector b;
    b.resize(selectorByte->size() + 1);
    b.assign(selectorByte->begin(), selectorByte->end());

    EXPECT_EQ(0xd12f, associationTag);
    EXPECT_EQ(0x1122, use);
    EXPECT_EQ(4, selectorLength);
    EXPECT_EQ(0, transactionId);
    EXPECT_EQ(0, timeout);
    char temp[] = {0x99, 0x88, 0x00};
    EXPECT_EQ(2, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());
    char temp2[] = {0x11, 0x22, 0x33, 0x44, 0x00};
    EXPECT_EQ(4, selectorByte->size());
    EXPECT_STREQ(temp2, b.data());

    delete desc;

}

TEST(DescriptorTest, AssociationTagStuff3)
{
    AssociationTagDescriptor* desc = new AssociationTagDescriptor((char*)associationTagDescriptorStuff3, 1, nullptr);

    int associationTag = desc->getAssociationTag();
    int use = desc->getUse();
    int selectorLength = desc->getSelectorLength();
    int transactionId = desc->getTransactionId();
    int timeout = desc->getTimeout();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());
    const CharVector* selectorByte = desc->getSelectorByte();
    CharVector b;
    b.resize(selectorByte->size() + 1);
    b.assign(selectorByte->begin(), selectorByte->end());

    EXPECT_EQ(0xd12f, associationTag);
    EXPECT_EQ(0x1122, use);
    EXPECT_EQ(4, selectorLength);
    EXPECT_EQ(0, transactionId);
    EXPECT_EQ(0, timeout);
    char temp[] = {0x99, 0x88, 0x00};
    EXPECT_EQ(2, privateDataByte->size());
    EXPECT_STREQ(temp, a.data());
    char temp2[] = {0x11, 0x22, 0x33, 0x44, 0x00};
    EXPECT_EQ(4, selectorByte->size());
    EXPECT_STREQ(temp2, b.data());

    delete desc;

}


/* deferredAssociationTagDescriptor */
TEST(DescriptorTest, DeferredAssociationTag)
{
    DeferredAssociationTagDescriptor* desc = new DeferredAssociationTagDescriptor((char*)deferredAssociationTagDescriptor, 0, nullptr);
    int associationTagsLoopLength = desc->getAssociationTagsLoopLength();
    AssociationTagVector *tags = desc->getAssociationTagVector();
    AssociationTagConstIterator tag = tags->begin();
    int transportStreamId = desc->getTransportStreamId();
    int programNumber = desc->getProgramNumber();
    int onid = desc->getOriginalNetworkId();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());

    EXPECT_EQ(6, associationTagsLoopLength);

// association tag
    EXPECT_EQ(3, tags->size());

    int associationTag = (*tag)->getAssociationTag();
    EXPECT_EQ(0x1122, associationTag);

    tag++;
    associationTag = (*tag)->getAssociationTag();
    EXPECT_EQ(0x33ff, associationTag);

    tag++;
    associationTag = (*tag)->getAssociationTag();
    EXPECT_EQ(0xddaa, associationTag);

    tag++;
    EXPECT_EQ(tags->end(), tag);
//

    EXPECT_EQ(0x9abc, transportStreamId);
    EXPECT_EQ(0x1234, programNumber);
    EXPECT_EQ(0x9988, onid);

    EXPECT_EQ(3, privateDataByte->size());
    char temp[] = {0x99, 0x88, 0x77, 0x00};
    EXPECT_STREQ(temp, a.data());

    delete desc;
}

TEST(DescriptorTest, DeferredAssociationTagStuff)
{
    DeferredAssociationTagDescriptor* desc = new DeferredAssociationTagDescriptor((char*)deferredAssociationTagDescriptorStuff, 1, nullptr);
    int associationTagsLoopLength = desc->getAssociationTagsLoopLength();
    AssociationTagVector *tags = desc->getAssociationTagVector();
    AssociationTagConstIterator tag = tags->begin();
    int transportStreamId = desc->getTransportStreamId();
    int programNumber = desc->getProgramNumber();
    int onid = desc->getOriginalNetworkId();
    const CharVector* privateDataByte = desc->getPrivateDataByte();
    CharVector a;
    a.resize(privateDataByte->size() + 1);
    a.assign(privateDataByte->begin(), privateDataByte->end());

    EXPECT_EQ(6, associationTagsLoopLength);

// association tag
    EXPECT_EQ(3, tags->size());

    int associationTag = (*tag)->getAssociationTag();
    EXPECT_EQ(0x1122, associationTag);

    tag++;
    associationTag = (*tag)->getAssociationTag();
    EXPECT_EQ(0x33ff, associationTag);

    tag++;
    associationTag = (*tag)->getAssociationTag();
    EXPECT_EQ(0xddaa, associationTag);

    tag++;
    EXPECT_EQ(tags->end(), tag);
//

    EXPECT_EQ(0x9abc, transportStreamId);
    EXPECT_EQ(0x1234, programNumber);
    EXPECT_EQ(0x9988, onid);

    EXPECT_EQ(3, privateDataByte->size());
    char temp[] = {0x99, 0x88, 0x77, 0x00};
    EXPECT_STREQ(temp, a.data());

    delete desc;
}

/* applicationSignallingDescriptor */
TEST(DescriptorTest, ApplicationSignalling)
{
    ApplicationSignallingDescriptor* desc = new ApplicationSignallingDescriptor((char*)applicationSignallingDescriptor, 0, nullptr);
    ApplicationTypeVector* apps = desc->getApplicationTypeVector();
    ApplicationTypeConstIterator app = apps->begin();

    EXPECT_EQ(3, apps->size());

    int apptype = (*app)->getApplicationType();
    int aitVersionNumber = (*app)->getAitVersionNumber();
    EXPECT_EQ(4386, apptype);
    EXPECT_EQ(1, aitVersionNumber);

    app++;
    apptype = (*app)->getApplicationType();
    aitVersionNumber = (*app)->getAitVersionNumber();
    EXPECT_EQ(8755, apptype);
    EXPECT_EQ(2, aitVersionNumber);

    app++;
    apptype = (*app)->getApplicationType();
    aitVersionNumber = (*app)->getAitVersionNumber();
    EXPECT_EQ(32580, apptype);
    EXPECT_EQ(26, aitVersionNumber);

    app++;
    EXPECT_EQ(apps->end(), app);

    delete desc;
}

/* extensionDescriptor */
TEST(DescriptorTest, Extension)
{
    ExtensionDescriptor* desc = new ExtensionDescriptor((char*)extensionDescriptor, 0, nullptr);
    int exTag = desc->getDescriptorTagExtension();
    CharVector* sel = desc->getSelectorByte();
    CharVector a;
    a.resize(sel->size() + 1);
    a.assign(sel->begin(), sel->end());
    char temp[] = {0x11, 0x22, 0x33, 0x44, 0x00};

    EXPECT_EQ(0x06, exTag);
    EXPECT_EQ(4, sel->size());
    EXPECT_STREQ(temp, a.data());

    delete desc;
}

TEST(DescriptorTest, ExtensionStuff)
{
    ExtensionDescriptor* desc = new ExtensionDescriptor((char*)extensionDescriptorStuff, 2, nullptr);
    int exTag = desc->getDescriptorTagExtension();
    CharVector* sel = desc->getSelectorByte();
    CharVector a;
    a.resize(sel->size() + 1);
    a.assign(sel->begin(), sel->end());
    char temp[] = {0x11, 0x22, 0x33, 0x44, 0x00};

    EXPECT_EQ(0x06, exTag);
    EXPECT_EQ(4, sel->size());
    EXPECT_STREQ(temp, a.data());

    delete desc;
}




