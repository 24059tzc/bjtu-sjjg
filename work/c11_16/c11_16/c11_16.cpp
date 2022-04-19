#include <iostream>
#include<stdio.h>
int main()
{
	enum MyEnum
	{
		a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
	};
	printf("%d", a);
	struct Date
	{
		int year;
		int month;
		int day;
	};
	struct student
	{
		char num[10];
		char name[20];
		char sex;
		struct Date birthday;
		int age;
		float score[3];
		float ave;
	};
	struct clock
	{
		int hour;
		int minute;
		int second;
	};
	struct student stu1[100] ;
	stu1[0] = {};
	stu1[0].birthday.day = 12;
	stu1[0].score[1] = 25.3;
	printf("\n%d", stu1[0].birthday.day);
	union MyUnion
	{

	};
	typedef int INT32;
	INT32 a;
}