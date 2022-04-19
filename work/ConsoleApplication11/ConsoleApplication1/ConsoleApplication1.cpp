#include<stdio.h>
int main()
{
	char a[100];
	char b[100];
	int i, j;
	scanf("%s", a);
	i = 0;
	j = 0;
	for (; a[j] != '\0'; i++)
	{
		if (j % 2 == 0 && i != 0)
		{
			b[i] = ' ';
			i++;
		}
			b[i] = a[j];
			j++;
	}
	b[i] = '\0';
	printf("%s", b);
}