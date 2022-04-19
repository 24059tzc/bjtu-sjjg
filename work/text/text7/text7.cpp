#include <iostream>

int main()
{
	int n,i= 0, b = 0;
	scanf("%d", &n);
	int a[100];
	for (i = 0;; i++)
	{
		a[i] = n % 10;
		n = n / 10;
		if (n == 0)
			break;
		b++;
	}
	for (; b >= 0; b--)
	{
		switch (a[b])
		{
		case 0:printf("zero "); break;
		case 1:printf("one "); break;
		case 2:printf("two "); break;
		case 3:printf("three "); break;
		case 4:printf("four "); break;
		case 5:printf("five "); break;
		case 6:printf("six "); break;
		case 7:printf("seven "); break;
		case 8:printf("eight "); break;
		case 9:printf("nine "); break;
		}

	}
}

