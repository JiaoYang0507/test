#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "menu.h"
#include "file.h"
//#include "menu.c"
#pragma warning(disable : 4996)


int main() {
	if (!getfile())
		printf("文件打开失败。");
	outputMenu();
	
	int flag = 1;
	while (flag==1) {
		if (!savefile()) {
			printf("文件保存失败，是否重试：\n1.重试\n2.取消");
			scanf("%d", flag);
		}
		else
			flag = 0;
	}
	return  0;
}

