#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include "serve.h"

void outputMenu() {
	int nSelection = -1, flag = 1;
	while (flag) {
		printf("��ӭ����Ʒѹ���ϵͳ\n");
		printf("----------��ӿ�----------\n");
		printf("1.��ӿ�\n");
		printf("2.��ѯ��\n");
		printf("3.�ϻ�\n");
		printf("4.�»�\n");
		printf("5.��ֵ\n");
		printf("6.�˷�\n");
		printf("7.��ѯͳ��\n");
		printf("8.ע����\n");
		printf("0.�˳�\n");
		printf("--------------------------\n");
		printf("��ѡ��˵�����(0~8)\n");
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
		case 0: { printf("��л��ʹ�ñ�ϵͳ��"); 
		          flag = 0;	    break; }
		default:printf:("�����Ŵ���");
		}
	}
}