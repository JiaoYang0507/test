#include <stdio.h>
#include <stdlib.h>
#include "card.h"
#include "menu.h"
#include <string.h>
#pragma warning(disable : 4996)
void setcard(Card t);
Card getcard(int j);
char* TimeTransfer(time_t t);
time_t StringToTime(char* _time);

int getfile() {
	FILE *file;
	file = fopen("card.txt", "a");  //如果文件不存在则创建一个文件
	fclose(file);
	char time_start[50], time_end[50], time_last[50];
	//time_t t_start, t_end, t_last;
	if ((file = fopen("card.txt", "r")) != NULL) {
		while (!feof(file)) {
			Card *t;
			t = (Card*)malloc(sizeof(Card));
			fscanf(file, "%s %s %d %s %s %f %s %d %f %d\n",
				t->Name, t->Pwd, &t->nStatus, time_start, time_end,
				&t->fTotalUse, time_last, &t->nUseCount, &t->fBalance, &t->nDel);
				t->tStart = StringToTime(time_start);
				t->tEnd = StringToTime(time_end);
				t->tLast = StringToTime(time_last);
				t->next = NULL;
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
	Card *t;
	t = head->next;
	if ((file = fopen("card.txt", "a")) != NULL) {
		while (t != NULL) {
			strcpy(time_start,TimeTransfer(t->tStart));
			strcpy(time_end, TimeTransfer(t->tEnd));
			strcpy(time_last, TimeTransfer(t->tLast));
			fprintf(file, "%s %s %d %s %s %f %s %f %f %d\n",
				t->Name, t->Pwd, t->nStatus, time_start,time_end,
				t->fTotalUse, time_last, t->nUseCount, t->fBalance, t->nDel);
			t = t->next;
		}
		return 1;
	}
	else
		return 0;
}