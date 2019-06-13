#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include "serve.h"

void outputMenu() {
	int nSelection = -1, flag = 1;
	while (flag) {
		printf("欢迎进入计费管理系统\n");
		printf("----------添加卡----------\n");
		printf("1.添加卡\n");
		printf("2.查询卡\n");
		printf("3.上机\n");
		printf("4.下机\n");
		printf("5.充值\n");
		printf("6.退费\n");
		printf("7.查询统计\n");
		printf("8.注销卡\n");
		printf("0.退出\n");
		printf("--------------------------\n");
		printf("请选择菜单项编号(0~8)\n");
		scanf_s("%d", &nSelection);
		switch (nSelection)
		{
		case 1:addcard();		break;
		case 2:findcard();		break;
		case 3:turnon();		break;
		case 4:turnoff();		break;
		case 5:addmoney();		break;
		case 6:refoundmoney();	break;
		case 7:searchcard();	break;
		case 8:deletecard();	break;
		case 0: { printf("感谢您使用本系统！"); 
		          flag = 0;	    break; }
		default:printf:("输入编号错误！");
		}
	}
}