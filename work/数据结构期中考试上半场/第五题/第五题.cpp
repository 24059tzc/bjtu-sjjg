#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef int SElemType;


//定义链栈结构
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

//初始化链栈
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
}

//判断链栈是否为空，是则返回TRUE，不是则返回FALSE
Status StackEmpty(LinkStack S)
{

	if (NULL == S)
		return TRUE;
	else
		return FALSE;
}

//将元素e入栈
Status Push(LinkStack& S, SElemType e)
{
	LinkStack temp;
	temp = (LinkStack)malloc(sizeof(StackNode));
	temp->data = e;
	temp->next = S;
	S = temp;
	return OK;

}

//获取栈顶元素，赋值给e
Status GetTop(LinkStack S, SElemType& e)
{
	if (StackEmpty(S) == TRUE)
		return ERROR;
	e = S->data;
	return OK;
}

//从栈顶弹出一个元素，元素赋值给e
Status Pop(LinkStack& S, SElemType& e)
{
	LinkStack temp;
	if (StackEmpty(S) == TRUE)
		return ERROR;
	e = S->data;
	temp = S;
	S = S->next;
	free(temp);
	return OK;
}

int main()
{
	LinkStack S;
	int n = 0;   //通过整数n统计相同相邻数的个数，若相同，则每次进栈后n+1
	InitStack(S); //初始化栈

//★★★请补全代码
	char ch = getchar();
	int c,temp;
	while (1)
	{
		if (ch >= '0' && ch <= '9')
		{
			c = ch - '0';
			GetTop(S, temp);
			if (c == temp)n++;
			else
			{
				if (n == 0);
				else
				{
					for (int i = 0; i <= n; i++)
					{
						Pop(S, temp);
					}
					n = 0;
				}
			}
			Push(S, c);
		}
		else if (ch == EOF)
		{
			if (n == 0);
			else
			{
				for (int i = 0; i <= n; i++)
				{
					Pop(S, temp);
				}
				n = 0;
			}
			break;
		}
		ch = getchar();
	}
	while (!StackEmpty(S))
	{
		Pop(S, temp);
		printf("%d ", temp);
	}
	printf("\n");
}
