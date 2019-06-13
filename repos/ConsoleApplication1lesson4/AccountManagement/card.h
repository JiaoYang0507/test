#pragma once



typedef struct Card
{
	char Name[18];
	char Pwd[8];
	int nStatus;//卡状态(0-未上机；1-正在上机；2-已注销；3-失效)
	time_t tStart;
	time_t tEnd;
	float fTotalUse;
	time_t tLast;
	float nUseCount;
	float fBalance;
	int nDel;//0-未删除 1-已删除
	struct Card* next;//指向下张卡
}Card;

Card *head, *p, *q;
void addCard(char name[], char password[], float left);
Card* find( char name[]);
void initial();