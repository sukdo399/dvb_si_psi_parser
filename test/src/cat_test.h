#ifndef CAT_TEST_H
#define CAT_TEST_H
/*
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
*/

static unsigned char cattest[] = {
    0x01, 0xb0, 0x0f, 0xff, 0xff, 0xc3, 0x00, 0x01,
    0x09, 0x04, 0x10, 0x20, 0xf8, 0x90, 0xfc, 0x9e,
    0x54, 0x6f
};
#endif
