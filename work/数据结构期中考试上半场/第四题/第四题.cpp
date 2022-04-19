#include<stdio.h>
float findMax(float A[], int i, int j)
{
	//★★★请补全代码
	if (i >= j)
	{
		return A[j];
	}
	else if (findMax(A, i, i) > findMax(A, i + 1, j))
	{
	return A[i];
	}
	else return findMax(A, i + 1, j);
}

int main() {
	int i, n = 10;
	float A[10];
	for (i = 0; i < n; i++)
		scanf("%f", &A[i]);
	float max = findMax(A, 0, n - 1);
	printf("最大值：%.2f\n", max);
}
