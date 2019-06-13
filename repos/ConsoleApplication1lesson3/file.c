#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include <string.h>
#pragma warning(disable : 4996)
void setcard(Card t);
Card getcard(int j);

int getfile() {
	FILE *file;
	file = fopen("C:\\Users\\焦阳\\source\\repos\\ConsoleApplication1lesson3\\card.txt", "a");  //如果文件不存在则创建一个文件
	fclose(file);
	char time_start[50], time_end[50], time_last[50];
	//time_t t_start, t_end, t_last;
	if ((file = fopen("C:\\Users\\焦阳\\source\\repos\\ConsoleApplication1lesson3\\card.txt", "r")) != NULL) {
		while (!feof(file)) {
			Card *t;
			t = (Card*)malloc(sizeof(Card));
			if (fscanf(file, "%s %s %d %s %s %f %s %d %f %d",
				t->aName, t->aPwd, &t->nStatus, time_start, time_end,
				&t->fTotalUse, time_last, &t->nUseCount, &t->fBalance, &t->nDel) == EOF)
				setcard(*t);
		}
		fclose(file);
		return 1;
	}
	else
	{
		fclose(file);
		return 0;
	}
}

int savefile() {
	FILE *file;
	
	char time_start[50], time_end[50], time_last[50];
	int i = 1;
	Card a;
	Card *t;
	t = &a;
	a = getcard(i);
	if ((file = fopen("C:\\Users\\焦阳\\source\\repos\\ConsoleApplication1lesson3\\card.txt", "a")) != NULL) {
		while (t->aName!=NULL) 
			if (fprintf(file, "%s %s %d %s %s %f %s %d %f %d",
				t->aName, t->aPwd, &t->nStatus, time_start, time_end,
				&t->fTotalUse, time_last, &t->nUseCount, &t->fBalance, &t->nDel) == EOF)
				*t = getcard(++i);
		return 1;
		}
	else
		return 0;
}



