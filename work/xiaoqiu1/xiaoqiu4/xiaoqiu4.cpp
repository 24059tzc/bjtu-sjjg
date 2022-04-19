#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int j;
	int x = 0;
	int y = 5;

	int velocity_y = 1;
	int velocity_x = 1;
	int left = 0;
	int right = 20;
	int top = 0;
	int bottom = 10;

	while (1)
	{
		x = x + velocity_x;
		y = y + velocity_y;

		system("cls");

		for (i = 0; i < x; i++)
			printf("\n");
		for (j = 0; j < y; j++)
			printf(" ");
		printf("o");
		printf("\n");
		if ((x == top)||(x==bottom))
			velocity_x = -velocity_x;
		if ((y == left)||(y==right))
			velocity_y = -velocity_y;
	}
	return 0;
}

