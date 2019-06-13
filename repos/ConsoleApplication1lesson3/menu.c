#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include <string.h>
#pragma warning(disable : 4996)

int i = 0, n = 0;
Card card[100];

void savecard(Card *card, char no[], char pwd[], float balance) {

	strcpy(card->aName, no);
	strcpy(card->aPwd, pwd);
	card->fBalance = balance;
	card->nStatus = time(0);
	card->nDel = 0;
	card->nUseCount = 0;
	card->fTotalUse = 0;
	card->nUseCount = 0;
}
void setcard(Card t) {
	card[i] = t;
	n=i++;
}

Card getcard(int j) {
	return card[j];
}

void addcard() {//��ӿ�
		printf("��������Ҫ��ӵĿ���(����1-18):\n");
	char no[50];
	scanf("%s", no);
	while (strlen(no) > 18 ) {
		if (strlen(no) > 18) printf("���ų���18λ�����������뿨��(����1-18):\n");
		//else printf("�ÿ����Ѵ������������뿨��(����1-18):\n");
		scanf_s("%s", no);
	}
	char pwd[30];
	printf("����������(����1-8):\n");
	scanf("%s", pwd);
	while (strlen(pwd) > 8) {
		printf("���볬��8λ����������������(����1-8):\n");
		scanf_s("%s", pwd);
	}
	float balance;
	printf("�����뿪�����(�����):\n");
	scanf_s("%f", &balance);
	printf("��ӿ�����Ϣ����:\n");
	printf("����\t����\t״̬\t���\n");
	printf("%s\t%s\t0\t%.1f\n", no, pwd, balance);
	savecard(&(card[i]), no, pwd, balance);
	n = i;
	i++;
	int a;
	printf("1.�������\n");
	printf("2.�����ϼ��˵�\n");
	printf("0.�˳�\n");
	scanf("%d", &a);
	switch (a) {
	case 0: {
		exit(0); break;
	}
	case 1: {
		addcard(); break;
	}
	case 2: {
		 break;
	}
	}

}

Card find(char no[]) {
	for (int j = 1; j <= n; j++) {
		if (strcmp(card[j].aName, no) == 0)
			return card[j];
		else
			return card[0];
	}
}

void findcard() {//��ѯ��
	char num[18];
	printf("��������Ҫ��ѯ�Ŀ���(����1-18):\n");
	scanf("%s", num);
	while (strlen(num) > 18) {
		if (strlen(num) > 18) printf("���ų���18λ�����������뿨��(����1-18):\n");
		//else printf("�ÿ����Ѵ������������뿨��(����1-18):\n");
		scanf_s("%s", num);
	}
	Card c;
	c = find(num);
	if (strcmp(c.aName, card[0].aName) !=0 ) {
		
		printf("������Ϣ����:\n");
		printf("����\t����\t״̬\t���\n");
		printf("%s\t%s\t%d\t%.1f\n", c.aName, c.aPwd, c.nDel, c.fBalance);
	}
	else
		printf("δ�ҵ��ÿ��š�");
}


void turnon() {//�ϻ�
	printf("turnon");
}

void turnoff() {//�»�
	printf("turnoff");
}

void addmoney() {//��ֵ
	printf("addmoney");
}

void refoundmoney() {//�˷�
	printf("refoundmoney");
}

void searchcard() {//��ѯͳ��
	printf("searchcard");
}

void deletecard() {//ע����
	printf("deletecard");
}

void outputMenu() {//��ʾ�˵�
	int a = -1, flag = 1;
	while (flag) {
		printf("Welcome to Internet bar billing system\n");
		printf("1.��ӿ�\n");
		printf("2.��ѯ��\n");
		printf("3.�ϻ�\n");
		printf("4.�»�\n");
		printf("5.��ֵ\n");
		printf("6.�˷�\n");
		printf("7.��ѯͳ��\n");
		printf("8.ע����\n");
		printf("0.�˳�ϵͳ\n");
		printf("������������������������������������\n");
		printf("����������Ҫ�Ĳ�����\n");
		scanf_s("%d", &a);
		if (a < 0 || a>8)
		{
			printf("�������\n");
			continue;
		}
		switch (a)
		{
		case 1:addcard();		break;
		case 2:findcard();		break;
		case 3:turnon();		break;
		case 4:turnoff();		break;
		case 5:addmoney();		break;
		case 6:refoundmoney();	break;
		case 7:searchcard();	break;
		case 8:deletecard();	break;
		case 0: { printf("��л��ʹ�ñ�ϵͳ��"); flag = 0;		break; }
		}
	}
}
