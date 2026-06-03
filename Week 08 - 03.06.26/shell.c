// int main(int argc, char const *argv[])
// {
//     // 0,1,2,3....
//     //*input = ls/0 -l\0        | grep C
//     // *[] {input,input+3,input+5,input+7,input+12,null}
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#define SIZE 256
#define blue() printf("\033[0;34m")
#define reset() printf("\033[0m")
#define green() printf("\033[0;92m")
#define bold() printf("\e[1m")
#define boldOff() printf("\e[m")
void welcome()
{
    char *logo[] = {"                     aRTI//BARK             ____\n",
                    "             simpleSH//////////Shl         |B//S|", "    |\n",
                    "          SH//////YS           shell//Sh   |A@@I|", "    | Welcome to simple shell\n",
                    " Sim aSystemSH//Sh              sys//B     |R$$M|", "    | Version 1.0\n",
                    " ArtABBBaraKk///Sh               sM//E     |A^^P|", "    |\n",
                    "         pCCCCY//h          eSS@@ y//E     |K**L|", "    | https://github.com/BSharabi\n",
                    "         SPPPP///a          pP///AC//E     |&&&E|", "    |\n",
                    "              A//A            smP////S     |A**S|", "    | Have fun!\n",
                    "              p///Ac            sE///a     |R##H|", "    |\n",
                    "              P////YCpc           L//L     |T!!E|", "    | Wanna support simple shell?\n",
                    "       scccccp///pSP///p          p//l     |I%%L|", "    |\n",
                    "      sY/////////y  caa           S//h     |U--L|", "    |\n",
                    "       shsSellH//Ya              pY/Sh     |MIGT|", "    |\n",
                    "        sH/ShS////YCc          aC//Yp      |____|", "    |\n",
                    "         Si  shlll//SHsimpleSH//LSs\n",
                    "                  shell//////IPSHs\n",
                    "                       artium\n", NULL};
    int i = 0;
    green();

    do
    {
        printf("%s", logo[i++]);
        if (i % 2 != 0 || i > 26)
            green();
        else
            blue();
    } while (logo[i]);
    reset();
    puts("\n");
}

char **splitArgv(char *input)
{
    int size = 1;
    char **args = (char **)malloc(size * sizeof(char *));
    int i = 0;
    int index = 0;
    char ch;
    // ls\0-l\0|\0grep\0c\0
    while ((ch = *(input + i)) != '\0' /* input[i] != '\0' */)
    {
        if (ch == ' ')
        {
            input[i] = '\0'; 
            i++;
            continue;
        }

        args = realloc(args, ++size * sizeof(char *));
        args[index++] = input + i;
        while ((ch = *(input + i)) != ' ' && ch != '\0')
            i++;
    }
    args[index] = NULL;

    return args;
}

char **splitArgs(char *input)
{
    int size = 1;
    char **args = (char **)malloc(size * sizeof(char *));
    int index = 0;
    char *addr = strtok(input, " ");

    while (addr != NULL)
    {
        args[index++] = addr;
        args = realloc(args, ++size * sizeof(char *));
        addr = strtok(NULL, " ");
    }
    args[index] = NULL;

    return args;
}
void getLocation()
{

    char location[SIZE];
    char hostname[SIZE];
    char *username;

    if (getcwd(location, SIZE) == NULL)
    {
        puts("ERR");
        exit(1);
    }

    username = getlogin();
    if (username == NULL)
    {
        struct passwd *pw = getpwuid(getuid());
        username = (pw != NULL) ? pw->pw_name : "user";
    }

    if (gethostname(hostname, SIZE) != 0)
        strcpy(hostname, "localhost");

    green();
    printf("%s", username);
    printf("@");
    printf("%s", hostname);
    reset();
    printf(":");
    blue();
    printf("%s", location);
    reset();
    printf("$ ");
}
char *getInput()
{

    int ch;
    int size = 1;
    char *input = (char *)malloc(size * sizeof(char));
    if (input == NULL)
        return NULL;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        input[size - 1] = (char)ch;
        size++;
        char *tmp = (char *)realloc(input, size * sizeof(char));
        if (tmp == NULL)
        {
            free(input);
            return NULL;
        }
        input = tmp;
    }
    *(input + size - 1) = '\0';

    return input;
}
int main(int argc, char const *argv[])
{

    char *input;
    int cnt = 0;
    welcome();
    while (cnt < 5)
    {
        getLocation();
        input = getInput();
        if (input == NULL)
        {
            cnt++;
            continue;
        }

        char **argument = splitArgs(input);
        int i = 0;
        while (*(argument + i))
        {
            puts(argument[i++]);
        }

        if (argument[0] != NULL && strcmp(argument[0], "exit") == 0)
        {
            free(argument);
            free(input);
            return 0;
        }

        free(argument);
        free(input);
        cnt++;
    }

    return 0;
}
