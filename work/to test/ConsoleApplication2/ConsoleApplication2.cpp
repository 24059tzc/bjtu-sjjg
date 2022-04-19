#include<stdio.h>
int main(void)
{
	/*********Begin*********/
	int a, b, c;
	char ch;
	for (c = 1; (ch = getchar()) != '\n';)
	{
		if (ch >= '0' && ch <= '9') { a = (int)ch-48; c = c * a; continue; }
		break;
	}
	printf("%d", c);
	/*********End**********/
	return 0;
}
