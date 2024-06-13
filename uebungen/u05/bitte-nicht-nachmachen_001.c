#include <stdio.h>

int main()
{
    int i = 1;
    printf("%d %d %d", i++, i++, i++);
    printf(" %d", i);

    i = 1;
    printf("\n");
    printf("%d %d %d", ++i, ++i, ++i);

    return 0;
}

