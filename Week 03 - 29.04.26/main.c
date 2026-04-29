#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    atoi(argv[2]);
    printf("argc -> (%d)\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    printf("Hello\n");

    /* code */
    return 0;
}
