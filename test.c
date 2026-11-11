#include <stdio.h>
#define ADD(a,b) ((a)+(b))
#define D 4
// single-line comment
int main()
{
    int a = 6, b = 4;
    int d = a/b;
    int/*glued*/c = 5;

    /* multi-line
       block comment */

    printf("http://x\n");
    printf("a /* not comment */\n");
    printf("PI\n");

    int z=D;
    int x=ADD(2,3);
    printf("%d\n",x);

    return 0;
}