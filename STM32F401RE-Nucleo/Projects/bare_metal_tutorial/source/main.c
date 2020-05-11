#include <stm32f401xe.h>

#include <stdio.h>



extern void initialise_monitor_handles(void);



int main()
{
	initialise_monitor_handles();

	printf("Hello World!\n");

	while(1) {
		printf("Hello World!\n");
	}
}

