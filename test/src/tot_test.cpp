/*
 *Original Author:	shko
 */


//hdvblib

#include <tot.h>

//google test
#include <gtest.h>

//hdvblib_test
#include "tot_test.h"


/* TOT */
TEST(PsiTest, Tot)
{
    TOT *tot = new TOT((char*)tottest);

    EXPECT_EQ(TABLEID_TOT, tot->getTableId());

    const CharVector *utcTime = tot->getUtcTime();
    CharVector a;
    a.resize(utcTime->size()+1);
    a.assign(utcTime->begin(), utcTime->end());
    char temp[] = {0xda, 0x0e, 0x11, 0x40, 0x10};
    EXPECT_STREQ(temp, a.data());
    EXPECT_EQ(5, utcTime->size());


    EXPECT_EQ(55822, tot->getUtcTimeMjd());
    EXPECT_EQ(114010, tot->getUtcTimeBcd());

// descriptor
    DescriptorVector *desc = tot->getDescriptorVector();
    DescriptorConstIterator descIter = desc->begin();

    LocalTimeOffsetDescriptor *localTimeOffsetDesc = (LocalTimeOffsetDescriptor*)(*descIter);
    const LocalTimeOffsetVector *offsets = localTimeOffsetDesc->getLocalOffsetVector();
    LocalTimeOffsetConstIterator iter = offsets->begin();

    // 1st.
    std::string countryCode = (*iter)->getCountryCode();
    int regionId = (*iter)->getCountryRegionId();
    int polarity = (*iter)->getLocalTimeOffsetPolarity();
    int timeOffset = (*iter)->getLocalTimeOffset();
    int timeOfChangeMjd = (*iter)->getTimeOfChangeMjd();
    int timeOfChangeBcd = (*iter)->getTimeOfChangeBcd();
    int nextTimeOffset = (*iter)->getNextTimeOffset();

    EXPECT_STREQ("kor", countryCode.c_str());
    EXPECT_EQ(0, regionId);
    EXPECT_EQ(0, polarity);
    EXPECT_EQ(1234, timeOffset);
    EXPECT_EQ(56828, timeOfChangeMjd);
    // TODO:
    EXPECT_EQ(111740, timeOfChangeBcd);
    EXPECT_EQ(852, nextTimeOffset);

//end
    iter++;
    EXPECT_EQ(offsets->end(), iter);



    EXPECT_FALSE(tot->getCrcError());


    delete tot;

}


