/*
 *Original Author:	shko
 */

#ifndef TABLEID_H
#define TABLEID_H

enum enTableId
{
    TABLEID_PAT						= 0x00,
    TABLEID_CAT						= 0x01,
    TABLEID_PMT						= 0x02,
    TABLEID_TSDT						= 0x03,
    TABLEID_NIT_ACT					= 0x40,
    TABLEID_NIT_OTH					= 0x41,
    TABLEID_SDT_ACT					= 0x42,
    TABLEID_SDT_OTH					= 0x46,
    TABLEID_EIT_ACT_PF				= 0x4e,
    TABLEID_EIT_OTH_PF				= 0x4f,
    TABLEID_EIT_ACT_SC_0				= 0x50,
    TABLEID_EIT_ACT_SC_1				= 0x51,
    TABLEID_EIT_ACT_SC_2				= 0x52,
    TABLEID_EIT_ACT_SC_3				= 0x53,
    TABLEID_EIT_ACT_SC_4				= 0x54,
    TABLEID_EIT_ACT_SC_5				= 0x55,
    TABLEID_EIT_ACT_SC_6				= 0x56,
    TABLEID_EIT_ACT_SC_7				= 0x57,
    TABLEID_EIT_ACT_SC_8				= 0x58,
    TABLEID_EIT_ACT_SC_9				= 0x59,
    TABLEID_EIT_ACT_SC_10			= 0x5a,
    TABLEID_EIT_ACT_SC_11			= 0x5b,
    TABLEID_EIT_ACT_SC_12			= 0x5c,
    TABLEID_EIT_ACT_SC_13			= 0x5d,
    TABLEID_EIT_ACT_SC_14			= 0x5e,
    TABLEID_EIT_ACT_SC_15			= 0x5f,
    TABLEID_EIT_OTH_SC_0				= 0x60,
    TABLEID_EIT_OTH_SC_1				= 0x61,
    TABLEID_EIT_OTH_SC_2				= 0x62,
    TABLEID_EIT_OTH_SC_3				= 0x63,
    TABLEID_EIT_OTH_SC_4				= 0x64,
    TABLEID_EIT_OTH_SC_5				= 0x65,
    TABLEID_EIT_OTH_SC_6				= 0x66,
    TABLEID_EIT_OTH_SC_7				= 0x67,
    TABLEID_EIT_OTH_SC_8				= 0x68,
    TABLEID_EIT_OTH_SC_9				= 0x69,
    TABLEID_EIT_OTH_SC_10			= 0x6a,
    TABLEID_EIT_OTH_SC_11			= 0x6b,
    TABLEID_EIT_OTH_SC_12			= 0x6c,
    TABLEID_EIT_OTH_SC_13			= 0x6d,
    TABLEID_EIT_OTH_SC_14			= 0x6e,
    TABLEID_EIT_OTH_SC_15			= 0x6f,

    TABLEID_BAT						= 0x4a,
    TABLEID_RST						= 0x71,
    TABLEID_TDT						= 0x70,
    TABLEID_TOT						= 0x73,
    TABLEID_AIT						= 0x74,

    TABLEID_DIT_ARIB					= 0x7E,		/* Already defined DIT_TABLE_ID */
    TABLEID_SIT						= 0x7F,

    TABLEID_DIT						= 0xc5,
    TABLEID_DIT_EXT					= 0xc5c5,
    TABLEID_DGT						= 0xc6,
    TABLEID_DBT						= 0xc7,

    TABLEID_DSI						= 0x3b,		/* dsm-cc data carousel */
    TABLEID_DII						= 0x3b,		/* dsm-cc data carousel */
    TABLEID_DDB						= 0x3c,		/* dsm-cc data carousel */
    TABLEID_DESC						= 0x3d,		/* dsm-cc data carousel stream description*/
    TABLEID_UNT						= 0x4b,		/* dvb-ssu enhanced profile */
    TABLEID_RCT						= 0x76,		/* related content table TS 102-323 & 300-468 */
    TABLEID_CIT						= 0xa0,
    TABLEID_CPT						= 0xa1,
    TABLEID_SGT						= 0x91,		/* from SUPPORT_ASTRA_LCN */
    TABLEID_RPD						= 0xe0,		/* from TNTSat - Regionalization Pool desiptor Section Table */
    TABLEID_DSC						= 0xf0,
    TABLEID_ICT						= 0xfe,

    TABLEID_EIT_ACT_SC_BASIC_0		= TABLEID_EIT_ACT_SC_0,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_BASIC_1		= TABLEID_EIT_ACT_SC_1,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_BASIC_2		= TABLEID_EIT_ACT_SC_1,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_BASIC_3		= TABLEID_EIT_ACT_SC_1,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_BASIC_4		= TABLEID_EIT_ACT_SC_1,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_BASIC_5		= TABLEID_EIT_ACT_SC_1,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_BASIC_6		= TABLEID_EIT_ACT_SC_6,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_BASIC_7		= TABLEID_EIT_ACT_SC_7,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_EXTENDED_8	= TABLEID_EIT_ACT_SC_8,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_EXTENDED_9	= TABLEID_EIT_ACT_SC_9,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_EXTENDED_10	= TABLEID_EIT_ACT_SC_10,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_EXTENDED_11	= TABLEID_EIT_ACT_SC_11,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_EXTENDED_12	= TABLEID_EIT_ACT_SC_12,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_EXTENDED_13	= TABLEID_EIT_ACT_SC_13,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_EXTENDED_14	= TABLEID_EIT_ACT_SC_14,	/* Japan, ARIB */
    TABLEID_EIT_ACT_SC_EXTENDED_15	= TABLEID_EIT_ACT_SC_15,	/* Japan, ARIB */
    TABLEID_EIT_OTH_BASIC_0			= TABLEID_EIT_OTH_SC_0,	/* Japan, ARIB */
    TABLEID_EIT_OTH_BASIC_1			= TABLEID_EIT_OTH_SC_1,	/* Japan, ARIB */
    TABLEID_EIT_OTH_BASIC_2			= TABLEID_EIT_OTH_SC_2,	/* Japan, ARIB */
    TABLEID_EIT_OTH_BASIC_3			= TABLEID_EIT_OTH_SC_3,	/* Japan, ARIB */
    TABLEID_EIT_OTH_BASIC_4			= TABLEID_EIT_OTH_SC_4,	/* Japan, ARIB */
    TABLEID_EIT_OTH_BASIC_5			= TABLEID_EIT_OTH_SC_5,	/* Japan, ARIB */
    TABLEID_EIT_OTH_BASIC_6			= TABLEID_EIT_OTH_SC_6,	/* Japan, ARIB */
    TABLEID_EIT_OTH_BASIC_7			= TABLEID_EIT_OTH_SC_7,	/* Japan, ARIB */
    TABLEID_EIT_OTH_EXTENDED_8		= TABLEID_EIT_OTH_SC_8,	/* Japan, ARIB */
    TABLEID_EIT_OTH_EXTENDED_9		= TABLEID_EIT_OTH_SC_9,	/* Japan, ARIB */
    TABLEID_EIT_OTH_EXTENDED_10		= TABLEID_EIT_OTH_SC_10,	/* Japan, ARIB */
    TABLEID_EIT_OTH_EXTENDED_11		= TABLEID_EIT_OTH_SC_11,	/* Japan, ARIB */
    TABLEID_EIT_OTH_EXTENDED_12		= TABLEID_EIT_OTH_SC_12,	/* Japan, ARIB */
    TABLEID_EIT_OTH_EXTENDED_13		= TABLEID_EIT_OTH_SC_13,	/* Japan, ARIB */
    TABLEID_EIT_OTH_EXTENDED_14		= TABLEID_EIT_OTH_SC_14,	/* Japan, ARIB */
    TABLEID_EIT_OTH_EXTENDED_15		= TABLEID_EIT_OTH_SC_15,	/* Japan, ARIB */
    TABLEID_SDTT						= 0xc3,						/* Japan, ARIB */
    TABLEID_BIT						= 0xc4,						/* Japan, ARIB */
    TABLEID_CDT						= 0xc8,						/* Japan, ARIB */

    TABLEID_FSAT_EITPF_PP_OTH		= 0xd1,						/* Freesat Tunneld Eit pf++ Oth */

    TABLEID_ETC						= 0xf1
};

#endif // TABLEID_H
