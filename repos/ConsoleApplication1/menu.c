#include <stdio.h>
#include <stdlib.h>


void addcard() {//��ӿ�
	printf("addcard");
}

void findcard() {//��ѯ��
	printf("findcard");
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
