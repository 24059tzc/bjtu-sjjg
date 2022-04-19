#include<stdio.h>
int Ack(int m, int n)
{
	int a[100],i=0,k=0;
	while (1)
	{
		if (m == 0) {
			n = n + 1;
			if (i>0&&k!=0) {
				m = a[i-1]; 
				i--;
			}
			else return n;
		}
		else if(n == 0) {
			m = m - 1; n = 1;
		}
		else
		{
			a[i] = m-1;
			n = n - 1;
			i++;
			k = 1;
		}
	}
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	printf("Ack(%d,%d)=%d\n", m, n, Ack(m, n));
}