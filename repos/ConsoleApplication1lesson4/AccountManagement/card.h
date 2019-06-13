#pragma once



typedef struct Card
{
	char Name[18];
	char Pwd[8];
	int nStatus;//��״̬(0-δ�ϻ���1-�����ϻ���2-��ע����3-ʧЧ)
	time_t tStart;
	time_t tEnd;
	float fTotalUse;
	time_t tLast;
	float nUseCount;
	float fBalance;
	int nDel;//0-δɾ�� 1-��ɾ��
	struct Card* next;//ָ�����ſ�
}Card;

Card *head, *p, *q;
void addCard(char name[], char password[], float left);
Card* find( char name[]);
void initial();