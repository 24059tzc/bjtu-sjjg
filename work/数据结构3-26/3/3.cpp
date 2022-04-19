#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define STACKINCREMENT 100

typedef char SElemType;
typedef int Status;

typedef struct {
    char* base;
    char* top;
    int stacksize;
}OPRTStack;
typedef struct {
    int* base;
    int* top;
    int stacksize;
}NUMStack;
Status InitStack(OPRTStack &S) {
    S.base = (char*)malloc(MAXSIZE * sizeof(char));
    if (!S.base) exit(ERROR);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//判断栈是否为空
Status StackEmpty(OPRTStack &S) {
    return (S.top == S.base);
}

//入栈
Status Push(OPRTStack &S, char e) {
    if (S.top - S.base >= S.stacksize) {      //栈满,追加存储空间
        S.base = (char*)realloc(S.base, (S.stacksize +
            STACKINCREMENT) * sizeof(char));
        if (!S.base) return ERROR;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *(S.top)=e;
    S.top++;
    return OK;
}

Status Pop(OPRTStack &S, char &e) {
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
char GetTop(OPRTStack S)
{
    char e;
    if (S.top == S.base) return ERROR;
    e = *(S.top-1);
    return e;
}
Status InitStack(NUMStack &S) {
    S.base = (int*)malloc(MAXSIZE * sizeof(int));
    if (!S.base) return ERROR;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//判断栈是否为空
Status StackEmpty(NUMStack& S) {
    return (S.top == S.base);
}

//入栈
Status Push(NUMStack& S, int e) {
    if (S.top - S.base >= S.stacksize) {      //栈满,追加存储空间
        S.base = (int*)realloc(S.base, (S.stacksize +
            STACKINCREMENT) * sizeof(int));
        if (!S.base) return ERROR;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *(S.top) = e;
    S.top++;
    return OK;
}

Status Pop(NUMStack& S, int& e) {
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
char GetTop(NUMStack S)
{
    int e;
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return e;
}
unsigned char prior[7][7] = {
{'>','>','<','<','<','>','>'},
{'>','>','<','<','<','>','>'},
{'>','>','>','>','<','>','>'},
{'>','>','>','>','<','>','>'},
{'<','<','<','<','<','=',' '},
{'<','<','<','<','<',' ','>'},
{'<','<','<','<','<',' ','='} };

char OPSET[7] = { '+','-','*','/','(',')','#' };
char precede(char a, char b)//判断优先级函数 
{
    int i = 0, j = 0;
    while (OPSET[i] != a)
    {
        i++;
    }
    while (OPSET[j] != b)
    {
        j++;
    }
    return prior[i][j];
}
Status In(char c)//判断是否为运算符 
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#')return 1;
    else return 0;
}
Status Operate(int a, char b, int c)//运算函数 
{
    switch (b)
    {
    case '+':
        return a + c;
    case '-':
        return a - c;
    case '*':
        return a * c;
    case '/':
        return a / c;
    }

    return OK;
}
int main()
{
    OPRTStack OPRT;
    NUMStack NUM;
    char operators;
    int a, b;
    InitStack(OPRT);
    InitStack(NUM);
    Push(OPRT, '#');
    char c = getchar();
	while (c!='#'||GetTop(OPRT)!='#')
	{
        if (!In(c))
        {
            Push(NUM, c - '0');
            c = getchar();
        }
        else 
        {
            switch (precede(GetTop(OPRT),c))
            {
            case '<':
                Push(OPRT, c);
                c = getchar();
                break;
            case '=':
                Pop(OPRT, operators);
                c = getchar();
                break;
            case '>':
                Pop(OPRT, operators);
                Pop(NUM, a);
                Pop(NUM, b);
                Push(NUM,Operate(b, operators, a));
                break;
            default:
                break;
            }
        }
        
	}
    printf("结果是: %d\n", GetTop(NUM));
	return 0;
}
 