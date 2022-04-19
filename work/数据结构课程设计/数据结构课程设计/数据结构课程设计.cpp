#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>  

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE -1
#define MAXNUM 100 /* 最大顶点数，应由用户定义 */
#define MAXTABLESIZE 10000 //允许开辟的最大散列表长度
#define Remainder 11
typedef int ElementType;
typedef int Status;
typedef struct HashEntry
{
    ElementType data; //存放的元素

}Cell, * pCell;
typedef struct TblNode
{
    int tablesize; //表的最大长度
    pCell cells;   //存放散列单元数据的数组
}hash,*HashTable;
/*确定key值*/
int Key(ElementType key)
{
    return key;
}
/*创建新的哈希表*/
HashTable CreateTable()
{
    HashTable H;
    return H;
}
/*显示已经创建的哈希表*/
void ShowTable(HashTable h)
{

}

int Hash(ElementType key, int n)
{
    return key % Remainder; //假设为11
}
/*查找元素位置*/
int Find(HashTable h, ElementType key)
{
    int address;
    return address;
}
/*插入新的元素*/
Status Insert(HashTable* h)
{
    return OK;
}
/*删除元素*/
Status DeleteTable(HashTable *h)
{
    return OK;
}
/*显示元素的全部信息*/
Status Printf(Cell e)
{
    printf("%d", e.data);
    return OK;
}
/*菜单显示*/
void menu()
{
    printf("1.创建哈希表\n");
    printf("2.显示哈希表\n");
    printf("3.查找元素\n");
    printf("4.插入元素\n");
    printf("5.删除元素\n");
    printf("6.退出系统\n");
    printf("请输入功能对应数字:");
}
int main()
{
    HashTable H;
    int c,find,temp,order=0;
    while (1)
    {
        menu();
        scanf("%d", &c);
        system("cls");
        switch (c)
        {
        case 1:H=CreateTable(); break;
        case 2:ShowTable(H); break;
        case 3:printf("请输入要查找的元素："); 
            scanf("%d", &find);
            system("cls");
            temp=Find(H, Key(find));
            if (temp != FALSE)
                Printf(H->cells[temp]);
            else printf("查找失败");
            break;
        case 4:temp=Insert(&H); 
            if (temp == OK)printf("插入成功,请进行下一步操作\n");
            else printf("插入失败\n");
            break;
        case 5:temp=DeleteTable(&H); 
            if (temp == OK)printf("删除成功,请进行下一步操作\n");
            else printf("删除失败\n");
            break; break;
        case 6:return 0;
        default:printf("输入错误，退回主菜单\n");
            break;
        }
    }
}
