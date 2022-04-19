//测试输入：
//10 3
//1 Siyu 90 90 90
//2 Amy 60 70 94
//3 Jack 60 60 98
//4 Jack 77 90 60
//5 Banana 60 60 40
//6 White 60 60 60
//7 Pinkman 60 60 60
//8 Fring 60 60 70
//9 Ehrmantraut 80 63 61
//10 Schrader 99 66 100
//1 Jack
//2 1 100 100 100
//3 10
//测试输入数据说明：
//输入一个n，q，标书下面n行则是n个学生的信息，再下q行则是对应的操作。
//1 name //为根据名字查询操作
//2 sno num1 num2 num2 //为修改分数操作，修改学号为sno的3门成绩
//3 sno //为删除操作
//预期输出：
//3 Jack 60 60 98 218
//4 Jack 77 90 60 227
//1 Siyu 100 100 100 300
//2 Amy 60 70 94 224
//3 Jack 60 60 98 218
//4 Jack 77 90 60 227
//5 Banana 60 60 40 160
//6 White 60 60 60 180
//7 Pinkman 60 60 60 180
//8 Fring 60 60 70 190
//9 Ehrmantraut 80 63 61 204
//10 Schrader 99 66 100 265
//1 Siyu 100 100 100 300
//2 Amy 60 70 94 224
//3 Jack 60 60 98 218
//4 Jack 77 90 60 227
//5 Banana 60 60 40 160
//6 White 60 60 60 180
//7 Pinkman 60 60 60 180
//8 Fring 60 60 70 190
//9 Ehrmantraut 80 63 61 204
//预期输出数据说明：
//每次修改操作则输出全部的学生信息，查询操作则输出查询的学生的信息。
#include<stdio.h>
#include<string.h>
int Count;
struct student 
{
    char sno[20], name[20];
    int math, english, chinese, sum;
};

void print(struct student stu) 
{
    printf("%s %s %d %d %d %d\n", stu.sno, stu.name, stu.math, stu.english, stu.chinese, stu.sum);
}

void query_stu(struct student s[], char* name) 
{
    /*********Begin*********/
    int i;
    for ( i = 0; i < 50; i++)
    {
        if (strcmp(s[i].name, name) == 0)
        {
            print(s[i]);
        }
    }
    /*********End**********/
}

void delete_stu(struct student s[], char* sno) {
    /*********Begin*********/
    int j=0;
    int i;
    for (int i = 0; i < 50; i++)
    {
        if (strcmp(s[i].sno, sno) == 0)
        {
            j = i;
            break;
        }
    }
    for (i = j; i < 49; i++)
    {
        s[i] = s[i + 1];
    }

    /*********End**********/
}

void update_stu(struct student s[], char* sno, int math, int english, int chinese) {
    /*********Begin*********/
    int i;
    for (i = 0; i < 50; i++)
    {
        if (strcmp(s[i].sno,sno) == 0)
        {
            s[i].math = math;
            s[i].english = english;
            s[i].chinese = chinese;
            s[i].sum = math + english + chinese;
            break;
        }
    }

    /*********End**********/
}

int main(void)
{
    int n, q;
    struct student students[50];
    scanf("%d%d", &n, &q);
    Count = n;
    for (int i = 0; i < n; i++) 
    {
        /*********Begin*********/
        scanf("%s %s %d %d %d\n", students[i].sno, students[i].name, &students[i].math, &students[i].english,&students[i].chinese);
        students[i].sum = students[i].math + students[i].english + students[i].chinese;

        /*********End**********/
    }
    while (q--) {
        int op;
        scanf("%d", &op);
        char sno[20], name[20];
        if (op == 1) {
            scanf("%s", name);
            query_stu(students, name);
        }
        else if (op == 2) {
            int a, b, c;
            scanf("%s%d%d%d", sno, &a, &b, &c);
            update_stu(students, sno, a, b, c);
            for (int i = 0; i < Count; i++)
                print(students[i]);
        }
        else {
            scanf("%s", sno);
            delete_stu(students, sno);
            for (int i = 0; i < Count - 1; i++)
                print(students[i]);
        }
    }
    return 0;
}