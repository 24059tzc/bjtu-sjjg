#include <stdio.h>
#include <stdlib.h>				
#include <string.h>	
#define LIST_SIZE 100
typedef int Datatype;
typedef struct {
	Datatype* data;
	int length;//线性表的真实长度
	int listsize;//线性表创造的数组的长度
}seqlist;
int InitList(seqlist* L)
{
    L->data = (Datatype*)malloc(sizeof(Datatype) * LIST_SIZE);
    if (L->data == NULL)
        return -1;
    L->length = 0;
    L->listsize = LIST_SIZE;
    printf("initial finish\n");
    return 0;
}
int DestroyList(seqlist* L)
{
    while (!L->data)
        free(L->data);
    L->length = 0;
    printf("destroy finish\n");
    return 0;

}
int Listdelete(seqlist* L, int i, Datatype* e)
{

    if (i<1 || i>L->listsize)
    {
        printf("postion error:\n");
        return -1;
    }
    Datatype* q = NULL;
    Datatype* p = NULL;
    q = &L->data[i - 1];//删除元素位置
    *e = *q;
    p = &L->data[L->length - 1];//表尾位置
    while (q <= p)
    {
        *q = *(q + 1);
        q++;
    }
    L->length--;
    return 0;
}
int main()
{
    InitList(L);

}
