#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void word()
{
    FILE* fp;
    char name[100] = { 0 };//�洢·����
    int ch;
    int total = 0;

    scanf("%s", name);

    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        total++;
    }
    printf("�ַ���:%d", total);
}

void words()
{
    int count = 0;
    int flag = 0;//��־λ�������ո񶺺ž���Ϊ0
    int ch;
    char name[100] = { 0 };//�洢·����
    scanf("%s", name);
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
    printf("������:%d", count);

}
int main()
{
    char in[5] = { 0 };
    char chs_c[5] = "-c";
    char chs_w[5] = "-w";

    scanf("%s", in);
    if (0 == strcmp(in, chs_c))
    {
        word();
    }
    if (0 == strcmp(in, chs_w))
    {
        words();
    }
    return 0;
}
