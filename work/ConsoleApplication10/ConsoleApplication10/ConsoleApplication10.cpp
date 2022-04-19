#include <stdio.h>
#define N 100                                    //宏定义全局变量
#include<string.h>
#include<stdlib.h>
int n;
void Write(); void Read(); void Save(); void Add();
void Sort(int); void ReWrite(); void Statistics(); void cart2();//引用多个函数
typedef struct students                         //定义结构体变量
{
    char num[10];
    char name[50];
    int chinese;
    int math;
    int english;
    int comprehensive;
    int sum;
}ADC;
ADC stu[N];                                     //定义结构体全局变量

void Write()                                    //定义写入函数
{
    char c[2];
    int i = 0;
    do
    {
        printf("请输入依次学号，姓名，语文成绩，数学成绩，英语成绩，综合成绩并用空格分隔\n");
        scanf("%s%s%d%d%d%d", stu[i].num, stu[i].name, &stu[i].chinese, &stu[i].math, &stu[i].english, &stu[i].comprehensive);
        stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english + stu[i].comprehensive;
        i++;
        printf("如继续输入请输入t,停止输入请输入f\n");
        scanf("%s", c);
        system("cls");
    } while (c[0] == 't');
    n = i;
}
void Add()
{
    char c[2];
    int i = n;
    do
    {
        printf("请输入依次学号，姓名，语文成绩，数学成绩，英语成绩，综合成绩并用空格分隔\n");
        scanf("%s%s%d%d%d%d", stu[i].num, stu[i].name, &stu[i].chinese, &stu[i].math, &stu[i].english, &stu[i].comprehensive);
        stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english + stu[i].comprehensive;
        i++;
        printf("如继续输入请输入t,停止输入请输入f\n");
        scanf("%s", c);
        system("cls");
    } while (c[0] == 't');
    n = i;
}

void Read()                                     //定义读取函数
{
    printf("  学号       姓名       语文      数学      英语      综合      总分\n");
    for (int i = 0; i < n; i++)
    {
        printf("%8s", stu[i].num);
        printf("%10s", stu[i].name);
        printf("%10d", stu[i].chinese);
        printf("%10d", stu[i].math);
        printf("%10d", stu[i].english);
        printf("%10d", stu[i].comprehensive);
        printf("%10d", stu[i].sum);
        printf("\n");
    }
}

void Save()                                     //定义保存到文件函数
{
    FILE* fp = NULL;
    fp = fopen("information.txt", "w+");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%s ", stu[i].num);
        fprintf(fp, "%s ", stu[i].name);
        fprintf(fp, "%d ", stu[i].chinese);
        fprintf(fp, "%d ", stu[i].math);
        fprintf(fp, "%d ", stu[i].english);
        fprintf(fp, "%d ", stu[i].comprehensive);
        fprintf(fp, "%d ", stu[i].sum);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void Sort(int x)                                //定义排序函数
{
    int temp, k, j;
    ADC b;
    switch (x)
    {
    case 1:
    {

        for (int i = 0; i < n; i++)
        {
            temp = stu[i].chinese;
            k = i;
            for (j = i; j < n; j++)
            {
                if (stu[j].chinese > temp)
                {
                    temp = stu[j].chinese;
                    k = j;
                }
            }
            b = stu[i];
            stu[i] = stu[k];
            stu[k] = b;

        }Read();
    }break;
    case 2: {
        for (int i = 0; i < n; i++)
        {
            temp = stu[i].math;
            k = i;
            for (j = i; j < n; j++)
            {
                if (stu[j].math > temp)
                {
                    temp = stu[j].math;
                    k = j;
                }
            }
            b = stu[i];
            stu[i] = stu[k];
            stu[k] = b;

        } Read();
    }break;
    case 3: {
        for (int i = 0; i < n; i++)
        {
            temp = stu[i].english;
            k = i;
            for (j = i; j < n; j++)
            {
                if (stu[j].english > temp)
                {
                    temp = stu[j].english;
                    k = j;
                }
            }
            b = stu[i];
            stu[i] = stu[k];
            stu[k] = b;
        }
        Read();
    }break;
    case 4: {
        for (int i = 0; i < n; i++)
        {
            temp = stu[i].comprehensive;
            k = i;
            for (j = i; j < n; j++)
            {
                if (stu[j].comprehensive > temp)
                {
                    temp = stu[j].comprehensive;
                    k = j;
                }
            }
            b = stu[i];
            stu[i] = stu[k];
            stu[k] = b;
        }
        Read();
    }break;
    case 5: {
        for (int i = 0; i < n; i++)
        {
            temp = stu[i].sum;
            k = i;
            for (j = i; j < n; j++)
            {
                if (stu[j].sum > temp)
                {
                    temp = stu[j].sum;
                    k = j;
                }
            }
            b = stu[i];
            stu[i] = stu[k];
            stu[k] = b;
        }
        Read();
    }break;
    default:
        break;
    }
}

void ReWrite()                                  //定义修改成绩函数
{
    char keyr[] = { "qwerty" };
    char key[20];
    char num1[10], name1[50];
    printf("请输入密码");
    scanf("%s", key);
    if (strcmp(keyr, key) == 0)
    {
        printf("请输入学号");
        scanf("%s", num1);////////////////////////////////////////////////////////此处修改过
        for (int k = 0; k <= N; k++)
        {
            if (strcmp(num1, stu[k].num) == 0)
            {
                printf("请输入修改后成绩（请输入四门成绩）");
                scanf("%d%d%d%d", &stu[k].chinese, &stu[k].math, &stu[k].english, &stu[k].comprehensive);
                stu[k].sum = stu[k].chinese + stu[k].math + stu[k].english + stu[k].comprehensive;
                printf("\n");
                break;
            }
            if (k == N)
            {
                printf("查无此人\n");
                break;
            }
        }
    }
    else
        printf("无权访问\n");
}

void Statistics()                               //定义成绩统计函数
{
    int x, i, temp, k, count;
    int Csum = 0, Msum = 0, Esum = 0, COsum = 0, Ssum = 0;
    double average1, average2, average3, average4, average5;
    for (i = 0; i < n; ++i)
        Csum += stu[i].chinese;
    average1 = Csum * 1.0 / n;

    for (i = 0; i < n; ++i)
        Msum += stu[i].math;
    average2 = Msum * 1.0 / n;

    for (i = 0; i < N; ++i)
        Esum += stu[i].english;
    average3 = Esum * 1.0 / n;

    for (i = 0; i < N; ++i)
        COsum += stu[i].comprehensive;
    average4 = COsum * 1.0 / n;

    for (i = 0; i < N; ++i)
        Ssum += stu[i].sum;
    average5 = Ssum * 1.0 / n;
    printf("1、显示每门课程成绩最高的学生的基本信息\n");
    printf("2、显示每门课程的平均成绩\n");
    printf("3、显示超过某门课程平均成绩的学生人数\n");
    printf("4、返回上层菜单\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
    {
        temp = stu[0].chinese;
        for (i = 0; i < n; ++i)
        {

            if (stu[i].chinese > temp)
            {
                temp = stu[i].chinese;
            }
        }
        for (i = 0; i < n; ++i)
        {
            if (stu[i].chinese == temp)
                printf("学科：语文   学号：%s   姓名：%s   分数：%d\n", stu[i].num, stu[i].name, stu[i].chinese);
        }

        temp = stu[0].math;
        for (i = 0; i < n; ++i)
        {
            if (stu[i].math > temp)
            {
                temp = stu[i].math;
            }
        }
        for (i = 0; i < n; ++i)
        {
            if (stu[i].math == temp)
                printf("学科：数学   学号：%s   姓名：%s   分数：%d\n", stu[i].num, stu[i].name, stu[i].math);
        }

        temp = stu[0].english;
        for (i = 0; i < n; ++i)
        {
            if (stu[i].english > temp)
            {
                temp = stu[i].english;
            }
        }
        for (i = 0; i < n; ++i)
        {
            if (stu[i].english == temp)
            {
                printf("学科：英语   学号：%s   姓名：%s   分数：%d\n", stu[i].num, stu[i].name, stu[i].english);
            }
        }

        temp = stu[0].comprehensive;
        for (i = 0; i < n; ++i)
        {
            if (stu[i].comprehensive > temp)
            {
                temp = stu[i].comprehensive;
            }
        }
        for (i = 0; i < n; ++i)
        {
            if (stu[i].comprehensive == temp)
            {
                printf("学科：综合   学号：%s   姓名：%s   分数：%d\n", stu[i].num, stu[i].name, stu[i].comprehensive);
            }
        }

        temp = stu[0].sum;
        for (i = 0; i < n; ++i)
        {
            if (stu[i].sum > temp)
            {
                temp = stu[i].sum;
            }
        }
        for (i = 0; i < n; ++i)
        {
            if (stu[i].sum == temp)
                printf("学科：总分   学号：%s   姓名：%s   分数：%d\n", stu[i].num, stu[i].name, stu[i].sum);
        }

    }
    Statistics();
    break;
    case 2:
    {
        printf("学科：语文   平均分数：%g\n", average1);

        printf("学科：数学   平均分数：%g\n", average2);

        printf("学科：英语   平均分数：%g\n", average3);

        printf("学科：综合   平均分数：%g\n", average4);

        printf("学科：总分   平均分数：%g\n", average5);
    }Statistics(); break;
    case 3:
    {
        count = 0;
        for (i = 0; i < n; ++i)
        {

            if (stu[i].chinese > average1)
                ++count;
        }
        printf("语文有%d人\n", count);

        count = 0;
        for (i = 0; i < n; ++i)
        {

            if (stu[i].math > average2)
                ++count;
        }
        printf("数学有%d人\n", count);

        count = 0;
        for (i = 0; i < n; ++i)
        {

            if (stu[i].english > average3)
                ++count;
        }
        printf("英语有%d人\n", count);

        count = 0;
        for (i = 0; i < n; ++i)
        {

            if (stu[i].comprehensive > average4)
                ++count;
        }
        printf("综合有%d人\n", count);

        count = 0;
        for (i = 0; i < n; ++i)
        {

            if (stu[i].sum > average5)
                ++count;
        }
        printf("总分有%d人\n", count);
    }Statistics(); break;
    default:break;
    }


}

void cart2()                                    //定义排序菜单函数
{
    int a;
    printf("请选择根据哪一学科进行排序\n1、语文\n2、数学\n3、英语\n4、综合\n5、总成绩\n6、返回上层菜单\n");
    scanf("%d", &a);
    switch (a)
    {
    case 1:Sort(1); cart2(); break;
    case 2:Sort(2); cart2(); break;
    case 3:Sort(3); cart2(); break;
    case 4:Sort(4); cart2(); break;
    case 5:Sort(5); cart2(); break;
    default:printf("呃，输错了哦！\n");
        cart2();
    }
}

void cart1()                                     //定义主菜单函数
{
    int a;
    printf("1、成绩录入\n2、成绩显示\n3、成绩保存\n4、成绩排序\n5、成绩修改（要求先输入密码）\n6、成绩统计\n7、添加成绩\n8、退出系统（请保存后再退出）\n");
    scanf("%d", &a);
    switch (a)
    {
    case 1:Write(); cart1(); break;
    case 2:Read(); cart1(); break;
    case 3:Save(); cart1(); break;
    case 4:cart2(); cart1(); break;
    case 5:ReWrite(); cart1(); break;
    case 6:Statistics(); cart1(); break;
    case 7:Add(); cart1(); break;
    default:printf("呃，输错了哦！\n");
        cart1();
        break;
    }
}

int main()                                     //主函数，展示主菜单
{
    cart1();
}

