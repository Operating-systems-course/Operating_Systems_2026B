#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 256
#define blue() printf("\033[0;34m")
#define reset() printf("\033[0m")
#define green() printf("\033[0;92m")
#define bold() printf("\e[1m")
#define boldOff() printf("\e[m")

void getLocation()
{

    char location[SIZE];
    if (getcwd(location, SIZE) == NULL)
    {
        puts("ERR");
        exit(1);
    }
    green();
    printf("Barak");
    printf("@");
    printf("Macbook");
    reset();
    printf(":");
    blue();
    printf("%s", location);
    reset();
    printf("$ ");
}
char *getInput()
{

    char ch;
    int size = 1;
    char *input = (char *)malloc(size * sizeof(char));
    if (input == NULL)
        return NULL;
    while ((ch = getchar()) != '\n')
    {
        input[size - 1] = ch;
        size++;
        if ((input = (char *)realloc(input, size * sizeof(char))) == NULL)
        {
            return NULL;
        }
    }
    *(input + size - 1) = '\0';

    return input;
}
int main(int argc, char const *argv[])
{

    char *input;
    int cnt = 0;
    while (cnt < 5)
    {
        getLocation();
        input = getInput();
        if (input == NULL)
        {
            cnt++;
            continue;
        }

        puts(input);
        free(input);
    }

    return 0;
}
