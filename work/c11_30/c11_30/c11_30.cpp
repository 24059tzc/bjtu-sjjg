//#include<stdio.h>
//typedef struct
//{
//	char no[10];
//	char name[20];
//	int age;
//}DATA;
//int main(void)
//{
//	DATA stu;
//	DATA* pstu;
//	pstu = &stu;
//	stu.age = 18;
//	printf("年龄是：%d\n", stu.age);
//	pstu->age = 30;
//	printf("年龄是：%d\n", stu.age);
//}
//#include<stdio.h>
//void Sub(int x, int y, int* z)
//{
//	*z = y - x;
//}
//int main()
//{
//	int a, b, c;
//	Sub(10, 5, &a);
//	Sub(7, a, &b);
//	Sub(a, b, &c);
//	printf("%4d,%4d,%4d\n", a, b, c);
//}
#include<stdio.h>
int main()
{
    FILE* fp;
    char str;
    if ((fp = fopen("f1.txt", "w+")) == NULL)
    {
        printf("\nCan't open this file!\n"); 
        return 0;
    }
    str = getchar();
    while (str != '\n')
    {
        fputc(str, fp); str = getchar();
    }
    rewind(fp);
    str = fgetc(fp);
    while (str != EOF)
    {
        putchar(str); str = fgetc(fp);
    }
    fclose(fp);
}