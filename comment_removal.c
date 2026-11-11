#include "comment_removal.h"
#include"fileinclude.h"
#include"macro.h"

int is_letter(int ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_')
        return 1;
    return 0;
}

int is_wordchar(int ch)
{
    if (is_letter(ch) || (ch >= '0' && ch <= '9'))
        return 1;
    return 0;
}

void remove_comments(FILE *in, FILE *out)
{
    int ch, next = 0, prev;
   char word[50];
char *body;
int w;

    while ((ch = fgetc(in)) != EOF)
    {
        //string
        if (ch == '"')
        {
            fputc(ch, out);
            while ((ch = fgetc(in)) != EOF && ch != '"')
            {
                fputc(ch, out);
                if (ch == '\\' && (next = fgetc(in)) != EOF)
                    fputc(next, out);
            }
            if (ch == '"')
                fputc(ch, out);
        }
        //header
        else if(ch=='#')
        {
            header(in,out);
        }
        //multi-line
        else if (ch == '/' && (next = fgetc(in)) == '*')
        {
            prev = 0;
            while ((ch = fgetc(in)) != EOF && !(prev == '*' && ch == '/'))
                prev = ch;
            fputc(' ', out);
        }
        //one line comment removal
        else if (ch == '/' && next == '/')
        {
            while ((ch = fgetc(in)) != '\n' && ch != EOF);
            fputc(' ', out);
            if (ch == '\n')
                fputc('\n', out);
        }
        //macro
        else if (is_letter(ch))
        {
            w = 0;
            word[w++] = ch;
            while ((ch = fgetc(in)) != EOF && is_wordchar(ch))
                word[w++] = ch;
            word[w] = '\0';
            if (ch != EOF)
                ungetc(ch, in);

            body = find_macro(word);
            if (body != NULL)
                fputs(body, out);
            else
                fputs(word, out);
        }
        else
        {
            fputc(ch, out);
            if (ch == '/' && next != EOF)
                ungetc(next, in);
        }
    }
}