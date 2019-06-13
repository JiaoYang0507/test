// 四则运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//【问题描述】设计一个模拟计算器功能的程序，它读入一个表达式，如果是一个正确的表达式（即它由操作数、圆括号和+、-、*、/四种运算符组成），则求出该表达式的值；否则给出某种错误信息。
//【提示】读入一个以字符序列形式给出的以等号（ = ）结尾的表达式；程序中应考虑运算符的优先级、运算的合法性。


#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cmath>
#define size 100

using namespace std;


/* 运算数栈*/
typedef struct SqStack_int
{
	int *base; /* 在栈构造之前和销毁之后，base的值为NULL */
	int  *top; /* 栈顶指针 */
	int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack_int;
/* 运算符栈 */
typedef struct SqStack_char
{
	char *base; /* 在栈构造之前和销毁之后，base的值为NULL */
	char *top; /* 栈顶指针 */
	int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack_char;

#define Status int
/*运算数栈操作*/
Status InitStack(SqStack_int *S)
{ /* 构造一个空栈S */
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*S).base)
		return (OVERFLOW); /* 存储分配失败 */
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}
Status GetTop(SqStack_int S, SElemType *e)
{ /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
	if (S.top > S.base)
	{
		*e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}

Status Push(SqStack_int *S, SElemType e)
{ /* 插入元素e为新的栈顶元素 */
	if ((*S).top - (*S).base >= (*S).stacksize) /* 栈满，追加存储空间 */
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(*S).base)
			return (OVERFLOW); /* 存储分配失败 */
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return OK;
}
Status Pop(SqStack_int *S, SElemType *e)
{ /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *--(*S).top;
	return OK;
}

/*运算符栈操作*/
Status InitStack(SqStack_char *S)
{ /* 构造一个空栈S */
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*S).base)
		return (OVERFLOW); /* 存储分配失败 */
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}
Status GetTop(SqStack_char S, SElemType *e)
{ /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
	if (S.top > S.base)
	{
		*e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}

Status Push(SqStack_char *S, SElemType e)
{ /* 插入元素e为新的栈顶元素 */
	if ((*S).top - (*S).base >= (*S).stacksize) /* 栈满，追加存储空间 */
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(*S).base)
			return (OVERFLOW); /* 存储分配失败 */
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return OK;
}

Status Pop(SqStack_char *S, SElemType *e)
{ /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *--(*S).top;
	return OK;
}


#include <stdio.h>
#include "Charstack.h"
#include "IntStack.h"

int In(char c)      //判断是否为运算符
{
	char s[] = "+-*\\()#";
	for (int i = 0; i < 8; i++)
	{
		if (c == s[i])
			return 1;
	}
	return 0;
}

char Precede(char c1, char c2)//c1 theta1,c2 theta 2
{/*Precede判断运算符栈的栈顶运算符theta1与读入的运算符theta2之间的优先关系*/
	char a[7][7] = { { '>','>','<','<','<','>','>' },
	{ '>','>','<','<','<','>','>' },
	{ '>','>','>','>','<','>','>' },
	{ '>','>','>','>','<','>','>' },
	{ '<','<','<','<','<','=',' ' },
	{ '>','>','>','>',' ','>','>' },
	{ '<','<','<','<','<',' ','=' } };/*存储算符优先关系表*/
	int i, j;
	switch (c1)
	{
	case '+':i = 0; break;
	case '-':i = 1; break;
	case '*':i = 2; break;
	case '/':i = 3; break;
	case '(':i = 4; break;
	case ')':i = 5; break;
	case '#':i = 6; break;
	}
	switch (c2)
	{
	case '+':j = 0; break;
	case '-':j = 1; break;
	case '*':j = 2; break;
	case '/':j = 3; break;
	case '(':j = 4; break;
	case ')':j = 5; break;
	case '#':j = 6; break;
	}
	return a[i][j];
}

void Oprate(int a, char theta, int b, int &c)
{/*opare为进行二元运算a theta b的函数*/
	switch (theta)
	{
	case '+':c = a + b; break;
	case '-':c = a - b; break;
	case '*':c = a * b; break;
	case '/':c = a / b; break;
	}
}

int main()
{
	SqStack_char OPTR;//运算符栈
	SqStack_int OPND;//运算数栈
	printf("请输入算数表达式并以#结尾\n");
	printf("算数表达式：");
	InitStack(&OPTR);
	Push(&OPTR, '#');
	InitStack(&OPND);
	char c = getchar();
	char m, n, e;
	char theta;
	while (c != '#' || e != '#')
	{
		printf("输入字符,%c     ", c);
		//不是运算符则进栈
		if (!In(c))
		{
			Push(&OPND, c - '0');
			printf("主要操作：Push(OPND,‘%d’)\n", c - '0');
			c = getchar();
		}
		else
		{
			GetTop(OPTR, &m);
			switch (Precede(m, c))
			{
			case '<':             //栈顶元素优先权低
				Push(&OPTR, c);
				printf("主要操作：Push(OPTR,‘%c’)\n", c);
				c = getchar();
				break;
			case '=':         //脱括号并接受下一字符
				Pop(&OPTR, &n);
				printf("主要操作：PoP(OPTR){消去一对括号}\n");
				c = getchar();
				break;
			case '>':                 //退栈并将运算结果入栈
				Pop(&OPTR, &theta);
				int a, b, d;
				Pop(&OPND, &b);
				Pop(&OPND, &a);
				Oprate(a, theta, b, d);
				printf("主要操作：Oprate('%d', '%c','%d')\n", a, theta, b);
				Push(&OPND, d);
				break;
			}
		}//switch
		GetTop(OPTR, &e);
	}//while
	int x;
	GetTop(OPND, &x);
	printf("输出结果：%d\n", x);
}
