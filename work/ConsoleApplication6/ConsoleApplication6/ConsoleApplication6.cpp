#include <stdio.h>
long int max(long int a, long int b)
{
	long int c = 0;
	while (c = a % b)
	{
		a = b;
		b = c;
	}
	return b;
}
long long int min(long int a, long int b)
{
	long long int c;
	c = (a * b) / max(a, b);
	return c;
}
void main()
{
	long int a, b;
	scanf("%d %d", &a, &b);
	if (a > 0 && b > 0)
		printf("%ld %lld", max(a, b), min(a, b));
	else
		printf("Input Error");
}