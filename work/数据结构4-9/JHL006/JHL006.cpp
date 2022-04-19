#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[100][10];
	char c;
	int j = 0, k = 0;
	for (int i = 0; i < 100000; i++)
	{
		c = getchar();
		if (c == ' ' || c == '\n')
		{
			a[j][k] = '\0';
			j++;
			k = 0;
		}
		else if (c == '.' || c == ';' || c == ',')
		{
			continue;
		}
		else if (c >= 'a' && c <= 'z')
		{
			a[j][k] = c;
			k++;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			a[j][k] = c + 'a' - 'A';
			k++;
		}
		else {
			a[j][k] = '\0';
			j++;
			k = 0; break;
		}
	}
	int Long = j - 1;
	k = 0;
	struct number
	{
		char a[10];
		int num = 0;
	};
	number numb[100];
	for (int i = 0; i < Long; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (strcmp(a[i], numb[j].a) == 0) { numb[j].num++; break; }
		}
		if (j == 100)
		{
			strcpy(numb[k].a, a[i]); numb[k].num = 1;
			k++;
		}
	}
	number temp2[100],temp3[100];
	int iii = 0;
	while (1)
	{
		j = 0;
		char max2[10];
		for (int i = 0; i < k; i++)
		{
			if (numb[i].num!=0)
			{
				strcpy(max2, numb[i].a);
				j = i;
				break;
			}
		}
		for (int i = 0; i < k; i++)
		{
			if (strcmp(numb[i].a,max2)<0&&numb[i].num!=0)
			{
				strcpy(max2, numb[i].a);
				j = i;
			}
		}
		if (numb[j].num != 0)
		{
			temp3[iii] = numb[j];
			iii++;
			numb[j].num = 0;
		}
		else break;
		
	}
	while (1)
	{
		j = 0;
		int max = temp3[0].num;
		for (int i = 1; i < k; i++)
		{
			if (temp3[i].num > max)
			{
				max = temp3[i].num;
				j = i;
			}
		}
		if (max > 0)
		{
			printf("%s %d\n", temp3[j].a, temp3[j].num);
			temp3[j].num = 0;
		}
		else
		{
			break;
		}

	}
}

