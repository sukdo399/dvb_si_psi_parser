/*
 *Original Author:	shko
 */

#include "descriptorbuilder.h"



DescriptorBuilder::DescriptorBuilder()
{
    // private. do not inherit
}



DescriptorVector DescriptorBuilder::buildDescriptorVector(const char* data, const int offset, const int len, TableSection* tableSection)
{

    int sispec = tableSection->getSiSpec();

    DescriptorVector r = DescriptorVector();
    int t = 0;

    while (t < len)
    {

        Descriptor *d;
        const int descriptorTag = Utils::getUnsignedByte(data[t + offset]);

        /*
         TODO: branch depends on categories...
         // 1. 0x00 - 0x3F: ITU-T Rec. H.222.0 | ISO/IEC 13818-1
         // 2. 0x40 - 0x7F: ETSI EN 300 468 V1.5.1 (2003-05)
         // 3. 0x80 - 0xFE: Private (User defined)
         */
        if (descriptorTag <= 0x3F)
        {
            if (tableSection->getTableId() == TABLEID_UNT)
            {
                d = getUNTDescriptor(data, offset, tableSection, t);
            }
            else if (tableSection->getTableId() == TABLEID_AIT)
            {
                d = getAITDescriptor(data, offset, tableSection, t);
            }
            else
            {
                d = getMPEGDescriptor(data, offset, tableSection, t);
            }
        }
        else if (descriptorTag <= 0x7F)
        {
            d = getDVBSIDescriptor(data, offset, tableSection, t);
        }
        else
        {
            d = getPrivateDVBSIDescriptor(data, offset, tableSection, t, sispec);

        }


        t += d->getDescriptorLength() + 2;
        r.push_back(d);

    }

    return r;
}

Descriptor *DescriptorBuilder::getPrivateDVBSIDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t, const int sispec)
{
    Descriptor *d = nullptr;

    if (sispec == eSiSpec_ZIGGO) // Ziggo private_data_specifier: 0x16...
    {
        switch (Utils::getUnsignedByte(data[t + offset]))
        {
        case 0x87:
            //d = new ZiggoVodDeliveryDescriptor(data, t + offset, tableSection);
            break;
        case 0x93:
            //d = new ZiggoVodURLDescriptor(data, t + offset, tableSection);
            break;
        case 0xD4:
            //d = new ZiggoPackageDescriptor(data, t + offset, tableSection);
            break;
        }
    }

    if (d == nullptr)
    {
        //"Unimplemented private descriptor
        d = new Descriptor(data, t + offset, tableSection);
    }

    return d;
}


// TODO descriptor tag enum...
Descriptor *DescriptorBuilder::getDVBSIDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t)
{
    Descriptor *d;
    switch (Utils::getUnsignedByte(data[t + offset]))
    {
        case TAG_NETWORK_NAME:
            d = new NetworkNameDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SERVICE_LIST:
            d = new ServiceListDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SATELLITE_DELIVERY_SYSTEM:
            d = new SatelliteDeliverySystemDescriptor(data, t + offset, tableSection);
            break;

        case TAG_CABLE_DELIVERY_SYSTEM:
            d = new CableDeliverySystemDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_VBI_DATA:
            break;
        case TAG_VBI_TELETEXT:
            break;
#endif
        case TAG_BOUQUET_NAME:
            d = new BouquetNameDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SERVICE:
            d = new ServiceDescriptor(data, t + offset, tableSection);
            break;

        case TAG_COUNTRY_AVAILABILITY:
            d = new CountryAvailabilityDescriptor(data, t + offset, tableSection);
            break;

        case TAG_LINKAGE:
            d = new LinkageDescriptor(data, t + offset, tableSection);
            break;

        case TAG_NVOD_REFERENCE:
            d = new NvodReferenceDescriptor(data, t + offset, tableSection);
            break;

        case TAG_TIME_SHIFTED_SERVICE:
            d = new TimeShiftedServiceDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SHORT_EVENT:
            d = new ShortEventDescriptor(data, t + offset, tableSection);
            break;

        case TAG_EXTENDED_EVENT:
            d = new ExtendedEventDescriptor(data, t + offset, tableSection);
            break;

        case TAG_TIME_SHIFTED_EVENT:
            d = new TimeShiftedEventDescriptor(data, t + offset, tableSection);
            break;

        case TAG_COMPONENT:
            d = new ComponentDescriptor(data, t + offset, tableSection);
            break;

        case TAG_MOSAIC:
            d = new MosaicDescriptor(data, t + offset, tableSection);
            break;

        case TAG_STREAM_IDENTIFIER:
            d = new StreamIdentifierDescriptor(data, t + offset, tableSection);
            break;

        case TAG_CA_IDENTIFIER:
            d = new CaIdentifierDescriptor(data, t + offset, tableSection);
            break;

        case TAG_CONTENT:
            d = new ContentDescriptor(data, t + offset, tableSection);
            break;

        case TAG_PARENTAL_RATING:
            d = new ParentalRatingDescriptor(data, t + offset, tableSection);
            break;

        case TAG_TELETEXT:
            d = new TeletextDescriptor(data, t + offset, tableSection);
            break;

        case TAG_TELEPHONE:
            d = new TelephoneDescriptor(data, t + offset, tableSection);
            break;

        case TAG_LOCAL_TIME_OFFSET:
            d = new LocalTimeOffsetDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SUBTITLING:
            d = new SubtitlingDescriptor(data, t + offset, tableSection);
            break;

        case TAG_TERRESTRIAL_DELIVERY_SYSTEM:
            d = new TerrestrialDeliverySystemDescriptor(data, t + offset, tableSection);
            break;

        case TAG_MULTILINGUAL_NETWORK_NAME:
            d = new MultilingualNetworkNameDescriptor(data, t + offset, tableSection);
            break;

        case TAG_MULTILINGUAL_BOUQUET_NAME:
            d = new MultilingualBouquetNameDescriptor(data, t + offset, tableSection);
            break;

        case TAG_MULTILINGUAL_SERVICE_NAME:
            d = new MultilingualServiceNameDescriptor(data, t + offset, tableSection);
            break;

        case TAG_MULTILINGUAL_COMPONENT:
            d = new MultilingualComponentDescriptor(data, t + offset, tableSection);
            break;

        case TAG_PRIVATE_DATA_SPECIFIER:
            d = new PrivateDataSpecifierDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SERVICE_MOVE:
            d = new ServiceMoveDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SHORT_SMOOTHING_BUFFER:
            d = new ShortSmoothingBufferDescriptor(data, t + offset, tableSection);
            break;

        case TAG_FREQUENCY_LIST:
            d = new FrequencyListDescriptor(data, t + offset, tableSection);
            break;

        case TAG_PARTIAL_TRANSPORT_STREAM:
            d = new PartialTransportStreamDescriptor(data, t + offset, tableSection);
            break;

        case TAG_DATA_BROADCAST:
            d = new DataBroadcastDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_SCRAMBLING:
            break;
#endif
        case TAG_DATA_BROADCAST_ID:
            d = new DataBroadcastIDDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_TRANSPORT_STREAM:
            break;
        case TAG_DSNG:
            break;
#endif
        case TAG_PDC:
            d = new PDCDescriptor(data, t + offset, tableSection);
            break;

        case TAG_DOLBY_AC3:
            d = new AC3Descriptor(data, t + offset, tableSection);
            break;

        case TAG_ANCILLARY_DATA:
            d = new AncillaryDataDescriptor(data, t + offset, tableSection);
            break;

        case TAG_CELL_LIST:
            d = new CellListDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_CELL_FREQ_LIST:
            d = new CellFrequencyLinkDescriptor(data, t + offset, tableSection);
            break;
        case TAG_ANNOUNCEMENT_SUPPORT:
            break;
#endif
        case TAG_APPLICATION_SIGNALLING:
            d = new ApplicationSignallingDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_ADAPTATION_FIELD_DATA:
            break;
        case TAG_SVC_IDENTIFIER:
            d = new ServiceIdentifierDescriptor(data, t + offset, tableSection);
            break;
        case TAG_SVC_AVAILABILITY:
            break;
#endif
        case TAG_DEFAULT_AUTHORITY:
            d = new DefaultAuthorityDescriptor(data, t + offset, tableSection);
            break;

        case TAG_RELATED_CONTENT:
            d = new RelatedContentDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_TVA_ID:
            break;
#endif
        case TAG_CONTENT_IDENTIFIER:
            d = new ContentIdentifierDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_TIME_SLICE_FEC_IDENTIFIER:
            break;
        case TAG_ECM_REPETITION_RATE:
            break;
#endif
        case TAG_S2_SATELLITE_DELIVERY_SYSTEM:
            d = new S2SatelliteDeliverySystemDescriptor(data, t + offset, tableSection);
            break;

        case TAG_ENHANCED_AC3:
            d = new EnhancedAC3Descriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_DTS:
            break;
#endif
        case TAG_AAC:
            d = new AACDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_XAIT_LOCATION:
            break;
#endif
        case TAG_FTA_CONTENT_MANAGEMENT:
            d = new FTAContentManagementDescriptor(data, t + offset, tableSection);
            break;

        case TAG_EXTENSION: // TODO, deep parse.
            d = new ExtensionDescriptor(data, t + offset, tableSection);
            break;

        default:
            // TODO: "Not implemented descriptor"
            d = new Descriptor(data, t + offset, tableSection);
            break;
    }
    return d;
}


Descriptor *DescriptorBuilder::getMPEGDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t)
{
    Descriptor *d;
    switch (Utils::getUnsignedByte(data[t + offset]))
    {
        case TAG_VIDEO_STREAM:
            d = new VideoStreamDescriptor(data, t + offset, tableSection);
            break;

        case TAG_AUDIO_STREAM:
            d = new AudioStreamDescriptor(data, t + offset, tableSection);
            break;

        case TAG_HIERARCHY:
            d = new HierarchyDescriptor(data, t + offset, tableSection);
            break;

        case TAG_REGISTRATION:
            d = new RegistrationDescriptor(data, t + offset, tableSection);
            break;

        case TAG_DATA_STREAM_ALIGNMENT:
            d = new DataStreamAlignmentDescriptor(data, t + offset, tableSection);
            break;

        case TAG_TARGET_BACKGROUND_GRID:
            d = new TargetBackGroundDescriptor(data, t + offset, tableSection);
            break;

        case TAG_VIDEO_WINDOW:
            d = new VideoWindowDescriptor(data, t + offset, tableSection);
            break;

        case TAG_CONDITIONAL_ACCESS:
            d = new ConditionalAccessDescriptor(data, t + offset, tableSection);
            break;

        case TAG_ISO_639_LANGUAGE:
            d = new ISO639LanguageDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SYSTEM_CLOCK:
            d = new SystemClockDescriptor(data, t + offset, tableSection);
            break;

        case TAG_MULTIPLEX_BUFFER_UTILIZATION:
            d = new MultiplexBufferUtilizationDescriptor(data, t + offset, tableSection);
            break;

        case TAG_COPYRIGHT:
            d = new CopyrightDescriptor(data, t + offset, tableSection);
            break;

        case TAG_MAXIMUM_BITRATE:
            d = new MaximumBitrateDescriptor(data, t + offset, tableSection);
            break;

        case TAG_PRIVATE_DATA_INDICATOR:
            d = new PrivateDataIndicatorDescriptor(data, t + offset, tableSection);
            break;

        case TAG_SMOOTHING_BUFFER:
            d = new SmoothingBufferDescriptor(data, t + offset, tableSection);
            break;

        case TAG_STD:
            d = new STDDescriptor(data, t + offset, tableSection);
            break;
#if 0
            // 0x12 IBP_descriptor as found in iso/conformance/hhi.m2t
        case TAG_IBP:
            d = new IBPDescriptor(data, t + offset, tableSection);
            break;
#endif
        case TAG_CAROUSEL_IDENTIFIER:
            d = new CarouselIdentifierDescriptor(data, t + offset, tableSection);
            break;

        case TAG_ASSOCIATION_TAG:
            d = new AssociationTagDescriptor(data, t + offset, tableSection);
            break;

        case TAG_DEFERRED_ASSOCIATION_TAG:
            d = new DeferredAssociationTagDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_STREAM_EVENT:
            d = new StreamEventDescriptor(data, t + offset, tableSection);
            break;
#endif
        case TAG_AVC_VIDEO:
            d = new AVCVideoDescriptor(data, t + offset, tableSection);
            break;
#if 0
        case TAG_AVC_TIMING_AND_HRD:
            d = new AVCTimingAndHRDDescriptor(data, t + offset, tableSection);
            break;
        case TAG_AAC_MPEG2:
            d = new AACMpeg2Descriptor(data, t + offset, tableSection);
            break;
        case TAG_JPEG2000VIDEO:
            d = new JPEG2000VideoDescriptor(data, t + offset, tableSection);
            break;
#endif
        default:
            // TODO: "Not implemented descriptor"
            d = new Descriptor(data, t + offset, tableSection);
            break;
    }
    return d;
}



Descriptor *DescriptorBuilder::getUNTDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t)
{
    Descriptor *d;
    switch (Utils::getUnsignedByte(data[t + offset]))
    {
#if 0
        case 0x01:
            d = new SchedulingDescriptor(data, t + offset, tableSection);
            break;
        case 0x02:
            d = new UpdateDescriptor(data, t + offset, tableSection);
            break;
        case 0x03:
            d = new SSULocationDescriptor(data, t + offset, tableSection);
            break;
        case 0x04:
            d = new MessageDescriptor(data, t + offset, tableSection);
            break;
        case 0x05:
            d = new SSUEventNameDescriptor(data, t + offset, tableSection);
            break;
        case 0x0B:
            d = new SSUSubgroupAssociationDescriptor(data, t + offset, tableSection);
            break;
        default:
            // TODO: "Not implemented descriptor"
            d = new UNTDescriptor(data, t + offset, tableSection);
            break;
#endif
    }
    return d;
}

Descriptor *DescriptorBuilder::getAITDescriptor(const char* data, const int offset, const TableSection* tableSection, const int t)
{
    Descriptor *d;
    switch (Utils::getUnsignedByte(data[t + offset]))
    {
#if 0
        case 0x00:
            d = new ApplicationDescriptor(data, t + offset, tableSection);
            break;
        case 0x01:
            d = new ApplicationNameDescriptor(data, t + offset, tableSection);
            break;
        case 0x02:
            d = new TransportProtocolDescriptor(data, t + offset, tableSection);
            break;
        case 0x03:
            d = new DVBJApplicationDescriptor(data, t + offset, tableSection);
            break;
        case 0x04:
            d = new DVBJApplicationLocationDescriptor(data, t + offset, tableSection);
            break;
        case 0x15:
            d = new SimpleApplicationLocationDescriptor(data, t + offset, tableSection);
            break;
        case 0x16:
            d = new ApplicationUsageDescriptor(data, t + offset, tableSection);
            break;
        case 0x17:
            d = new SimpleApplicationBoundaryDescriptor(data, t + offset, tableSection);
            break;
        default:
            // TODO: "Not implemented descriptor"
            d = new AITDescriptor(data, t + offset, tableSection);
            break;
#endif
    }
    return d;
}
