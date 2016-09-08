/*
 *Original Author:	shko
 */




//hdvblib

#include <pmt.h>

//google test
#include <gtest.h>

//hdvblib_test
#include "pmt_test.h"






/* PMT */
TEST(PsiTest, Pmt)
{
    PMT *pmt = new PMT((char*)PMT_out);

    EXPECT_EQ(TABLEID_PMT, pmt->getTableId());

    EXPECT_EQ(1, pmt->getProgramNumber());
    EXPECT_EQ(2064, pmt->getPcrPid());

    PMTElementaryStreamInfoVector *esInfoList = pmt->getElementaryStreamInfoVector();
    PMTElementaryStreamInfoConstIterator iterPos = esInfoList->begin();

//1st
    PMT::ElementaryStreamInfo *esInfo = *iterPos;
    EXPECT_EQ(2, esInfo->getStreamtype());
    EXPECT_EQ(2064, esInfo->getElementaryPID());

//2nd
    iterPos++;
    esInfo = *iterPos;
    EXPECT_EQ(4, esInfo->getStreamtype());
    EXPECT_EQ(2068, esInfo->getElementaryPID());

//3rd
    iterPos++;
    esInfo = *iterPos;
    EXPECT_EQ(6, esInfo->getStreamtype());
    EXPECT_EQ(1011, esInfo->getElementaryPID());


        DescriptorVector *descVector = (DescriptorVector *)esInfo->getDescriptorVector();

        //1st
        DescriptorIterator descIterPos = descVector->begin();
        Descriptor *desc = *descIterPos;
        EXPECT_EQ(0x59, desc->getDescriptorTag());

        SubtitlingDescriptor *subtitilingDesc = (SubtitlingDescriptor *)desc;
        SubtitleVector *subtitleVector = (std::vector<SubtitlingDescriptor::Subtitle*> *)subtitilingDesc->getSubtitleVector();

            //1st
            SubtitleIterator subtitlingIterPos = subtitleVector->begin();
            SubtitlingDescriptor::Subtitle *subtitling = *subtitlingIterPos;
            EXPECT_STREQ("kor", subtitling->getIso639LanguageCode().c_str());
            EXPECT_EQ(0x10, subtitling->getSubtitlingType());
            EXPECT_EQ(1, subtitling->getCompositionPageId());
            EXPECT_EQ(1, subtitling->getAncillaryPageId());

            //end
            subtitlingIterPos++;
            EXPECT_EQ(subtitleVector->end(), subtitlingIterPos);

        //end
        descIterPos++;
        EXPECT_EQ(descVector->end(), descIterPos);

//end
    iterPos++;
    EXPECT_EQ(esInfoList->end(), iterPos);


    EXPECT_EQ(1, pmt->getVersionNumber());
    EXPECT_EQ(0, pmt->getSectionNumber());
    EXPECT_EQ(0, pmt->getLastSectionNumber());

    EXPECT_FALSE(pmt->getCrcError());

    EXPECT_EQ(3, pmt->getNumberOfStreams());

    EXPECT_EQ(2064, pmt->getElementaryPID(0));
    EXPECT_EQ(2068, pmt->getElementaryPID(1));
    EXPECT_EQ(1011, pmt->getElementaryPID(2));

    delete pmt;
}

#if 0
TEST(PsiTest, Pmt)
{

    cout << "main called \n" << endl;
//    PMT *pmt0 = new PMT(PMT_out); // without spec. default is eSiSpec_NONE
    PMT *pmt = new PMT(PMT_out, eSiSpec_ZIGGO); // with spec.
//    PMT *pmt2 = new PMT(PMT_out);

    cout << "\n programNumber: " << pmt->getProgramNumber();
    cout << "\n pcrPid: " << pmt->getPcrPid();

    ElementaryStreamInfoVector *esInfoList = pmt->getElementaryStreamInfoVector();


    for( PMTElementaryStreamInfoIterator iterPos = esInfoList->begin(); iterPos != esInfoList->end(); ++iterPos )
    {

        PMT::ElementaryStreamInfo *esInfo = *iterPos;
        cout << "\n\t streamType: " << dec << (int)esInfo->getStreamtype();
        cout << "\n\t elementaryPid: " << esInfo->getElementaryPID();

        DescriptorVector *descVector = (DescriptorVector *)esInfo->getDescriptorVector();

        for( DescriptorIterator descIterPos = descVector->begin(); descIterPos != descVector->end(); ++descIterPos)
        {

            Descriptor *desc = *descIterPos;
            cout << "\n\t\t descriptorTag: 0x" << hex << (int)desc->getDescriptorTag();

            if(desc->getDescriptorTag() == 0x59)
            {

                //if 0x59, subtitling desc.
                SubtitlingDescriptor *subtitilingDesc = (SubtitlingDescriptor *)desc;
                SubtitleVector *subtitleVector = (SubtitleVector *)subtitilingDesc->getSubtitleVector();
                for( SubtitleIterator subtitlingIterPos = subtitleVector->begin(); subtitlingIterPos != subtitleVector->end(); ++subtitlingIterPos )
                {


                    SubtitlingDescriptor::Subtitle *subtitling = *subtitlingIterPos;

                    cout << "\n\t\t\t subtitlingType: 0x" << hex << (int)subtitling->getSubtitlingType();
                    cout << "\n\t\t\t iso639LanguageCode: " << subtitling->getIso639LanguageCode();
                    cout << "\n\t\t\t ancillaryPageId: " << dec << subtitling->getAncillaryPageId();
                    cout << "\n\t\t\t compositionPageId: " << dec << subtitling->getCompositionPageId();

                }
                cout << endl;

            }


        }
        cout << endl;
    }

    cout << "\n versionNumber: " << dec << (int)pmt->getVersion();
    cout << "\n currentNextIndicator: " << dec << (int)pmt->getCurrentNext();
    cout << "\n sectionNumber: " << dec << (int)pmt->getSectionNumber();
    cout << "\n lastSectionNumber: " << dec << (int)pmt->getSectionLastNumber();

    cout << "\n crc: " << hex << pmt->getCrc();
    cout << "\n crc error: " << hex << pmt->getCrcError();

    cout << endl;

//    delete pmt0;
    delete pmt;
//    delete pmt2;


}
#endif

