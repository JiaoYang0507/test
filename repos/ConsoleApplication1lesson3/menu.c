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

void addcard() {//添加卡
		printf("请输入需要添加的卡号(长度1-18):\n");
	char no[50];
	scanf("%s", no);
	while (strlen(no) > 18 ) {
		if (strlen(no) > 18) printf("卡号超过18位，请重新输入卡号(长度1-18):\n");
		//else printf("该卡号已存在请重新输入卡号(长度1-18):\n");
		scanf_s("%s", no);
	}
	char pwd[30];
	printf("请输入密码(长度1-8):\n");
	scanf("%s", pwd);
	while (strlen(pwd) > 8) {
		printf("密码超过8位，请重新输入密码(长度1-8):\n");
		scanf_s("%s", pwd);
	}
	float balance;
	printf("请输入开卡金额(人民币):\n");
	scanf_s("%f", &balance);
	printf("添加卡的信息如下:\n");
	printf("卡号\t密码\t状态\t金额\n");
	printf("%s\t%s\t0\t%.1f\n", no, pwd, balance);
	savecard(&(card[i]), no, pwd, balance);
	n = i;
	i++;
	int a;
	printf("1.继续添加\n");
	printf("2.返回上级菜单\n");
	printf("0.退出\n");
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

void findcard() {//查询卡
	char num[18];
	printf("请输入需要查询的卡号(长度1-18):\n");
	scanf("%s", num);
	while (strlen(num) > 18) {
		if (strlen(num) > 18) printf("卡号超过18位，请重新输入卡号(长度1-18):\n");
		//else printf("该卡号已存在请重新输入卡号(长度1-18):\n");
		scanf_s("%s", num);
	}
	Card c;
	c = find(num);
	if (strcmp(c.aName, card[0].aName) !=0 ) {
		
		printf("卡的信息如下:\n");
		printf("卡号\t密码\t状态\t金额\n");
		printf("%s\t%s\t%d\t%.1f\n", c.aName, c.aPwd, c.nDel, c.fBalance);
	}
	else
		printf("未找到该卡号。");
}


void turnon() {//上机
	printf("turnon");
}

void turnoff() {//下机
	printf("turnoff");
}

void addmoney() {//充值
	printf("addmoney");
}

void refoundmoney() {//退费
	printf("refoundmoney");
}

void searchcard() {//查询统计
	printf("searchcard");
}

void deletecard() {//注销卡
	printf("deletecard");
}

void outputMenu() {//显示菜单
	int a = -1, flag = 1;
	while (flag) {
		printf("Welcome to Internet bar billing system\n");
		printf("1.添加卡\n");
		printf("2.查询卡\n");
		printf("3.上机\n");
		printf("4.下机\n");
		printf("5.充值\n");
		printf("6.退费\n");
		printf("7.查询统计\n");
		printf("8.注销卡\n");
		printf("0.退出系统\n");
		printf("——————————————————\n");
		printf("请输入您需要的操作：\n");
		scanf_s("%d", &a);
		if (a < 0 || a>8)
		{
			printf("输入错误\n");
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
		case 0: { printf("感谢您使用本系统！"); flag = 0;		break; }
		}
	}
}
