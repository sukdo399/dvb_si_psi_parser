/*
 *Original Author:	shko
 */

#ifndef DESCRIPTORBUILDER_H
#define DESCRIPTORBUILDER_H

#include "descriptor.h"

#include "subtitlingdescriptor.h"
#include "networknamedescriptor.h"
#include "servicelistdescriptor.h"
#include "servicedescriptor.h"
#include "shorteventdescriptor.h"
#include "extendedeventdescriptor.h"
#include "parentalratingdescriptor.h"
#include "localtimeoffsetdescriptor.h"
#include "satellitedeliverysystemdescriptor.h"
#include "cabledeliverysystemdescriptor.h"
#include "terrestrialdeliverysystemdescriptor.h"
#include "bouquetnamedescriptor.h"
#include "countryavailabilitydescriptor.h"
#include "linkagedescriptor.h"
#include "componentdescriptor.h"
#include "timeshiftedservicedescriptor.h"
#include "timeshiftedeventdescriptor.h"
#include "streamIdentifierdescriptor.h"
#include "caidentifierdescriptor.h"
#include "contentdescriptor.h"
#include "privatedataspecifierdescriptor.h"
#include "servicemovedescriptor.h"
#include "frequencylistdescriptor.h"
#include "partialtransportstreamdescriptor.h"
#include "nvodreferencedescriptor.h"
#include "teletextdescriptor.h"
#include "multilingualnetworknamedescriptor.h"
#include "multilingualbouquetnamedescriptor.h"
#include "multilingualservicenamedescriptor.h"
#include "mosaicdescriptor.h"
#include "telephonedescriptor.h"
#include "multilingualcomponentdescriptor.h"
#include "pdcdescriptor.h"
#include "ancillarydatadescriptor.h"
#include "shortsmoothingbufferdescriptor.h"
#include "databroadcastdescriptor.h"
#include "databroadcastiddescriptor.h"
#include "ac3descriptor.h"
#include "enhancedac3descriptor.h"
#include "aacdescriptor.h"
#include "celllistdescriptor.h"
#include "s2satellitedeliverysystemdescriptor.h"
#include "ftacontentmanagementdescriptor.h"
#include "extensiondescriptor.h"

// ts 102 323
#include "defaultauthoritydescriptor.h"
#include "contentidentifierdescriptor.h"
#include "relatedcontentdescriptor.h"

// 13818-1
#include "videostreamdescriptor.h"
#include "audiostreamdescriptor.h"
#include "hierarchydescriptor.h"
#include "registrationdescriptor.h"
#include "datastreamalignmentdescriptor.h"
#include "targetbackgroundgriddescriptor.h"
#include "videowindowdescriptor.h"
#include "conditionalaccessdescriptor.h"
#include "iso639languagedescriptor.h"
#include "systemclockdescriptor.h"
#include "multiplexbufferutilizationdescriptor.h"
#include "copyrightdescriptor.h"
#include "maximumbitratedescriptor.h"
#include "privatedataindicatordescriptor.h"
#include "smoothingbufferdescriptor.h"
#include "stddescriptor.h"
#include "avcvideodescriptor.h"

// 13818-6, tr 101 202
#include "carouselidentifierdescriptor.h"
#include "associationtagdescriptor.h"
#include "deferredassociationtagdescriptor.h"

//ts 102 809
#include "applicationsignallingdescriptor.h"


class DescriptorBuilder
{


private:
    DescriptorBuilder();

public:
    static DescriptorVector buildDescriptorVector(const char* data, const int offset, const int len, TableSection* tableSection);

private:
    static DescriptorVector buildDescriptorVectorInner(const char* data, const int offset, const int len, TableSection* tableSection);

    static Descriptor *getPrivateDVBSIDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t, const int);
    static Descriptor *getDVBSIDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t);
    static Descriptor *getMPEGDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t);
    static Descriptor *getUNTDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t);
    static Descriptor *getAITDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t);
};
#endif // DESCRIPTORBUILDER_H
