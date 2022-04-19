#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>  

#define _CRT_SECURE_NO_WARNINGS 1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE -1
#define MAXNUM 100 /* 最大顶点数，应由用户定义 */
#define MAXTABLESIZE 100//允许开辟的最大散列表长度
#define Remainder 99
#define ENDNOTE -1//输入-1时停止读取数据

typedef int ElementType;
typedef int Status;
typedef struct HashNode
{
    int HashAddress;//哈希地址
    ElementType key;//关键字
    //用户可添加其余信息

}HashNode, * HNode;
typedef struct TblNode
{
    int tablesize; //表的最大长度
    HNode cells;   //存放散列单元数据的数组
}In_Hash, * HashTable;

/*确定key值*/
/*int Key(ElementType key)
{
    return key;
}

/*哈希函数*/
int Hash(ElementType key)
{
    return key % Remainder;
}

/*解决冲突函数*/
int ConflictSolve(HashNode h, HashTable H)
{
    int i = h.HashAddress;
    while (H->cells[i].key != 0 && i <= MAXTABLESIZE)
    {
        i++;
    }
    if (i > MAXTABLESIZE) {//如果之后无空位置，则从表头开始查找
        i = 0;
        while (H->cells[i].key != 0 && i < h.HashAddress) i++;
        if (i == h.HashAddress) i = -1;//表满，返回-1
    }
    return i;
}
/*创建新的哈希表*/
HashTable CreateTable()
{
    HashTable H;
    H = (HashTable)malloc(sizeof(In_Hash));
    HashNode h;
    H->cells = (HNode)malloc(sizeof(HashNode) * MAXTABLESIZE);
    H->tablesize = 0;
    for (int i = 0; i < MAXTABLESIZE; i++) H->cells[i].key = 0;
    printf("请输入关键字：");
    scanf("%d", &h.key);//读取关键字的值
    while (h.key != ENDNOTE) {
        h.HashAddress = Hash(h.key);//确定哈希地址
        if (H->cells[h.HashAddress].key == 0)
        {//未发生冲突，直接写入
            H->cells[h.HashAddress] = h;
            H->tablesize++;
        }
        else
        {
            h.HashAddress = ConflictSolve(h, H);//发生冲突，执行解决冲突函数
            if (h.HashAddress == -1) printf("表已满！\n");
            else
            {
                H->cells[h.HashAddress] = h;
                H->tablesize++;
            }
        }
        scanf("%d", &h.key);
    }
    printf("创建成功！\n");
    return H;
}

/*显示已经创建的哈希表*/
void ShowTable(HashTable h)
{
    int i;
    printf("哈希地址");
    printf(" 关键字\n");
    for (i = 0; i < MAXTABLESIZE; i++)
    {
        if (h->cells[i].key != 0) {
            printf("%4d", h->cells[i].HashAddress);
            printf("%8d\n", h->cells[i].key);
        }
    }
}

int ConflictSolve(int h, HashTable H,int key)
{
    int i = h;
    while (H->cells[i].key != key && i <= MAXTABLESIZE)
    {
        i++;
    }
    if (i > MAXTABLESIZE) {//如果之后无空位置，则从表头开始查找
        i = 0;
        while (H->cells[i].key != key && i < h) i++;
        if (i ==h) 
            i = -1;//表满，返回-1
    }
    return i;
}
/*查找元素位置*/
int Find(HashTable h, ElementType key)
{
    int address=Hash(key);
    if (h->cells[address].key != key)address=ConflictSolve(address, h, key);
    return address;
}
Status Printf(HashNode e)
{
    printf("%4d", e.HashAddress);
    printf("%8d\n", e.key);
    return OK;
}
/*插入新的元素*/
Status Insert(HashTable* H)
{
    ElementType new_key;
    printf("请输入要插入的元素：\n");
    scanf("%d", &new_key);
    int addr = Hash(new_key); /* 求散列地址 */
    HashNode h;
    h.HashAddress = addr;
    h.key = new_key;
    if ((*H)->cells[addr].key != 0)//若冲突，则排除冲突后插入
    {
        h.HashAddress = ConflictSolve(h, *H);
        if (h.HashAddress == -1) printf("表已满！\n");
        else
        {
            (*H)->cells[h.HashAddress] = h;
            (*H)->tablesize++;
        }
        return 1;
    }
    else//不冲突，直接插入
    {
        (*H)->cells[addr] = h;
        return 1;
    }
}

/*删除元素*/
Status DeleteTable(HashTable* h)
{
    ElementType new_key;
    printf("请输入要删除的元素：\n");
    scanf("%d", &new_key);
    int address = Find(*h,new_key);
    if (address == -1)printf("没有此元素\n");
    else (*h)->cells[address].key = 0;
    return OK;
}

/*显示元素的全部信息*/
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
    HashTable H = NULL;
    int c, find, temp, order = 0;
    while (1)
    {
        menu();
        scanf("%d", &c);
        system("cls");
        switch (c)
        {
        case 1:H = CreateTable(); break;
        case 2:ShowTable(H); break;
        case 3:printf("请输入要查找的元素：");
            scanf("%d", &find);
            system("cls");
            temp = Find(H, find);
            if (temp != FALSE)
                Printf(H->cells[temp]);
            else printf("查找失败\n");
            break;
        case 4:temp = Insert(&H);
            if (temp == OK)printf("插入成功,请进行下一步操作\n");
            else printf("插入失败\n");
            break;
        case 5:temp = DeleteTable(&H);
            if (temp == OK)printf("删除成功,请进行下一步操作\n");
            else printf("删除失败\n");
            break; break;
        case 6:return 0;
        default:printf("输入错误，退回主菜单\n");
            break;
        }
    }
}
