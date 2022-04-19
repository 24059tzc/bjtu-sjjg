#include <iostream>

int main()
{
	int score;
	scanf("%d", &score);
	if (score > 100 || score < 0)
	{
		printf("Wrong input. The score should be between 0~100.");
	}
	else if(score >= 90)
	{
		printf("The grade is A");
	}
	else if (score >= 80)
	{
		printf("The grade is B");
	}
	else if (score >= 70)
	{
		printf("The grade is C");
	}
	else if (score >= 60)
	{
		printf("The grade is D");
	}
	else 
	{
		printf("The grade is F");
	}
}
