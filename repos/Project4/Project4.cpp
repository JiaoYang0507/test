#include <stdio.h>
#include <stdlib.h>
#include<string.h> 

int main()
{
	char a[20];
	int b[20], c[18], d[18], e = 0, n, i;
	c[1] = 7; c[2] = 9; c[3] = 10; c[4] = 5; c[5] = 8; c[6] = 4; c[7] = 2; c[8] = 1; c[9] = 6; c[10] = 3; c[11] = 7; c[12] = 9; c[13] = 10; c[14] = 5; c[15] = 8; c[16] = 4; c[17] = 2;
	printf("请输入身份证号\n");
	gets_s(a);
	for (i = 1; i <= 18; i++) {
		if (a[i - 1] == 'X')
			break;
		b[i] = (a[i - 1]) - '0';
	}
	for (i = 1; i <= 17; i++)
		d[i] = b[i] * c[i];
	for (int j = 1; j <= 17; j++)
		e = e + d[j];
	n = e % 11;
	if (n == 2 && a[17] == 'X')
		printf("身份证号是正确的");
	else if (n == 0 && a[17] == '1')
		printf("身份证号是正确的");
	else if (n == 1 && a[17] == '0')
		printf("身份证号是正确的");
	else if (n == 3 && a[17] == '9')
		printf("身份证号是正确的");
	else if (n == 4 && a[17] == '8')
		printf("身份证号是正确的");
	else if (n == 5 && a[17] == '7')
		printf("身份证号是正确的");
	else if (n == 6 && a[17] == '6')
		printf("身份证号是正确的");
	else if (n == 7 && a[17] == '5')
		printf("身份证号是正确的");
	else if (n == 8 && a[17] == '4')
		printf("身份证号是正确的");
	else if (n == 9 && a[17] == '3')
		printf("身份证号是正确的");
	else if (n == 10 && a[17] == '2')
		printf("身份证号是正确的");
	else
		printf("身份证号是错误的");
	return 0;
}
