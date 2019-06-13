#define _CRT_SECURE_NO_WARNINGS//消除scanf警告
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "card.h"
#include "time.h"


//Card head=(Card)malloc(sizeof(Card));

void addCard(char name[], char password[], float left) {
	q = (Card*)malloc(sizeof(Card));
	strcpy(q->Name, name);
	strcpy(q->Pwd, password);
	q->nStatus = 0;
	q->tStart = time(0); 
	q->tEnd = time(0) + 60 * 60 * 24 * 365;
	q->fTotalUse = 0;
	q->fBalance = left;
	q->tLast = time(0);
	q->nUseCount = 0;
	q->nDel = 0;
	q->next = NULL;
	p->next = q;
	p = p->next;
	printf("\n------添加卡信息如下------\n");
	printf("卡号:%s\n", q->Name);
	printf("密码:%s\n", q->Pwd);
	//card[i].nStatus = 0;
	//printf("状态:%d\n", card[i].nStatus);
	printf("开卡金额:%.2f\n", q->fBalance);
}
void setcard(Card d) {
	q = (Card*)malloc(sizeof(Card));
	strcpy(q->Name, d.Name);
	strcpy(q->Pwd, d.Pwd);
	q->nStatus = d.nStatus;
	q->tStart = d.tStart;
	q->tEnd = d.tEnd;
	q->fTotalUse = d.fTotalUse;
	q->fBalance = d.fBalance;
	q->tLast = d.tLast;
	q->nUseCount = d.nUseCount;
	q->nDel = d.nDel;
	q->next = NULL;
	p->next = q;
	p = p->next;

}
void initial() {
	head = (Card*)malloc(sizeof(Card));
	p = head;
	head->next = NULL;
	
}
Card* find( char name[]) {
	Card *t;
	for (t=head->next; t != NULL; t = t->next) {
		//printf("%s", t->Name);
		if (strcmp(t->Name, name) == 0) {
			//printf("%d", strcmp(t->Name, name));
			return t;

		}
		
	}
	return NULL;
}