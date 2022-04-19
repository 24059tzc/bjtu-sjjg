#define N 10
#include <stdio.h>
int Maxcol(int a[][N], int n, int row)
{
    int i, maxcol = 0;
    for (i = 1; i < n; i++)
        if(a[row][i] > a[row][maxcol]) maxcol = i;
    return maxcol;
}
int Minrow(int a[][N], int m, int col)
{
    int i, minrow = 0;
    for (i = 1; i < m; i++)
        if (a[i][col] < a[minrow][col]) minrow = i;
    return minrow;
}
int main() {
    int m, n, i, j;
    int maxcol, minrow;
    int a[N][N];
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++) for (j = 0; j < n; j++)
        scanf("%d", &a[i][j]);
    for (i = 0; i < m; i++) {
        maxcol = Maxcol(a, n, i);
        minrow = Minrow(a, m, maxcol);
        if (i == minrow) {
            printf("Array[%d][%d]=%d\n", i, maxcol, a[i][maxcol]);
            break;
        }
    }
    if (i >= m) printf("None\n");
}
