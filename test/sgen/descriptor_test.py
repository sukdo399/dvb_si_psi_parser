#! /usr/bin/env python

import os
import sys

sys.path.append("lib/dvbobjects.zip")

from dvbobjects.DVB.Descriptors import *
from dvbobjects.MPEG.Descriptors import *
from dvbobjects.DSMCC.Descriptors import *
from dvbobjects.utils.MJD import *

from sgen import bin2array

if __name__ == '__main__':
	
	test  = []
	print("\n============ Descriptor Test ===============")

	test.append(	
		hierarchy_descriptor(
			hicrarchy_type = 0x07,
			hierarchy_layer_index = 0x16,
			hierarchy_embedded_layer_index = 0x3B,
			hierarchy_channel = 0x25,
			)
	)

	test.append(	
		data_stream_alignment_descriptor(
			alignment_type = 0x03,
			)
	)
	
	test.append(
		target_background_grid_descriptor(
			horizontal_size = 0x567, 
			vertical_size = 0xA87,
			aspect_ratio_information = 0x3,
			)
	)
	
	test.append(
		video_window_descriptor(
			horizontal_offset = 1,
			vertical_offset = 0x28,
			window_priority = 0x02,
			)
	)

	test.append(
		system_clock_descriptor(
			external_clock_referrence_indicator = 1,
			clock_accuracy_integer = 0x28,
			clock_accuracy_exponent = 0x02,
			)

	)

	test.append(
		multiplex_buffer_utilization_descriptor(
			bound_valid_flag = 1,
			LTW_offset_lower_bound = 0x7bac,
			LTW_offset_upper_bound = 0x6ba9,
			)
	)

	test.append(
		copyright_descriptor(
			copyright_identifier = 0x4567,
			additional_copyright_info = 'AddInfo',
		)
	)

	test.append(
		maximum_bitrate_descriptor(
			maximum_bitrate = 0x48BD,
		)
	)

	test.append(
 		private_data_indicator_descriptor(
			private_data_indicator = 0x123fa,
		)
	)

	test.append(
		smoothing_buffer_descriptor(
			sb_leak_rate = 0x40592,
			sb_size = 0x1FFE0,
		)
	)
	
	test.append(
		ibp_descriptor(
			close_gop_flag = 1,
			identical_gop_flag = 1,
			max_gop_length = 0x1234,	
			)
	)


	test.append(
		mpeg4_video_descriptor(
			mpeg4_visual_profile_and_level = 0x11,
		)

	)

	test.append(
		iod_descriptor(
			scope_of_IOD_label = 0x11,
			IOD_label = 0x03,
			InitialObjectDescriptor = 0x00, # dummy
		)
	)


	test.append(
		fmc_descriptor(
			fmc_loop = [
				fmc_loop_item(
					ES_ID = 0x1011,
					FlexMuxChannel = 0xEF,
				),
				fmc_loop_item(
					ES_ID = 0x7FAA,
					FlexMuxChannel = 0x08,
				),
			],
		),
	)

	
	test.append(
		external_es_id_descriptor(
			External_ES_ID = 0x4058,
		)
	)

	test.append(
		muxcode_descriptor(
			muxcode_loop = [
				MuxCodeTableEntry(
					dummy = 0x11, # Need to implement...
				),

				MuxCodeTableEntry(
					dummy = 0x22, # Need to implement...
				)				
			]
		)
	)

	test.append(
		multiplexbuffer_descriptor(
			MB_buffer_size = 0x56742,
			TB_leak_rate = 0x27440,
		)
	)



	test.append(
		stuffing_descriptor(
			stuffing_loop = [
				stuffing_loop_item(
					stuffing_byte = 0xFF
				),
				stuffing_loop_item(
					stuffing_byte = 0xFF
				),
				stuffing_loop_item(
					stuffing_byte = 0xFF
				),
				stuffing_loop_item(
					stuffing_byte = 0xFF
				),
				stuffing_loop_item(
					stuffing_byte = 0xFF
				),
			]
		)		
	)


	
	test.append(
		vbi_teletext_descriptor(
			teletext_descriptor_loop = [
				teletext_descriptor_loop_item(
					ISO639_language_code = 'kor',
					type = 0x02,
					magazine_number = 0x01,
					page_number = 0xFA,
				),
				teletext_descriptor_loop_item(
					ISO639_language_code = 'eng',
					type = 0x02,
					magazine_number = 0x02,
					page_number = 0x35,
				)
			]

		)
	)


	test.append(
		nvod_reference_descriptor(
			nvod_reference_loop = [
				nvod_reference_loop_item(
					transport_stream_id = 0x2201,
					original_network_id = 0x0101,
					service_id = 0x1001,
					),
				nvod_reference_loop_item(
					transport_stream_id = 0x2201,
					original_network_id = 0x0101,
					service_id = 0x1002,
					),
				nvod_reference_loop_item(
					transport_stream_id = 0x2201,
					original_network_id = 0x0101,
					service_id = 0x1003,
					),
				]
			)
	)
	

	test.append(
		time_shifted_service_descriptor(
			reference_service_id = 0x1001,
			)
	)
	test.append(
			time_shifted_event_descriptor(
			reference_service_id = 0x1001,
			reference_event_id = 0xA400,
			)
	)

	
	test.append(
		mosaic_descriptor(

			mosaic_entry_point = 0x01,
			number_of_horizontal_elementary_cells = 0x02,
			number_of_vertical_elementary_cells = 0x04,

			mosaic_descriptor_loop = [
				mosaic_descriptor_loop_item(
					logical_cell_id = 0x12,
					logical_cell_presentation_info = 0x05,
					mosaic_elementary_cell_loop = [
						mosaic_elementary_cell_loop_item(
							elementary_cell_id = 0x08,
							),
						mosaic_elementary_cell_loop_item(
							elementary_cell_id = 0x09,
							),

					],
					cell_linkage_info = 0x01,
					bouquet_id = 0x04,
				),

				mosaic_descriptor_loop_item(
					logical_cell_id = 0x12,
					logical_cell_presentation_info = 0x05,
					mosaic_elementary_cell_loop = [
						mosaic_elementary_cell_loop_item(
							elementary_cell_id = 0x08,
							),
					],
					cell_linkage_info = 0x02,
					original_network_id = 0xAE04,
					transport_stream_id = 0x2244,
					service_id = 0x1001
				),

				mosaic_descriptor_loop_item(
					logical_cell_id = 0x12,
					logical_cell_presentation_info = 0x05,
					mosaic_elementary_cell_loop = [
						mosaic_elementary_cell_loop_item(
							elementary_cell_id = 0x08,
							),
					],
					cell_linkage_info = 0x04,
					original_network_id = 0xAE04,
					transport_stream_id = 0x2244,
					service_id = 0x1001,
					event_id = 0x8080,
				),


			]
			)
	)

	
	test.append(
		ca_identifier_descriptor(
			ca_identifier_loop = [
				ca_identifier_loop_item(
						CA_system_id = 0x7070
					),
				ca_identifier_loop_item(
						CA_system_id = 0x8080
					),
				ca_identifier_loop_item(
						CA_system_id = 0x1F1F
					),
			]
		)
	)
	
	
	test.append(
		multilingual_network_name_descriptor(
			multilingual_network_name_loop = [
				multilingual_network_name_loop_item(
					ISO_639_language_code = 'kor',
					network_name = 'TestNetwork',
					),
				multilingual_network_name_loop_item(
					ISO_639_language_code = 'eng',
					network_name = 'EngNetwork',
					),
				multilingual_network_name_loop_item(
					ISO_639_language_code = 'ger',
					network_name = 'GerNetwork',
					),
			]
		)
	)

	test.append(
		multilingual_bouquet_name_descriptor(
			multilingual_bouquet_name_loop = [
				multilingual_bouquet_name_loop_item(
					ISO_639_language_code = 'kor',
					bouquet_name = 'Comedy',
					),
				multilingual_bouquet_name_loop_item(
					ISO_639_language_code = 'kor',
					bouquet_name = 'Movie',
					),
				multilingual_bouquet_name_loop_item(
					ISO_639_language_code = 'kor',
					bouquet_name = 'Drama',
					),
			]
		)
	)

	test.append(
		multilingual_service_name_descriptor(
			multilingual_service_name_loop = [
				multilingual_service_name_loop_item(
					ISO_639_language_code = 'kor',
					provider_name = 'Test',
					service_name = 'svc1',
					),
				multilingual_service_name_loop_item(
					ISO_639_language_code = 'kor',
					provider_name = 'Test',
					service_name = 'svc2',
					),
				multilingual_service_name_loop_item(
					ISO_639_language_code = 'kor',
					provider_name = 'Test',
					service_name = 'svc3',
					),
			]
		)
	)	


	test.append(
		multilingual_component_descriptor(
			multilingual_component_loop = [
				multilingual_component_loop_item(
					ISO_639_language_code = 'kor',
					text = 'test test test'
					),
				multilingual_component_loop_item(
					ISO_639_language_code = 'kor',
					text = 'test test test'
					),
				multilingual_component_loop_item(
					ISO_639_language_code = 'kor',
					text = 'test test test'
					),
			]
		)
	)	


	
	test.append(
		service_move_descriptor(
			new_original_network_id = 0x0013,
			new_transport_stream_id = 0xE6AA,
			new_service_id = 0x2004,
		)
	)



	test.append(
		short_smoothing_buffer_descriptor(
			sb_size = 0,
			sb_leak_rate = 0x14,
			DVB_reserved = '0',
		)
	)


	test.append(
		scrambling_descriptor(
			scrambling_mode = 0x02,
			)
	)
	
	test.append(
		ancillary_data_descriptor(
			ancillary_data_identifier = 0x20, #MPEG-4 ancillary data
			)
	)



	test.append(
		cell_list_descriptor(
			cell_list_loop = [
				cell_list_loop_item(
					cell_id = 0x1010,
					cell_latitude = 0x4040,
					cell_longitude = 0x7777,
					cell_extent_of_latitude = 0x111,
					cell_extent_of_longitude = 0x222,
						cell_list_extension_loop = [
							cell_list_extension_loop_item(
								cell_id_extension = 0x10,
								subcell_latitude = 0x5050,
								subcell_longitude = 0xAAAA,
								subcell_extent_of_latitude = 0x888,
								subcell_extent_of_longitude = 0x233,
								),
							cell_list_extension_loop_item(
								cell_id_extension = 0x20,
								subcell_latitude = 0x6060,
								subcell_longitude = 0xAAAA,
								subcell_extent_of_latitude = 0x888,
								subcell_extent_of_longitude = 0x233,
								)

						]

				),

				cell_list_loop_item(
					cell_id = 0x1010,
					cell_latitude = 0x4040,
					cell_longitude = 0x7777,
					cell_extent_of_latitude = 0x111,
					cell_extent_of_longitude = 0x222,
						cell_list_extension_loop = [
							cell_list_extension_loop_item(
								cell_id_extension = 0x10,
								subcell_latitude = 0x5050,
								subcell_longitude = 0xAAAA,
								subcell_extent_of_latitude = 0x888,
								subcell_extent_of_longitude = 0x233,
								)

						]

				)


			]

		)
	)


	
	test.append(
		cell_frequency_link_descriptor(
			cell_frequency_link_loop = [
				cell_frequency_link_loop_item(
					cell_id = 0xA004,
					frequency = 0x10203040,
					cell_frequency_link_extension_loop = [
						cell_frequency_link_extension_loop_item(
							cell_id_extension = 0xFF,
							transposer_frequency = 0x56102030,
							),
						cell_frequency_link_extension_loop_item(
							cell_id_extension = 0xFF,
							transposer_frequency = 0x56102030,
							),
					]

					),
				
				cell_frequency_link_loop_item(
					cell_id = 0xA004,
					frequency = 0x10203040,
					cell_frequency_link_extension_loop = [
						cell_frequency_link_extension_loop_item(
							cell_id_extension = 0xFF,
							transposer_frequency = 0x56102030,
							),
						cell_frequency_link_extension_loop_item(
							cell_id_extension = 0xFF,
							transposer_frequency = 0x56102030,
							),
					]

					)				


			]

		)
	)


	test.append(
		announcemnet_support_descriptor(
			announcement_support_indicator = 0x0010, # News flash
			announcemnet_support_loop = [
				announcemnet_support_loop_item(
					announcement_type = 0x04,
					reference_type = 0x02,
					original_network_id = 0x0030,
					transport_stream_id = 0x8860,
					service_id = 0x1050,
					component_tag = 0x11,
				),

				announcemnet_support_loop_item(
					announcement_type = 0x04,
					reference_type = 0x00,
				)
			],
		)
	)


	test.append(
		adaption_field_data_descriptor(
			adaptation_field_data_identifier = 0x02,
		)
	)

	test.append(
		service_identifier_descriptor(
			textual_service_identifier_bytes = 'TEST identifier'
		)
	)

	test.append(
		service_availability_descriptor(
			availability_flag = 1,
			service_availability_loop = [
				service_availability_loop_item(
						cell_id = 0x7080,
					),
				service_availability_loop_item(
						cell_id = 0xAAEE,
					),
			]

		)
	)

	test.append(
		releated_content_descriptor(

		)
	)
	
	test.append(
		tva_id_descriptor(
			tva_id_loop = [
				tva_id_loop_item(
					TVA_id = 0xEA76,
					runing_status = 0x07,
				),
			]
		)
	)

	test.append(
		ecm_repetition_rate_descriptor(
			CA_system_ID = 0xafEE,
			ECM_repetition_rate = 0x1234,
			private_data_byte = "\x40\x44\xEF",
		)
	)

	test.append(
		s2_satellite_delivery_system_descriptor(
			scrambling_sequence_selector = 1,
			multiple_input_stream_flag = 1,
			backwards_compatibility_indicator = 1,
			scrambling_sequence_index = 0x1AEAE,
			input_stream_identifier = 0x45,
		)
	)

	test.append(
		s2_satellite_delivery_system_descriptor(
			scrambling_sequence_selector = 1,
			multiple_input_stream_flag = 0,
			backwards_compatibility_indicator = 1,
			scrambling_sequence_index = 0x1AEAE,
			input_stream_identifier = 0x45,
		)
	)

	
	test.append(
		s2_satellite_delivery_system_descriptor(
			scrambling_sequence_selector = 0,
			multiple_input_stream_flag = 1,
			backwards_compatibility_indicator = 1,
			scrambling_sequence_index = 0x1AEAE,
			input_stream_identifier = 0x45,
		)
	)
	
	test.append(
		enhanced_ac3_descriptor(
			component_type_flag = 1, 
			bsid_flag = 1,
			mainid_flag = 1,
			asvc_flag = 1,
			mixinfoexists = 0,
			substream1_flag = 1,
			substream2_flag = 1,
			substream3_flag = 1,

			component_type = 0x1B, 
			bsid = 0x88,
			mainid = 0x55,
			asvc = 0x22,
			substream1 = 0x11,
			substream2 = 0xAA,
			substream3 = 0xFF,
			additional_info = '\xAA\xEE',
		)
	)

	test.append(
		enhanced_ac3_descriptor(
			component_type_flag = 1, 
			bsid_flag = 0,
			mainid_flag = 1,
			asvc_flag = 0,
			mixinfoexists = 0,
			substream1_flag = 1,
			substream2_flag = 0,
			substream3_flag = 1,

			component_type = 0x1B, 
			bsid = 0x88,
			mainid = 0x55,
			asvc = 0x22,
			substream1 = 0x11,
			substream2 = 0xAA,
			substream3 = 0xFF,
			additional_info = '\xAA\xEE',
		)
	)

	test.append(
		extension_descriptor(
			descriptor_tag_extension = 0x04, #T2 delivery system...
			selector_byte = "\xAA\x12\x13",
		)
	)
	
	test.append(
		video_stream_descriptor(
			multiple_frame_rate_flag = 1,
			frame_rate_code = 4, # 30
			MPEG_1_only_flag = 0,
			constrained_parameter_flag = 1,
			still_picture_flag = 0,
			profile_and_level_indication = 0x11,
			chroma_format = 1, # 4:2:0
			frame_rate_extension_flag = 0,
		),
	)

	test.append(
		video_stream_descriptor(
			multiple_frame_rate_flag = 1,
			frame_rate_code = 4, # 30
			MPEG_1_only_flag = 1,
			constrained_parameter_flag = 1,
			still_picture_flag = 0,
			profile_and_level_indication = 0x11,
			chroma_format = 1, # 4:2:0
			frame_rate_extension_flag = 0,
		),
	)

	test.append(
		ac3_descriptor(
			component_type_flag = 1,
			bsid_flag = 0,
			mainid_flag = 1,
			asvc_flag = 1,
			component_type = 0x01,
			bsid = 0x02,
			mainid = 0x03,
			asvc = 0x04,
			additional_info ='add'
		),
	)

	test.append(
		local_time_offset_descriptor(
				local_time_offset_loop = [
					local_time_offset_loop_item(
						ISO_639_language_code = 'kor',
						country_region_id = 0,
						local_time_offset_polarity = 0,
						local_time_offset_hour = 12, # 09:00
						local_time_offset_minute = 34,
						year_of_change = 114,
						month_of_change = 6, 
						day_of_change = 20,
						hour_of_change = 11,
						minute_of_change = 17,
						second_of_change = 40,

						next_time_offset_hour = 8,
						next_time_offset_minute = 52, 
					),
				],

			),
	)
	test.append(
		satellite_delivery_system_descriptor(
			frequency = 12800,
			orbital_position = 5678,
			west_east_flag = 1, 
			polarization = 0x01,
			modulation = 0x00,
			symbol_rate = 27500, 
			FEC_inner = 0x01, 
		),
	)

	test.append(
		cable_delivery_system_descriptor(
			frequency = 640000,
			FEC_outer = 0x01,
			modulation = 0x02, # 32 QAM
			symbol_rate = 27500,
			FEC_inner = 0x03, # 2/3 conv
		),	
	)

	'''
	test.append(
	
	)
	'''
	
	# start test!
	print("")
	for a in test : 
		#print(a.__class__.__name__)
		
		# enable if you need c array header
#		bin2array(a.pack(), a.__class__.__name__)

		print(a)
		a.dump()
		print("\n")
