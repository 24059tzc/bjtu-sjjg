#include<stdio.h>
#include<stdlib.h>
#define defaultsize 10
#define increasesize 5
typedef struct {
	char* base;
	char* top;
	int stacksize;//栈的存储容量 
}OPRTstack;
typedef struct {
	int* base;
	int* top;
	int stacksize;
}NUMstack;
int createStack(OPRTstack* s)
{
	s->base = (char*)malloc(sizeof(char) * defaultsize);
	if (!s->base)return 0;
	s->top = s->base;
	s->stacksize = 10;
	return 1;
}
int pop(OPRTstack* s, char* e)
{
	if (s->top == s->base)return 0;
	s->top--;
	*e = *(s->top);
	return 1;
}
int push(OPRTstack* s, char e)
{
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (char*)realloc(s->base, sizeof(char) * (s->stacksize + increasesize));
		if (!s->base)return 0;
		s->top = s->base + s->stacksize;
		s->stacksize += increasesize;

	}
	*(s->top) = e;
	s->top++;
}
int isEmpty(OPRTstack* s)
{
	if (s->top == s->base)return 1;
	else return 0;
}
char GetTop(OPRTstack* s)
{
	if (!isEmpty(s))
	{
		char* temp = s->top;
		temp--;
		return *(temp);
	}
	else return '!';//这样定义的话，栈里面不能存储！这个数据 
}

int createStack(NUMstack* s)
{
	s->base = (int*)malloc(sizeof(int) * defaultsize);
	if (!s->base)return 0;
	s->top = s->base;
	s->stacksize = 10;
	return 1;
}
int pop(NUMstack* s, int* e)
{
	if (s->top == s->base)return 0;
	s->top--;
	*e = *(s->top);
	return 1;
}
int push(NUMstack* s, int e)
{
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (int*)realloc(s->base, sizeof(int) * (s->stacksize + increasesize));
		if (!s->base)return 0;
		s->top = s->base + s->stacksize;
		s->stacksize += increasesize;

	}
	*(s->top) = e;
	s->top++;
}
int isEmpty(NUMstack* s)
{
	if (s->top == s->base)return 1;
	else return 0;
}
int GetTop(NUMstack* s)
{
	if (!isEmpty(s))
	{
		int* temp = s->top;
		temp--;
		return *(temp);
	}
	else return -1;//这样定义的话，栈里面不能存储！这个数据 
}
int isOPRT(char c)//判断c是不是运算符 
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#')return 1;
	else return 0;
}
char compare(char a, char b)
{
	if (a == '+')
	{
		if (b == '*' || b == '/' || b == '(') return '<';
		else return '>';
	}
	else if (a == '-')
	{
		if (b == '*' || b == '/' || b == '(') return '<';
		else return '>';
	}
	else if (a == '*')
	{
		if (b == '(')return '<';
		else return '>';
	}
	else if (a == '/')
	{
		if (b == '(')return '<';
		else return '>';
	}
	else if (a == '(')
	{
		if (b == ')')return '=';
		else if (b == '#') return '!';
		else return '<';
	}
	else if (a == ')')
	{
		if (b == '(')return '!';
		else return '>';

	}
	else if (a == '#')
	{
		if (b == ')')return '!';
		if (b == '#')return '=';
		else return '<';
	}
}
int calculate(int left, int right, char operators)
{
	switch (operators)
	{
	case '+':
		return left + right;

	case '-':
		return 1 * left - right;

	case '*':
		return left * right;

	case '/':
		return 1 * left / right;
	}
}


int main()
{
	OPRTstack oprt;//运算符栈 
	NUMstack  num;//运算数字栈 
	NUMstack temp;//缓冲区，用于构建完整的运算数字 
	int build = 0;//由若干数位构成的数字 
	int index;//某个数位上的数字 
	int complex = 1;//10的幂次 
	char operators;//基本表达式中的四则运算符 
	int left, right;//基本表达式中左右运算数字 
	createStack(&num);
	createStack(&oprt);
	createStack(&temp);
	
	push(&oprt, '#');
	char c = getchar();
	int error = 0;//syntax error 标识符 
	while (c != '#' || GetTop(&oprt) != '#')
	{
		while (!isOPRT(c))//读入的是数字 
		{
			push(&temp, c - '0');
			c = getchar();
		}
		while (!isEmpty(&temp))//将读取到的数字字符存入缓冲区，构建完整的运算数字 
		{
			pop(&temp, &index);
			build += (index * complex);
			complex *= 10;

		}
		complex = 1;
		if (build)push(&num, int(build));//将此运算数字压入栈num 
		build = 0;

		if (isOPRT(c))//读入的是运算符 
		{
			switch (compare(GetTop(&oprt), c)) {
			case '<':
				push(&oprt, c);
				c = getchar();
			
				break;

			case '=':
				pop(&oprt, &operators);
				c = getchar();
			
				break;

			case '>':
				pop(&oprt, &operators);
				pop(&num, &right);
				pop(&num, &left);
				push(&num, calculate(left, right, operators));//从num栈弹出两个运算数字，利用运算符栈顶元素进行计算 
				
				break;

			case '!':
				
				error = 1;
				break;
			}



		}
		if (error)break;
	}
	if (!error)printf("结果是: %d\n", GetTop(&num));
	return 0;
}