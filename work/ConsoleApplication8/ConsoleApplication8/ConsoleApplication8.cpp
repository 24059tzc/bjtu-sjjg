#include <stdio.h>
int  N = 3;
void Write(); void Read(); void Save(); void cart2(); void cart(); void Add();//引用函数
struct time {
    int hour;
    char min[3];
};

typedef struct students
{
    int   fre;
    struct time statime;
    char start[30];
    char  end[30];
    float thtime;
    int load;
    int num;
}ADC;//结构体定义
ADC stu[100];//定义全局变量
void Write()
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%s%s%s%.1f%d%d", &stu[i].fre, &stu[i].statime.hour, stu[i].statime.min, stu[i].start, stu[i].end, &stu[i].thtime, &stu[i].load, &stu[i].num);

    }
}//写入函数
void Read()
{
    printf("班次  发车时间    起点站    终点站     行车时间  额定载量   已订票人数");
    for (int i = 0; i < N; i++)
    {
        printf("%d%d:%s%s%s%d%.1f%d\n", stu[i].fre, stu[i].statime.hour, stu[i].statime.min, stu[i].start, stu[i].end, stu[i].thtime, stu[i].load, stu[i].num);

    }
}//读取函数
void Save()
{

}//保存到文件中
void Add1()
{

}
void cart()
{
    int a;
    printf("1、班次录入\n2、班次显示\n3、路线查询\n4、售票\n5、退票\n6、增加班次\n");
    scanf("%d", &a);
    switch (a)
    {
    case 1:Write(); cart(); break;
    case 2:Read; cart(); break;
    case 3: cart2(); cart(); break;
    case 4:cart2(); cart(); break;
    case 5:cart(); break;
    case 6:Add1(); cart(); break;
    case 7:break;
    default:break;
    }
}//主菜单函数
void cart2()
{
    int b;
    printf("1、按班次号查询\n2、按终点站查询\n");
    scanf("%d", &b);
    switch (b)
    {
    case 1: break;
    case 2: break;
    default:
        break;
    }
}
int main()
{
    cart();

}//主函数

