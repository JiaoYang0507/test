#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "menu.h"
#include "file.h"
//#include "menu.c"
#pragma warning(disable : 4996)


int main() {
	if (!getfile())
		printf("�ļ���ʧ�ܡ�");
	outputMenu();
	
	int flag = 1;
	while (flag==1) {
		if (!savefile()) {
			printf("�ļ�����ʧ�ܣ��Ƿ����ԣ�\n1.����\n2.ȡ��");
			scanf("%d", flag);
		}
		else
			flag = 0;
	}
	return  0;
}

