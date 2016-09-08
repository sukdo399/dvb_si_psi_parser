/*
 *Original Author:	shko
 */

// to use valgrind for memory-check
// valgrind -v --tool=memcheck --leak-check=full --vgdb=yes --track-fds=yes --trace-children=yes --run-libc-freeres=no --leak-resolution=high --log-file=./valgrind_test.txt ./hdvblib_test



#include "gtest.h"
#include "tap/tap.h"




GTEST_API_ int main(int argc, char **argv)
{

// use TAP.
#if 0
    testing::InitGoogleTest(&argc, argv);

    testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();

    // Delete the default listener
    //delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new tap::TapListener());
    printf("Running main() using TAP\n");

    return RUN_ALL_TESTS();

#elif 0

#if 0
#include "descriptor_test.h"
#include <sys/time.h>
#endif
    testing::InitGoogleTest(&argc, argv);

    testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();

    // Delete the default listener
    delete listeners.Release(listeners.default_result_printer());


    printf("Running main() for time check\n");

    struct timeval now;
    gettimeofday(&now, NULL);
    int dd3 = (now.tv_sec) * 1000 + now.tv_usec / 1000;

    RUN_ALL_TESTS();

    gettimeofday(&now, NULL);
    int dd4 = (now.tv_sec) * 1000 + now.tv_usec / 1000;

    printf("elapsed time (msec): %ld\n", dd4-dd3);

    return 0;
#else

    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

#endif
}

