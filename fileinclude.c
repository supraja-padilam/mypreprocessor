#include<stdio.h>
#include"fileinclude.h"
#include<string.h>
#include<stddef.h>
#include"comment_removal.h"
#include"macro.h"
int c=0;
void header(FILE *in, FILE *out)
{
    char line[200];
    char name[100];
    char path[200];
    int ch,n=0,i,j=0;
    FILE *inc;
    while((ch = fgetc(in)) != EOF && ch!='\n')
    {
        line[n++]=ch;
    }
    line[n]='\0';
    if(strncmp(line,"include",7)!=0)
    {
           if (strncmp(line, "define", 6) == 0)
           {
            store_macro(line + 6);
            return;
           }
       fprintf(out,"#%s\n",line);
       return;
    }
    i=7;
    while(line[i]!='<'&&line[i]!='"'&&line[i]!='\0')
        i++;
    if(line[i]=='\0')
    {
        fprintf(out,"#%s\n",line);
        return;
    }
    i++;
    while(line[i]!='>'&&line[i]!='"'&&line[i]!='\0')
    {
        name[j++]=line[i++];
    }
    name[j]='\0';
    if(c>=1)
    {
        fprintf(out,"#%s\n",line);
        return;
    }
    inc=fopen(name,"r");
    if(inc==NULL)
    {
        strcpy(path, "/usr/include/");
        strcat(path,name);
        inc=fopen(path,"r");
    }
    if(inc==NULL)
    {
        fprintf(out,"#%s\n",line);
        return;
    }
    c++;
    remove_comments(inc,out);
    c--;
    fclose(inc);
    fputc('\n',out);
}
