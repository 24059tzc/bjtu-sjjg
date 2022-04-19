#include <stdio.h>
#include <stdlib.h>
#define List_init_size 1000
typedef int Element;
typedef int Status;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct
{
    Element* elem;
    int length;
    int listsize;
}Sqlist;

//初始化顺序表
Status Initlist(Sqlist& L)
{
    L.elem = (Element*)malloc(List_init_size * sizeof(Element));
    if (!L.elem) return ERROR;
    L.length = 0;
    L.listsize = List_init_size;
    return OK;
}

//创建一个长度为m的顺序表
void Createlist(Sqlist& L, int m)//输入函数
{
    int i;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &L.elem[i]);
    }
    L.length = m;
}

//将元素e插入到第k个元素之前
Status Listinsert(Sqlist& L, int k, int e)
{
    if (k<1 || k>L.length + 1) return ERROR;//判断插入位置的合法性
    int j;
    int pos = k;

    for (j = L.length - 1; j >= pos - 1; j--)
    {//从最后一个位置开始移位，将需要插入的位置空出
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[pos - 1] = e;
    L.length++;  //每插入一个元素，顺序表长度加一
    return OK;

}

//判断在顺序表中是否存在某元素（存在返回值TRUE；不存在返回值FALSE）
Status isPresent(Sqlist L, int e) {

    //★★★请补全代码
    if (L.length == 0)return FALSE;
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)return TRUE;
    }
    return FALSE;
}

//打印顺序表的元素
void Display(Sqlist L)
{
    //★★★请补全代码
    if (L.length == 0)printf("顺序表为空\n");
    else
    {
        for (int i = 0; i < L.length; i++)
        {
            printf("%d ", L.elem[i]);
        }
        printf("\n");
    }
}

//取顺序表的第i个元素
Status GetElem(Sqlist L, int i, Element& e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

//求L1与L2的交集，放入L3
void InterSection(Sqlist L1, Sqlist L2, Sqlist& L3)
{
    //★★★请补全代码
    int temp1, temp2, i = 1, j = 1, k = 1;
    while (i <= L1.length && j <= L2.length)
    {
        temp1 = L1.elem[i - 1];
        temp2 = L2.elem[j - 1];
        if (temp1 < temp2)i++;
        else if (temp1 > temp2)j++;
        else
        {
            Listinsert(L3, k, temp1);
            i++;
            j++;
            k++;
        }
    }

}


int main()
{
    int m, n;
    Sqlist A, B, C;
    printf("请依次输入表A和表B中的元素个数\n");
    scanf("%d%d", &m, &n);
    Initlist(A);
    Initlist(B);
    Initlist(C);
    printf("请依次输入表A中的元素\n");
    Createlist(A, m);
    printf("请依次输入表B中的元素\n");
    Createlist(B, n);
    InterSection(A, B, C);
    printf("表A和表B的交集为\n");
    Display(C);
    return 0;
}
