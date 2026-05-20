#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
                    "                       artium\n",NULL};
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
        if(strcmp(input,"exit")==0)
            return 0;
        puts(input);
        free(input);
    }

    return 0;
}
