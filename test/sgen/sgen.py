#! /usr/bin/env python

import os
import sys

sys.path.append("lib/dvbobjects.zip")

from dvbobjects.PSI.PAT import *
from dvbobjects.PSI.NIT import *
from dvbobjects.PSI.SDT import *
from dvbobjects.PSI.PMT import *
from dvbobjects.PSI.EIT import *
from dvbobjects.PSI.BAT import *
from dvbobjects.PSI.TDT import *
from dvbobjects.PSI.TOT import *
from dvbobjects.PSI.CAT import *
from dvbobjects.PSI.UNT import *
from dvbobjects.PSI.ECM import *
from dvbobjects.PSI.EMM import *
from dvbobjects.DVB.Descriptors import *
from dvbobjects.MPEG.Descriptors import *
from dvbobjects.DSMCC.Descriptors import *

# 1. Make section (PAT, PMT, CAT, SDT, NIT, BAT, EIT, TOT, TDT...)
# 2. Convert section binary to c array

#pat_start#
# PAT
pat = program_association_section(
	transport_stream_id = 1,
        program_loop = [
    	    program_loop_item(
	        program_number = 1,
    		PID = 1031,
    	    ),  
    	    program_loop_item(
	        program_number = 0, # special program for the NIT
    		PID = 16,
    	    ), 
        ],
        version_number = 1, # you need to change the table number every time you edit, so the decoder will compare its version with the new one and update the table
        section_number = 0,
        last_section_number = 0,
        )
#pat_end#


#pmt_start#
# PMT
pmt = program_map_section(
	program_number = 1,
	PCR_PID = 2064,
	program_info_descriptor_loop = [
	
		#==== Not implemented descriptor lists ====
		# service_move_descriptor
		# data_stream_alignment
		
		registration_descriptor (
			format_identifier = 0x49443320, # apple (http://smpte-ra.org/mpegreg/mpegreg.html)
		),
	],

	stream_loop = [
		stream_loop_item(
			stream_type = 2, # mpeg2 video stream type
			elementary_PID = 2064,
			element_info_descriptor_loop = [
				
				#==== Not implemented descriptor lists ====
				# hierarchy_descriptor

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

			],
		),
		stream_loop_item(
			stream_type = 4, # mpeg2 audio stream type
			elementary_PID = 2068,
			element_info_descriptor_loop = [
				
				audio_stream_descriptor(
					free_format_flag = 1,
					ID = 1,
					layer = 2, 
					variable_rate_audio_indicator = 0,
				),
			],
		),
		stream_loop_item(
			stream_type = 6, # mpeg2 audio stream type
			elementary_PID = 1011,
			element_info_descriptor_loop = [

			#==== Not added descriptor lists ====
			# vbi_teletext_descriptor
			# mosaic_descriptor
			# scrambling_descriptor
			# ancillary_data_descriptor
			# adaption_field_data_descriptor
			# related_content_descriptor
			# ECM_repetition_rate_descriptor
			# enhanced_AC-3_descriptor
		 	# XAIT location_descriptor
		 	# extension_descriptor

				vbi_data_descriptor(
					data_service_id = 0x01,
					vbi_data_descriptor_loop = [
						vbi_data_descriptor_loop_item(
							field_parity = 1,
							line_offset = 0x04,
							),
						vbi_data_descriptor_loop_item(
							field_parity = 0,
							line_offset = 0x07,
							),
					],
				),

				stream_identifier_descriptor(
					component_tag = 0x11,
				),

				teletext_descriptor(
					teletext_descriptor_loop = [
						teletext_descriptor_loop_item(
							ISO639_language_code = 'kor',
							type = 0x02, # teletext subtitle page
							magazine_number = 0x01,
							page_number = 0x05,
						),
					],
				),

				subtitling_descriptor(
					subtitling_data_descriptor_loop = [
						subtitling_data_descriptor_loop_item(
						ISO_639_language_code = 'kor',
						subtitling_type = 0x10, # DVB subtitles with no monitor aspect ratio criticality
						composition_page_id = 1,
						ancillary_page_id = 1,
						),
					],
				),

				private_data_specifier_descriptor(
					private_data_specifier = 0x1011,
				),
			
				data_broadcast_id_descriptor(
					data_broadcast_ID = 0x000A, # DVB-SSU
					OUI_info_loop = [
						OUI_info_loop_item (
							OUI = 0x00015A,
							update_type = 0x01, # with broadcasted UNT, 0x01 without UNT: it requires a stream_identifier_descriptor
							update_versioning_flag = 0, # no version change
							update_version = 1, # increment this at update change
							selector_bytes = "",
						),
					],
					private_data_bytes = "",
				),

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
				),

				application_signalling_descriptor(
					application_type = 0x0010, # HbbTV application
					AIT_version = 1,  # current ait version
				),

			],
		),

	],
        version_number = 1, # you need to change the table number every time you edit, so the decoder will compare its version with the new one and update the table
        section_number = 0,
        last_section_number = 0,
        )    
#pmt_end#

#sdt_start#
# SDT
sdt = service_description_section(
	transport_stream_id = 1,
	original_network_id = 1,
        service_loop = [
	    service_loop_item(
		service_ID = 1,
		EIT_schedule_flag = 0, # 0 no current even information is broadcasted, 1 broadcasted
		EIT_present_following_flag = 0, # 0 no next event information is broadcasted, 1 is broadcasted
		running_status = 4, # 4 service is running, 1 not running, 2 starts in a few seconds, 3 pausing
		free_CA_mode = 0, # 0 means service is not scrambled, 1 means at least a stream is scrambled
		service_descriptor_loop = [

			#==== Not added descriptor lists ====
			# stuffing_descriptor
		 	# NVOD_reference_descriptor
		 	# time_shifted_service_descriptor
		 	# mosaic_descriptor
		 	# CA_identifier_descriptor
		 	# multilingual_service_name_descriptor
		 	# announcement_support_descriptor
		 	# service_identifier_descriptor
		 	# service_availability_descriptor
		 	# XAIT location_descriptor
		 	# extension_descriptor

		    service_descriptor(
				service_type = 1, # digital television service
				service_provider_name = "Test Op",
				service_name = "Test Service 01",
		    ),

		    service_descriptor(
				service_type = 1, # digital television service
				service_provider_name = "TestOp",
				service_name = "Test Service 02",
		    ),    

		    bouquet_name_descriptor(
			    bouquet_name = "TestBouquet",
		    ),

		    country_availability_descriptor(
				country_availability_flag = 1,
				country_code = 'kor',
			),
	    
	    	linkage_descriptor(
				transport_stream_id = 1,
				original_network_id = 1,
				service_id = 1,
				linkage_type = 0x09,
				OUI_loop = [
					OUI_data (
						OUI = 0x00015A,
						selector_bytes = "",
					)
				],
				private_data_bytes = "",
			),

			component_descriptor(
				stream_content = 0x05,  
				component_type = 0x03,  # 0x05, 0x03 : H.264/AVC standard definition video, 16:9 aspect ratio, 25 Hz (Table 26, ETSI 300468)
				component_tag = 0x11, # same as the value of stream_identifier_descriptor's component_tag 
				ISO_639_language_code = 'kor',
				text_char = 'TestTestDes',

			),
			
			telephone_descriptor(
				foreign_availability = 1,
				connection_type = 0x02,
				country_prefix_length = 0x03,
				international_area_code_length = 0x02, 
				operator_code_length = 0x03,
				national_area_code_length = 0x02, 
				core_number_length = 0x04, 
				country_prefix_bytes = "kor",
				international_area_code_bytes = "be",
				operator_code_bytes = "abc",
				national_area_code_bytes = "KA",
				core_number_bytes = "test",
			),
		

			private_data_specifier_descriptor(
				private_data_specifier = 0x1234,
			),

			data_broadcast_descriptor(
	            component_tag = 0x11,
	            ISO_639_language_code = 'kor',
	            selector_bytes = "012345",
	            text_chars = "abcde",
			),

			default_authority_descriptor(
				authority = 'auTest'
			),
		],
	    ),	
        ],
        version_number = 1, # you need to change the table number every time you edit, so the decoder will compare its version with the new one and update the table
        section_number = 0,
        last_section_number = 0,
        )
#sdt_end#

#sdt2_start#
# SDT
sdt2 = service_description_section(
	transport_stream_id = 1,
	original_network_id = 1,
        service_loop = [
		    service_loop_item(
			service_ID = 1,
			EIT_schedule_flag = 0, # 0 no current even information is broadcasted, 1 broadcasted
			EIT_present_following_flag = 0, # 0 no next event information is broadcasted, 1 is broadcasted
			running_status = 4, # 4 service is running, 1 not running, 2 starts in a few seconds, 3 pausing
			free_CA_mode = 0, # 0 means service is not scrambled, 1 means at least a stream is scrambled
			service_descriptor_loop = [

			    service_descriptor(
					service_type = 1, # digital television service
					service_provider_name = "TestOp",
					service_name = "Test Service 01",
			    ),

			    bouquet_name_descriptor(
				    bouquet_name = "TestBouquet",
			    ),

			    country_availability_descriptor(
					country_availability_flag = 1,
					country_code = 'kor',
				),
		    
			],
		    ),	

		    service_loop_item(
			service_ID = 2,
			EIT_schedule_flag = 0, # 0 no current even information is broadcasted, 1 broadcasted
			EIT_present_following_flag = 0, # 0 no next event information is broadcasted, 1 is broadcasted
			running_status = 4, # 4 service is running, 1 not running, 2 starts in a few seconds, 3 pausing
			free_CA_mode = 0, # 0 means service is not scrambled, 1 means at least a stream is scrambled
			service_descriptor_loop = [

			    service_descriptor(
					service_type = 1, # digital television service
					service_provider_name = "TestOp",
					service_name = "Test Service 02",
			    ),

			    bouquet_name_descriptor(
				    bouquet_name = "TestBouquet",
			    ),

			    country_availability_descriptor(
					country_availability_flag = 1,
					country_code = 'eng',
				),
		    
			],
		    ),	


		    service_loop_item(
			service_ID = 3,
			EIT_schedule_flag = 0, # 0 no current even information is broadcasted, 1 broadcasted
			EIT_present_following_flag = 0, # 0 no next event information is broadcasted, 1 is broadcasted
			running_status = 4, # 4 service is running, 1 not running, 2 starts in a few seconds, 3 pausing
			free_CA_mode = 0, # 0 means service is not scrambled, 1 means at least a stream is scrambled
			service_descriptor_loop = [

			    service_descriptor(
					service_type = 1, # digital television service
					service_provider_name = "TestOp",
					service_name = "Test Service 03",
			    ),

			    bouquet_name_descriptor(
				    bouquet_name = "TestBouquet",
			    ),

			    country_availability_descriptor(
					country_availability_flag = 1,
					country_code = 'fre',
				),
		    
			],
		    ),	

        ],
        version_number = 1, # you need to change the table number every time you edit, so the decoder will compare its version with the new one and update the table
        section_number = 0,
        last_section_number = 0,
        )
#sdt2_end#


#nit_start#
# NIT
nit = network_information_section(
	network_id = 1,
        network_descriptor_loop = [
	    network_descriptor(network_name =  "Test",), 
            ],
	transport_stream_loop = [
	    transport_stream_loop_item(
		transport_stream_id = 1,
		original_network_id = 1,
		transport_descriptor_loop = [
		 
		   	#==== Not added descriptor lists ====
			# stuffing_descriptor 
		  	# multilingual_network_name_descriptor
		    # cell_list_descriptor
		    # cell_frequency_link_descriptor
		    # S2_satellite_delivery_system_descriptor
		 	# XAIT location_descriptor
		 	# extension_descriptor

		    service_list_descriptor(
			dvb_service_descriptor_loop = [
			    service_descriptor_loop_item(
				service_ID = 1, 
				service_type = 1, # digital tv service type
			    ),
			],
		    ),

			satellite_delivery_system_descriptor(
				frequency = 12800,
				orbital_position = 5678,
				west_east_flag = 1, 
				polarization = 0x01,
				modulation = 0x00,
				symbol_rate = 27500, 
				FEC_inner = 0x01, 
			),

			cable_delivery_system_descriptor(
				frequency = 640000,
				FEC_outer = 0x01,
				modulation = 0x02, # 32 QAM
				symbol_rate = 27500,
				FEC_inner = 0x03 # 2/3 conv
			),
		    
	    	linkage_descriptor(
				transport_stream_id = 1,
				original_network_id = 1,
				service_id = 1,
				linkage_type = 0x09,
				OUI_loop = [
					OUI_data (
						OUI = 0x00015A,
						selector_bytes = "",
					)
				],
				private_data_bytes = "",
			),

		    terrestrial_delivery_system_descriptor(
		    	center_frequency = 520200, 
		    	bandwidth = 0x00, # 8MHz
		    	priority = 1, # high
				timeslice_ind = 0,
				mpe_fec_ind = 1,
				constellation = 2, # 640QAM
				hierarchy_information = 2, # a=2, native interleaver
				code_rate_HP_stream = 3, # 5/6
				code_rate_LP_stream = 4, # 7/8
				guard_interval = 2, 	# 1/8 
				transmission_mode = 1, # 8k mode
				other_frequency_flag = 0,
		    ),

   			private_data_specifier_descriptor(
				private_data_specifier = 0x1234,
			),

			default_authority_descriptor(
				authority = 'auTest',
			),

			time_slice_fec_identifier_descriptor(
				time_slicing = 1,
				mpe_fec = 1, 
		        frame_size = 2,
		        max_burst_duration = 10,
		        max_average_rate = 1,
		        time_slice_fec_id = 2,
			),

			],		
	     ),
	  ],
        version_number = 1, # you need to change the table number every time you edit, so the decoder will compare its version with the new one and update the table
        section_number = 0,
        last_section_number = 0,

        )
#nit_end#


#bat_start#
# BAT
bat = bouquet_association_section(
	bouquet_id = 0x01,
	bouquet_descriptor_loop = [

	    bouquet_name_descriptor(
		    bouquet_name = "TestBouquet",
	    ),

	],

	transport_stream_loop = [
		transport_stream_loop_item(
			transport_stream_id = 1,
			original_network_id = 1,

			transport_descriptor_loop = [

			  	#==== Not added descriptor lists ====
				# stuffing_descriptor 
				# CA_identifier_descriptor
				# multilingual_bouquet_name_descriptor
			 	# XAIT location_descriptor
			 	# extension_descriptor

			    service_list_descriptor(
				dvb_service_descriptor_loop = [
				    service_descriptor_loop_item(
					service_ID = 1, 
					service_type = 1, # digital tv service type
				    ),

				    service_descriptor_loop_item(
					service_ID = 2, 
					service_type = 1, # digital tv service type
				    ),

				],
			    ),

			    country_availability_descriptor(
					country_availability_flag = 1,
					country_code = 'kor',
				),

		    	linkage_descriptor(
					transport_stream_id = 1,
					original_network_id = 1,
					service_id = 1,
					linkage_type = 0x09,
					OUI_loop = [
						OUI_data (
							OUI = 0x00015A,
							selector_bytes = "",
						)
					],
					private_data_bytes = "",
				),
	
				private_data_specifier_descriptor(
					private_data_specifier = 0x1011,
				),

				default_authority_descriptor(
					authority = 'auTest',
				),


			],
		),

	],

    version_number = 1,
    section_number = 0,
    last_section_number = 0, # pay attention here, we have another section after this!
	)
#bat_end#


#eit_start#
# EIT
eit = event_information_section(
	table_id = EIT_ACTUAL_TS_PRESENT_FOLLOWING,
	service_id = 1,
	transport_stream_id = 1,
	original_network_id = 1,
        event_loop = [
	    event_loop_item(
		event_id = 1,
		start_year = 114, # since 1900
		start_month = 6, 
		start_day = 19, 
		start_hours = 7, # use hex like decimals
		start_minutes = 32,
		start_seconds = 10,
		duration_hours = 1,
		duration_minutes = 40,
		duration_seconds = 58,
		running_status = 4, # 4 service is running, 1 not running, 2 starts in a few seconds, 3 pausing
		free_CA_mode = 0, # 0 means service is not scrambled, 1 means at least a stream is scrambled
		event_descriptor_loop = [
		   	#==== Not added descriptor lists ====
			# stuffing_descriptor 
			# time_shifted_service_descriptor
			# CA_identifier_descriptor
			# multilingual_component_descriptor
			# short_smoothing_buffer_descriptor
			# TVA_id_descriptor
			# XAIT location_descriptor
		 	# extension_descriptor

	    	linkage_descriptor(
				transport_stream_id = 1,
				original_network_id = 1,
				service_id = 1,
				linkage_type = 0x09,
				OUI_loop = [
					OUI_data (
						OUI = 0x00015A,
						selector_bytes = "",
					)
				],
				private_data_bytes = "",
			),

		    short_event_descriptor (
			ISO639_language_code = "kor", 
			event_name = "Test news 24",
			text = "this is an epg event text example",
		    ),

		    extended_event_descriptor (
		    	descriptor_number = 0,
		    	last_descriptor_number = 0,
				ISO639_language_code = "kor",  
				extended_event_loop = [
					extended_event_loop_item (
						item_description = "item description field",
						item = "item field",
					),
				],
				text = "text text",
		    ),

			component_descriptor(
				stream_content = 0x05,  
				component_type = 0x03,  # 0x05, 0x03 : H.264/AVC standard definition video, 16:9 aspect ratio, 25 Hz (Table 26, ETSI 300468)
				component_tag = 0x11, # same as the value of stream_identifier_descriptor's component_tag 
				ISO_639_language_code = 'kor',
				text_char = 'TestTestDes',

			),

			content_descriptor(
				content_user_loop = [
					content_user_loop_item(
						content_nibble_level_1 = 0x01,
						content_nibble_level_2 = 0x04, # comedy
						user_nibble_level_1 = 0x03,
						user_nibble_level_2 = 0x02,
					),
				],

			),

			parental_rating_descriptor(
				country_code = "kor",
				rating = 12,
			),

			telephone_descriptor(
				foreign_availability = 1,
				connection_type = 0x02,
				country_prefix_length = 0x03,
				international_area_code_length = 0x02, 
				operator_code_length = 0x03,
				national_area_code_length = 0x02, 
				core_number_length = 0x04, 
				country_prefix_bytes = "kor",
				international_area_code_bytes = "be",
				operator_code_bytes = "abc",
				national_area_code_bytes = "KA",
				core_number_bytes = "test",
			),
		

			private_data_specifier_descriptor(
				private_data_specifier = 0x1011,
			),

			data_broadcast_descriptor(
	            component_tag = 0x11,
	            ISO_639_language_code = 'kor',
	            selector_bytes = "012345",
	            text_chars = "abcde",
			),

			PDC_descriptor(
				day = 0x0B,
				month = 0x0A,
				hour = 0x3,
				minute = 0x08,
			),

			content_identifier_descriptor(
				crid_descriptor_loop = [
					crid_descriptor_loop_item(
						type = 0x01,
						location = 0x00,
						crid_byte = '\x10\x20\x30\x40',
					),

					crid_descriptor_loop_item(
						type = 0x02,
						location = 0x01,
						crid_ref = 0x5678,
					),

					crid_descriptor_loop_item(
						type = 0x03,
						location = 0x02,
					),
				],
			),
		],
	    ),	    	
            ],
        segment_last_section_number = 1,
        version_number = 1,
        section_number = 0,
        last_section_number = 1, # pay attention here, we have another section after this!
	)
#eit_end#



#tdt_start#
# TDT
tdt = time_date_section(

	# 2011/09/18 11:40:10
	year = 111, #2011
	month = 9,
	day = 18,
	hour = 11,
	minute = 40,
	second = 10,
	)
#tdt_end#

#tot_start#
# TOT
tot = time_offset_section(

	# 2011/09/18 11:40:10
	year = 111, #2011
	month = 9,
	day = 18,
	hour = 11,
	minute = 40,
	second = 10,
	descriptor_loop = [
		local_time_offset_descriptor(
				local_time_offset_loop = [
					local_time_offset_loop_item(
						ISO_639_language_code = 'kor',
						country_region_id = 0,
						local_time_offset_polarity = 0,
						local_time_offset_hour = 12,
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
	],

	)
#tot_end#


#cat_start#
cat = conditional_access_section(

	ca_descriptor_loop = [
		ca_descriptor(
			CA_system_ID = 0x1020,
			CA_PID = 0x1890,
			)
		],

	    version_number = 1,
	    section_number = 0,
	    last_section_number = 1, 
	)
#cat_end#

# Convert binary to c array (unsigned char [])
def bin2array(bin, arrayname, wfile) : 

	line = ''
	count = 0

	wfile.write('static unsigned char ' + arrayname + '[] = {\n')
	b_first = True

	for da in bin:
	#	print(da.encode('hex'))
		aa = ''

		if b_first == False:
			aa = ', '
		else:
			b_first = False
			aa = '\t'


		aa = aa +'0x' + da.encode('hex')
		line = line + aa
		count = count + 1
		
		if count == 8:
			line = line +', \n'
			b_first = True
			wfile.write(line)
			line = ''
			count = 0
		
			

		#print(aa)
	wfile.write(line)

	wfile.write('\n};\n')


def copyCode(key_start, key_end, wfile):

	bWrite = False;

	wfile.write("/*\n")
	for line in open('./sgen.py'):
		if line.find(key_end) != -1 :
			bWrite = False

		if bWrite == True:
			wfile.write(line)

		if line.find(key_start) != -1 :
			bWrite = True

	wfile.write("*/\n\n")

'''
bin : the binary of section 
name : the name of output file
'''
def	genSectionArray(bin, name):

	bin
	bWrite = False;

	line = ''

	wfile = open(name + '.h','w')
	
	wfile.write("#ifndef " + name.upper() + "_TEST_H\n")
	wfile.write("#define " + name.upper() + "_TEST_H\n")
	############# write python code ##############
	key_start = '#'+name+'_start#'
	key_end = '#'+name+'_end#'

	copyCode(key_start, key_end, wfile)

	########### Write C array ############
	bin2array(bin, name, wfile)
	wfile.write("#endif\n")

	wfile.close()


if __name__ == '__main__':

	# Set name and make section array

	genSectionArray(pat.pack(), 'pat')
	genSectionArray(pmt.pack(), 'pmt')
	genSectionArray(sdt.pack(), 'sdt')
	genSectionArray(bat.pack(), 'bat')
	genSectionArray(nit.pack(), 'nit')
	genSectionArray(eit.pack(), 'eit')
	genSectionArray(tot.pack(), 'tot')
	genSectionArray(tdt.pack(), 'tdt')
	genSectionArray(cat.pack(), 'cat')

	genSectionArray(sdt2.pack(), 'sdt2')
