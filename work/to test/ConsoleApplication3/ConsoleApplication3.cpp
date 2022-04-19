#include<stdio.h>
int main(void)
{
    /*********Begin*********/
    int n,c, a, m = 0;
    scanf_s("%d", &n);
    for (a=1; n >= 1; n--)
    {
        for (c=n; c >=1 ;c-- )
        {
            a = a * c;
           
        }
      

        m = m + a;
        a = 1;
    }
    printf("%d", m);

    /*********End**********/
    return 0;
}
