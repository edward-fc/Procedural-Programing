#include <stdio.h>

int lets_get_serious()
{
    return 0;
}

int main()
{
    int* adress = (void *)lets_get_serious;
    printf("\n \n Even functions have address. \n \n");

    printf("The address of main function = %p \n \n", (void *)main);

    printf("The address of lets_get_serious function = %p \n \n", (void *) lets_get_serious);
    printf ("Now the magic ! Content of \"*var_address\" = %d\n", *adress);

    return 0;
}