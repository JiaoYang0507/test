#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996)
#include <string.h>
#include "card.h"
#include "menu.h"

void addcard() {
//	Card *card = initial();
	printf("----------添加卡----------\n");
	printf("请输入卡号<长度为1-18>:");
	char name[10];
	scanf("%s", name);
	char password[10];
	printf("\n请输入密码<长度为1-8>:");
	scanf("%s",password);
	float left;
	printf("\n请输入开卡金额（RMB):");
	scanf("%f", &left);
	addCard(name, password, left);
	
	}

void findcard() {
	
	printf("请输入查询的卡号<长度为1-18>:");
	char name[10];
	scanf("%s", name);
	Card *t = find( name);
	if (t == NULL) {
		printf("卡号错误。");
		return ;
	}
	printf("查询卡信息如下:\n");
	printf("卡号\t密码\t状态\t金额\n");
	printf("%s\t%s\t%d\t%.2f\n", t->Name, t->Pwd, t->nStatus, t->fBalance);

	
}


char* TimeTransfer(time_t t)//将时间转换成字符，T为时间，pBuf为转换后的字符
{//yinggaishi char *
	char pBuf[20] = { 0 };
	struct tm * timeinfo;
	timeinfo = localtime(&t);
	strftime(pBuf, 20, "%Y-%m-%d %H:%M", timeinfo);
	//printf("%s", pBuf);
	return pBuf;
}

time_t StringToTime(char* _time)//将字符转换成时间
{
	struct tm ptime;
	memset(&ptime, 0, sizeof(ptime));
	sscanf(_time, "%4d-%2d-%2d %2d:%2d", &ptime.tm_year, &ptime.tm_mon, &ptime.tm_mday, &ptime.tm_hour, &ptime.tm_min);
	ptime.tm_sec = 0;
	ptime.tm_mon -= 1;
	ptime.tm_year -= 1900;
	time_t time = mktime(&ptime);
	return time;
}


void turnon() {
	printf("turnon");
}

void turnoff() {
	printf("turnoff");
}

void addmoney() {
	printf("addmoney");
}

void refoundmoney() {
	printf("refoundmoney");
}

void searchcard() {
	printf("searchcard");
}

void deletecard() {
	printf("deletecard");
}