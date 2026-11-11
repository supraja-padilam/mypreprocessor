#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"comment_removal.h"
int main(int argc,char **argv)
{

    if(argc!=2)
    {
        printf("Usage:./a.out fname\n");
        return 1;
    }
    char outputfname[50];
    strcpy(outputfname,argv[1]);
    char *p;
    p=outputfname;
    while(*p!='\0')
    {
        if(*p=='.' && *(p+1)=='c' && *(p+2)=='\0')
        {
            p++;
            *p='i';
        }
        else p++;
    }

    FILE *fp=fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("input file not found\n");
        return 1;
    }
    FILE *fr=fopen(outputfname,"w");
    if(fr==NULL)
    {
        printf("output file not found\n");
        fclose(fp);
        return 1;
    }
   remove_comments(fp,fr);

    fclose(fp);
    fclose(fr);
    return 0;
}