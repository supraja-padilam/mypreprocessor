#include <stdio.h>

#define PI 3.14
#define SQUARE(x) ((x)*(x))
#define MAX(a,b) ((a)>(b)?(a):(b))

 
int main()
{
    int a = 6, b = 4;           
    int d = a/b;                
    int c = 5;         

     

    printf("http://x\n"");             
    printf("a /* not comment */\n"");    
    printf("PI\n"");                     

    float area = PI * 2 * 2;          
    int sq = SQUARE(5);                 
    int m = MAX(a, b);                  
    int e = SQUARE(a + 1);             

    printf("%d %d %d\n"", sq, m, e);
    return 0;
}