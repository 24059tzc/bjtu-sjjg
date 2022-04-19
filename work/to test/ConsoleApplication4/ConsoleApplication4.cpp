#include<stdio.h>
#include<math.h>
int main(void)
{
	/*********Begin*********/
	double a,b = 0;
	for (a = 1; a <= 100; a++)
	{
		b =b+ pow(-1, (a + 1)) * (1 / a);
	}
	printf("%.3f", b);

	/*********End**********/
	return 0;
}