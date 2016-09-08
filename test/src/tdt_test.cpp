/*
 *Original Author:	shko
 */


//hdvblib

#include <tdt.h>

//google test
#include <gtest.h>

//hdvblib_test
#include "tdt_test.h"


/* TDT */
TEST(PsiTest, Tdt)
{
    TDT *tdt = new TDT((char*)tdttest);

    EXPECT_EQ(TABLEID_TDT, tdt->getTableId());

    const CharVector *utcTime = tdt->getUtcTime();
    CharVector a;
    a.resize(utcTime->size()+1);
    a.assign(utcTime->begin(), utcTime->end());
    char temp[] = {0xda, 0x0e, 0x11, 0x40, 0x10};
    EXPECT_STREQ(temp, a.data());
    EXPECT_EQ(5, utcTime->size());


    EXPECT_EQ(55822, tdt->getUtcTimeMjd());
    EXPECT_EQ(114010, tdt->getUtcTimeBcd());



    EXPECT_FALSE(tdt->getCrcError());


    delete tdt;

}



