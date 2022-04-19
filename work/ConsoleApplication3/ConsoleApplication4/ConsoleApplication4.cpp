#include<stdio.h>
int main(void)
{
	/*********Begin*********/
	char ch;
	int a = 0, b = 0, c = 0, d = 0;
	for (; (ch = getchar()) != '\n'; )
	{
		if (ch == ' ') { c++; continue; }
		if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') { a = a + 1; continue; }
		if (ch >= '0' && ch <= '9') { b++; continue; }
		else { d++; continue; }
		break;

	}
	printf("%d %d %d %d", a, b, c, d);


	/*********End**********/
	return 0;
}