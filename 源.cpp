#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void word(char* name)
{
    FILE* fp;
    int ch;
    int total = 0;

    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        total++;
    }
    printf("字符数:%d", total);
}

void words(char* name)
{
    int count = 0;
    int flag = 0;//标志位，遇到空格逗号就置为0
    int ch;
   
    FILE* fp = fopen(name, "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch) && flag == 0)
        {
            count++;
            flag = 1;
        }
        if (ch == 44 || ch == 32)
            //if(!isalpha(fgetc(fp)))
        {
            flag = 0;
        }
    }
    printf("单词数:%d", count);

}
int main(int argc,char* argv[])
{
    
    if (!strcmp(argv[1],"-c"))
    {
        word(argv[2]);
    }
    if (!strcmp(argv[1], "-w"))
    {
        words(argv[2]);
    }
    return 0;
}
