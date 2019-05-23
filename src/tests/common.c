#include <stdio.h>
#include <board.h>
#include <plat.h>
#include <plat/test/pl061.h>
#include <plat/test/gcov.h>
#include <plat/test/uart.h>
#include <plat/test/semihosting.h>
#include <assert.h>

#include "test.h"
#include <plat/test/gcov.h>

void __assert_func(const char *fn,
                   int line_no,
                   const char *assert_func,
                   const char *asdf)
{

    UNUSED(asdf);
    printf("Assert failed %s:%i (%s)\n\r",fn, line_no, assert_func);

    gcov_final();
    semihosting_sys_exit(1);

    while(1);
}


void pb_main(void)
{

    test_uart_init();

    pl061_init(0x09030000);

	gcov_init();
    test_main();
    gcov_final();
    printf ("Calling exit function\n\r");
    semihosting_sys_exit(0);
}
