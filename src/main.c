#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
    int numb = 1996;
    char *generation = generation_type(numb);

    printf("Your Generation Type is: %s\n",generation);

    return 0;

}