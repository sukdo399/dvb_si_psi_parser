/*
 *Original Author:	shko
 */

#ifndef DESCRIPTORTAG_H
#define DESCRIPTORTAG_H



enum enDescriptorTag
{
    // 0x80 ~ 0xFE : Private (User define)

    /** < ISO/IEC 13818-1 */
    TAG_VIDEO_STREAM					= 0x02,	/** < Video Stream Descriptor */
    TAG_AUDIO_STREAM					= 0x03,	/** < Audio Stream Descriptor */
    TAG_HIERARCHY						= 0x04,	/** < Hierarchy Descriptor */
    TAG_REGISTRATION					= 0x05,	/** < Registration Descriptor */
    TAG_DATA_STREAM_ALIGNMENT			= 0x06,	/** < Data Stream Alignment Descriptor */
    TAG_TARGET_BACKGROUND_GRID			= 0x07,	/** < Target Background Grid Descriptor */
    TAG_VIDEO_WINDOW					= 0x08,	/** < Video Window Descriptor */
    TAG_CONDITIONAL_ACCESS				= 0x09,	/** < CA Descriptor */
    TAG_ISO_639_LANGUAGE				= 0x0A,	/** < ISO 639 Language Descriptor */
    TAG_SYSTEM_CLOCK					= 0x0B,	/** < System Clock Descriptor */
    TAG_MULTIPLEX_BUFFER_UTILIZATION	= 0x0C,	/** < Multiplex Buffer Utilization Descriptor */
    TAG_COPYRIGHT						= 0x0D,	/** < Copyright Descriptor */
    TAG_MAXIMUM_BITRATE					= 0x0E,	/** < Maximum Bitrate Descriptor */
    TAG_PRIVATE_DATA_INDICATOR			= 0x0F,	/** < Private Data Indicator Descriptor */
    TAG_SMOOTHING_BUFFER				= 0x10,	/** < Smoothing Buffer Descriptor */
    TAG_STD								= 0x11,	/** < STD Descriptor */
    TAG_IBP                             = 0x12, /** 0x12 IBP_descriptor as found in iso/conformance/hhi.m2t */ // not exist in octo...
    TAG_CAROUSEL_IDENTIFIER				= 0x13, /** < Carousel ID Descriptor */ // 13818-6, // tr 101 202
    TAG_ASSOCIATION_TAG					= 0x14,	/** < Association Tag Descriptor */ // 13818-6, // tr 101 202
    TAG_DEFERRED_ASSOCIATION_TAG		= 0x15,	/** < Deferred Association Tag Descriptor */ // 13818-6
    TAG_STREAM_EVENT                    = 0x1A, // not exist in octo...
    TAG_AVC_VIDEO						= 0x28,	/** < AVC Video Descriptor */
    TAG_AVC_TIMING_AND_HRD              = 0x2A, // not exist in octo...
    TAG_AAC_MPEG2                       = 0x2B, // not exist in octo...
    TAG_JPEG2000VIDEO                   = 0x32, // not exist in octo...

    /** < ETS 300 468 */
    TAG_NETWORK_NAME					= 0x40,	/** < Network Name Descriptor */
    TAG_SERVICE_LIST					= 0x41,	/** < Service List Descriptor */
    TAG_STUFFING						= 0x42,	/** < Stuffing Descriptor */ // not exist in octo...
    TAG_SATELLITE_DELIVERY_SYSTEM		= 0x43,	/** < Satellite Delivery System Descriptor */
    TAG_CABLE_DELIVERY_SYSTEM			= 0x44,	/** < Cable Delivery System Descriptor */
    TAG_VBI_DATA                        = 0x45, // not exist in octo...
    TAG_VBI_TELETEXT                    = 0x46, // not exist in octo...
    TAG_BOUQUET_NAME					= 0x47,	/** < Bouquet Name Descriptor */
    TAG_SERVICE							= 0x48,	/** < Service Descriptor */
    TAG_COUNTRY_AVAILABILITY			= 0x49,	/** < Country Availability Descriptor */
    TAG_LINKAGE							= 0x4A,	/** < Linkage Descriptor */
    TAG_NVOD_REFERENCE					= 0x4B,	/** < NVOD Reference Descriptor */
    TAG_TIME_SHIFTED_SERVICE			= 0x4C,	/** < Time Shifted Service Descriptor */
    TAG_SHORT_EVENT						= 0x4D,	/** < Short Event Descriptor */
    TAG_EXTENDED_EVENT					= 0x4E,	/** < Extended Event Descriptor */
    TAG_TIME_SHIFTED_EVENT				= 0x4F,	/** < Time Shifted Event Descriptor */
    TAG_COMPONENT						= 0x50,	/** < Component Descriptor */
    TAG_MOSAIC							= 0x51,	/** < Mosaic Descriptor */ // not exist in octo...
    TAG_STREAM_IDENTIFIER				= 0x52,	/** < Stream Identifier Descriptor */
    TAG_CA_IDENTIFIER					= 0x53,	/** < CA Identifier Descriptor */
    TAG_CONTENT							= 0x54,	/** < Content Descriptor */
    TAG_PARENTAL_RATING					= 0x55,	/** < Parental Rating Descriptor */
    TAG_TELETEXT						= 0x56,	/** < Teletext Descriptor */
    TAG_TELEPHONE						= 0x57,	/** < Telephone Descriptor */
    TAG_LOCAL_TIME_OFFSET				= 0x58,	/** < Local Time Offset Descriptor */
    TAG_SUBTITLING						= 0x59,	/** < Subtitling Descriptor */
    TAG_TERRESTRIAL_DELIVERY_SYSTEM		= 0x5A,	/** < Terrestrial Delivery System Descriptor */
    TAG_MULTILINGUAL_NETWORK_NAME		= 0x5B,	/** < Multilingual Network Name Descriptor */
    TAG_MULTILINGUAL_BOUQUET_NAME		= 0x5C,	/** < Multilingual Bouquet Name Descriptor */
    TAG_MULTILINGUAL_SERVICE_NAME		= 0x5D,	/** < Multilingual Service Name Descriptor */
    TAG_MULTILINGUAL_COMPONENT			= 0x5E,	/** < Multilingual Component Descriptor */
    TAG_PRIVATE_DATA_SPECIFIER			= 0x5F,	/** < Private Data Specifier Descriptor */
    TAG_SERVICE_MOVE					= 0x60,	/** < Service Move Descriptor */
    TAG_SHORT_SMOOTHING_BUFFER			= 0x61,	/** < Short Smoothing Buffer Descriptor */
    TAG_FREQUENCY_LIST					= 0x62,	/** < Frequency List Descriptor */
    TAG_PARTIAL_TRANSPORT_STREAM        = 0x63,
    TAG_DATA_BROADCAST					= 0x64,	/** < Data Boadcast Descriptor */
    TAG_SCRAMBLING                      = 0x65, // not exist in octo...
    TAG_DATA_BROADCAST_ID				= 0x66,	/** < Data Boadcast Descriptor (NEW, 2001)*/
    TAG_TRANSPORT_STREAM                = 0x67, // not exist in octo...
    TAG_DSNG                            = 0x68, // not exist in octo...
    TAG_PDC								= 0x69,	/** < PDC Descriptor (300 468 v1.7.1) */
    TAG_DOLBY_AC3						= 0x6A,	/** < AC3(Dolby) Descriptor */
    TAG_ANCILLARY_DATA					= 0x6B, // not exist in octo...
    TAG_CELL_LIST						= 0x6C,
    TAG_CELL_FREQ_LIST					= 0x6D, // not exist in octo...
    TAG_ANNOUNCEMENT_SUPPORT			= 0x6E, // not exist in octo...
    TAG_APPLICATION_SIGNALLING			= 0x6F,	/** < Application Signalling Descriptor */ // ts 102 809
    TAG_ADAPTATION_FIELD_DATA			= 0x70, // not exist in octo...
    TAG_SVC_IDENTIFIER					= 0x71, // not exist in octo...
    TAG_SVC_AVAILABILITY				= 0x72, // not exist in octo...
    TAG_DEFAULT_AUTHORITY				= 0x73,	/** < Default Authority descriptor */ // TS 102 323
    TAG_RELATED_CONTENT					= 0x74, // TS 102 323
    TAG_TVA_ID                          = 0x75, // not exist in octo...
    TAG_CONTENT_IDENTIFIER				= 0x76,	/** < Content identifier descriptor */ // TS 102 323
    TAG_TIME_SLICE_FEC_IDENTIFIER       = 0x77, // not exist in octo...
    TAG_ECM_REPETITION_RATE             = 0x78, // not exist in octo...
    TAG_S2_SATELLITE_DELIVERY_SYSTEM 	= 0x79,
    TAG_ENHANCED_AC3					= 0x7A, /** < Enhanced - AC3(Dolby Plus) Descriptor */
    TAG_DTS								= 0x7B, /** see DVB 300-468 annex G*/ // not exist in octo...
    TAG_AAC								= 0x7C, /** see DVB 300-468 annex H*/
    TAG_XAIT_LOCATION					= 0x7D, // not exist in octo...
    TAG_FTA_CONTENT_MANAGEMENT			= 0x7E,
    TAG_EXTENSION						= 0x7F,

    TAG_END								= 0xFF
};


#endif // DESCRIPTORTAG_H
