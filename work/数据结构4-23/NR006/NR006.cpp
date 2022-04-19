#include<stdio.h>
int Ack(int m, int n)
{
	if (m == 0)return n + 1;
	else if (n == 0) Ack(m - 1, 1);
	else Ack(m - 1, Ack(m, n - 1));
}
int main()
	{
	int m, n;
	scanf("%d %d", &m, &n);
	printf("Ack(%d,%d)=%d\n", m, n, Ack(m, n));
	}