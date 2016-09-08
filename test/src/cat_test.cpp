
/*
 *Original Author:	shko
 */




//hdvblib

#include <cat.h>

//google test
#include <gtest.h>

//hdvblib_test
#include "cat_test.h"






/* CAT */
TEST(PsiTest, Cat)
{

    CAT *cat = new CAT((char*)cattest);

    EXPECT_EQ(TABLEID_CAT, cat->getTableId());

    //descriptor loop
    DescriptorVector* loops = cat->getDescriptorVector();
    DescriptorConstIterator desc = loops->begin();

    ConditionalAccessDescriptor* ca = (ConditionalAccessDescriptor*)*desc;
    EXPECT_EQ(TAG_CONDITIONAL_ACCESS, ca->getDescriptorTag());
    EXPECT_EQ(0x1020, ca->getCaSystemID());
    EXPECT_EQ(0x1890, ca->getCaPID());

    desc++;
    EXPECT_EQ(loops->end(), desc);

    //

    EXPECT_EQ(1, cat->getVersionNumber());
    EXPECT_EQ(0, cat->getSectionNumber());
    EXPECT_EQ(1, cat->getLastSectionNumber());

    EXPECT_FALSE(cat->getCrcError());


    delete cat;

}


