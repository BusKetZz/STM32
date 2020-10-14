/* Support files for GNU libc.  Files in the system namespace go here.
   Files in the C namespace (ie those that do not start with an
   underscore) go in .c.  */

/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "debug.h"

#include "stm32f4xx_ll_usart.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>



/*****************************************************************************/
/* SYSTEM CALLS DEFINITIONS */
/*****************************************************************************/

int _write(int file, char *ptr, int len)
{
    (void)file;
	int DataIdx;
    LL_USART_Enable(DEBUG_UART_PERIPHERAL);

	for (DataIdx = 0; DataIdx < len; DataIdx++) {
        LL_USART_TransmitData8(DEBUG_UART_PERIPHERAL, *(uint8_t *)ptr);
	}

    LL_USART_Disable(DEBUG_UART_PERIPHERAL);

	return len;
}



/*****************************************************************************/
/* UNUSED SYSTEM CALLS */
/*****************************************************************************/

caddr_t _sbrk(int incr)
{
    (void)incr;
	return (caddr_t)0;
}



int _close(int file)
{
    (void)file;
	return -1;
}



int _fstat(int file, struct stat *st)
{
    (void)file;
    (void)st;
	return 0;
}



int _isatty(int file)
{
    (void)file;
	return 1;
}



int _lseek(int file, int ptr, int dir)
{
    (void)file;
    (void)ptr;
    (void)dir;
	return 0;
}



int _read(int file, char *ptr, int len)
{
    (void)file;
    (void)ptr;
    (void)len;
    return len;
}

