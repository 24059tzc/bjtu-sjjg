#include <stdio.h>
#define swap(x,y) {int t;t=x;x=y;y=t;}
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    swap(x, y);
    printf("%d,%d", x, y);
}