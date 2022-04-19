#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char aa[11][10000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", aa[i]);
	}
	for (int i = 0; i < n; i++)
	{
		int ll = strlen(aa[i]);
		int j;
		char cc[10000];
		cc[ll] = '\0';
		for (int mm = 0; mm < ll; mm++)
		{
			if (aa[i][mm] == '(')
				cc[ll-1-mm] = ')';
			else cc[ll-1-mm] = '(';
		}
		for (j = 0; j < ll; )
		{
			if(aa[i][j]==cc[j])
			{
				j++;
			}
			else
			{
				break;
			}
		}
		if (j == ll)
		{
			printf("SYMMETRY!!!\n");
		}
		else
		{
			char bb[10000];
			for (int k = 0; k < ll; k++)
			{
				bb[ll] = '\0';
				bb[ll-1-k] = aa[i][k];
			}
			if (strcmp(bb,aa[i])==0)
			{
				printf("PALINDROME!!!\n");
			}
			else
			{
				printf("UGLY!!!\n");
			}
		}
	}
}