#include <stdio.h>
void sort(int s[], int n);
float average(int s[], int n);
int main()
{
    int j, a[] = { 60,70,55,89,90,100,67,88,76,94};
    sort(a, 10);
    for (j = 0; j < 10; j++)
        printf("%d ", a[j]);
    printf("平均分=%.2f", average(a, 10));
}
void sort(int s[], int n)
{
    int j, t, k;
    for (j = 0; j < n - 1; j++)
    {
        for (k = j + 1; k < n; k++)
        {
            if (s[j] < s[k])
            {
                t = s[j];
                s[j] = s[k];
                s[k] = t;
            }
        }
    }
}
 float average(int s[], int n)
{
    int i;
    float m,pj=0;
    for (i = 0; i < n; i++)
    {
        pj = pj + s[i];
    }
    m = pj / n;
    return(m);
}