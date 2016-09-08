#ifndef TOT_TEST_H
#define TOT_TEST_H
/*
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
*/

static unsigned char tottest[] = {
    0x73, 0x70, 0x1a, 0xda, 0x0e, 0x11, 0x40, 0x10,
    0xf0, 0x0f, 0x58, 0x0d, 0x6b, 0x6f, 0x72, 0x02,
    0x12, 0x34, 0xdd, 0xfc, 0x11, 0x17, 0x40, 0x08,
    0x52, 0xfb, 0xc5, 0x96, 0x1b
};
#endif // TOT_TEST_H
