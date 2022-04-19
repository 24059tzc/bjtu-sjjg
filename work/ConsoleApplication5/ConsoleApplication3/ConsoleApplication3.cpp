#include <stdio.h>
#include <math.h>

/***** 以下一行有错误 *****/
double fun(double a, double x0)
{
	double x1, y;
	x1 = (x0 + a / x0) / 2.0;

	/***** 以下一行有错误 *****/
	if (fabs(x1 - x0) <= 0.00001)
		y = fun(a, x1);
	else
	{
		y = x1;
		return y;
	}
}


int main()
{
	double x;
	scanf("%lf", &x);
	printf("The square root of %lf is %lf\n", x, fun(x, 1.0));

	return 0;
}