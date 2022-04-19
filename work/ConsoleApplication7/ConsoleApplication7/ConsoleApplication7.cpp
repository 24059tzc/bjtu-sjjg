//任务描述
//本关任务：有n个学生的信息(包括学号，姓名，成绩)，要求按照成绩的高低顺序输出学生的信息。
//5
//10101 Zhang 78
//10103 Wang 98
//10106 Li 86
//10108 Ling 73
//10110 Sun 100
//预期输出：
//10110 Sun 100
//10103 Wang 98
//10106 Li 86
//10101 Zhang 78
//10108 Ling 73
//测试输入数据说明：
//
//第一行为整数n表示有n个学生， 1 <= n <= 200。接下来包含n行数据，每行数据代表一个学生的信息，
//按学号（11位的整数），姓名（字符串，长度不超过20）和成绩（整数）。
#include<stdio.h>
int main()
{
	int i,n,temp,j,k;
	struct students
	{
		long long int num;
		char name[21];
		int score;
	}stu[200],a;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld %s %d", &stu[i].num, stu[i].name, &stu[i].score);
	}
	for (i = 0; i < n; i++)
	{
		temp = stu[i].score;
		k = i;
		for (j = i; j < n; j++)
		{
			if (stu[j].score > temp)
			{
				temp = stu[j].score;
				k = j;
			}
		}
		a = stu[i];
		stu[i] = stu[k];
		stu[k] = a;
	}
	for (i = 0; i < n; i++)
	{
		printf("%lld %s %d\n", stu[i].num, stu[i].name, stu[i].score);
	}
}