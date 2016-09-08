/*
 *Original Author:	shko
 */

#ifndef PMT_TEST_H
#define PMT_TEST_H



/*
program_map_section(
   program_number = 1,
   PCR_PID = 2064,
   program_info_descriptor_loop = [],
   stream_loop = [
             stream_loop_item(
                        stream_type = 2, # mpeg2 video stream type
                        elementary_PID = 2064,
                        element_info_descriptor_loop = []
             ),
             stream_loop_item(
                        stream_type = 4, # mpeg2 audio stream type
                        elementary_PID = 2068,
                        element_info_descriptor_loop = []
             ),
             stream_loop_item(
                        stream_type = 6, # mpeg2 audio stream type
                        elementary_PID = 1011,
                        element_info_descriptor_loop = [

                                  subtitling_descriptor(
                                             ISO_639_language_code = 'kor',
                                             subtitling_type = 0x10, # DVB subtitles with no monitor aspect ratio criticality
                                             composition_page_id = 1,
                                             ancillary_page_id = 1,
                                             ),
                        ]
             ),

   ],
version_number = 1, # you need to change the table number every time you edit, so the decoder will compare its version with the new one and update the table
section_number = 0,
last_section_number = 0,
)
*/
#if 0
// crc error case.
static unsigned char PMT_out[] = {
    0x02, 0xb0, 0x26, 0x00, 0x01, 0xc3, 0x00, 0x00,
    0xe8, 0x10, 0xf0, 0x00, 0x02, 0xe8, 0x10, 0xf0,
    0x00, 0x04, 0xe8, 0x14, 0xf0, 0x00, 0x06, 0xe3,
    0xf3, 0xf0, 0x0a, 0x59, 0x08, 0x6b, 0x6f, 0x72,
    0x10, 0x00, 0x01, 0x00, 0x01, 0xf2, 0x2c, 0x20,
    0x69
};
#else
static unsigned char PMT_out[] = {
    0x02, 0xb0, 0x26, 0x00, 0x01, 0xc3, 0x00, 0x00,
    0xe8, 0x10, 0xf0, 0x00, 0x02, 0xe8, 0x10, 0xf0,
    0x00, 0x04, 0xe8, 0x14, 0xf0, 0x00, 0x06, 0xe3,
    0xf3, 0xf0, 0x0a, 0x59, 0x08, 0x6b, 0x6f, 0x72,
    0x10, 0x00, 0x01, 0x00, 0x01, 0xf2, 0x2c, 0x20,
    0x66
};
#endif




#endif // PMT_TEST_H
