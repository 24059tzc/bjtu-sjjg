#include<stdio.h>
#include<string.h>

void func1(char* s)
{
	for (int i = 0; i < strlen(s); s++)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s = 'Z' - *s + 'A';
	}
}
char* func2(char *s)
{
	char a[100];
	int i;
	for ( i = 0; i < strlen(s);s++)
	{
		if (*s>='0'&&*s<='9')
		{
			a[i] = *s;
			i++;
		}
	}
	a[i] = '\0';
	return a;
}
int main()
{
	char v[100];
	scanf("%s", v);
	func1(v);
	printf("%s", v);
	char *ss=func2(v);
		printf("%s", ss);
}