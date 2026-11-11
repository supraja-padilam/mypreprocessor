#include <string.h>
#include "macro.h"

char names[50][50];
char bodies[50][100];
int count = 0;

void store_macro(char *text)
{
    int i = 0, j = 0;

    while (text[i] == ' ' || text[i] == '\t')
        i++;

    while (text[i] != ' ' && text[i] != '\t' && text[i] != '\0')
    {
        if (text[i] == '(')
            return;
        names[count][j++] = text[i++];
    }
    names[count][j] = '\0';

    while (text[i] == ' ' || text[i] == '\t')
        i++;

    j = 0;
    while (text[i] != '\0')
        bodies[count][j++] = text[i++];
    bodies[count][j] = '\0';

    count++;
}

char *find_macro(char *word)
{
    int i;
    for (i = 0; i < count; i++)
        if (strcmp(names[i], word) == 0)
            return bodies[i];
    return NULL;
}