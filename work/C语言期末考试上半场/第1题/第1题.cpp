#include<stdio.h>
int main()
{
	int Wrinting;
	int Testing;
	scanf("%d%d", &Wrinting, &Testing);
	if (((Wrinting < 0) || (Wrinting > 100)) || ((Testing < 0) || (Testing > 100)))
		printf("wrong score");
	else
	{
		int score = 0.6 * Wrinting + 0.4 * Testing;
		if (score < 60)
		{
			printf("Writing score: %d\nTesting score : %d\nFinal score is %d, the grade is fail\n", Wrinting, Testing, score);
		}
		else if (score >= 60 && score < 70)
		{
			printf("Writing score: %d\nTesting score : %d\nFinal score is %d, the grade is pass\n", Wrinting, Testing, score);
		}
		else if (score >= 70 && score < 85)
		{
			printf("Writing score: %d\nTesting score : %d\nFinal score is %d, the grade is good\n", Wrinting, Testing, score);
		}
		else
		{
			printf("Writing score: %d\nTesting score : %d\nFinal score is %d, the grade is excellent\n", Wrinting, Testing, score);
		}
	}
}