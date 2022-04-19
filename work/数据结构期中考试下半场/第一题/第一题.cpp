#include<stdio.h>
char m[] = { "100010011010111" }; /*  给定m序列 */
int main()
{

	//★★★请补全代码
	int a=0, b=0,i=0;
	while (m[i]!='\0')
	{
		if (m[i] == '0')a++;
		else b++;
		i++;
	}
	printf("the number of 0 = %d\nthe number of 1 = %d\n", a, b);
}
