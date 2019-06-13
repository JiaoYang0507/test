#include <stdio.h>
#include <stdlib.h>


void addcard() {//添加卡
	printf("addcard");
}

void findcard() {//查询卡
	printf("findcard");
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
