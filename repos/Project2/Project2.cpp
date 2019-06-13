#include <stdio.h>
#include<memory.h>
#include<stdlib.h>





int main() {
	double x[] = { 7341,548,220,177,150,149,151,154,136,101,88,94,89,81,574,197,102,80,92,104,78,91,80,62,63,66,61,36,50,38,295,98,66,84,29,28,30,13,16,12,30,39,19,21,19,19,24,16,18,14,20,22,15,13,10,10,22,11,8,18,12,76,18,12,8,7,1,56,71,32,17,11,10,8,4,6,99,33,1,3,6,8,6,10,5,6,3,5,2,8,1,4,3,8,2,4,47,10,9,4,4,1,4,2,5,2,1,2,1,6,1,3,4,3,1,10,10,3,20,42,17,17,5,7,12,7,7,10,4,11,3,9,7,31,10,8,4,2,3,6,3,8,7,4,2,2,2,9,4,3,2,10,1,4,3,1,2,5,1,3,1,4,1,1,1,34,8,3,2,2,1,1,1,1,3,1,1,1,2,1,1,1,1,1,1,10,1,3,2,1,1,1,1,1,1,1,1,1,256,34,15,19,12,12,10,19,23,6,14,4,7 };
	int len = 211;
	int pre_time = 212;
	ExponentialSmoothing(x, len, pre_time);
}



int ExponentialSmoothing(double x[], int len, int pre_time) {

	double weight = 0.6;

	double at = 0.0;

	double bt = 0.0;

	double ct = 0.0;

	double* onetime_pre = (double*)malloc(len * sizeof(double));

	double* twotime_pre = (double*)malloc(len * sizeof(double));

	double* threetime_pre = (double*)malloc(len * sizeof(double));

	double* y = (double*)malloc(pre_time * sizeof(double));

	memset(onetime_pre, 0, len * sizeof(double));

	memset(twotime_pre, 0, len * sizeof(double));

	memset(threetime_pre, 0, len * sizeof(double));

	memset(y, 0, pre_time * sizeof(double));

	//一次指数平滑

	onetime_pre[0] = x[0]; //init

	for (int i = 1; i < len; i++)

	{

		onetime_pre[i] = weight * x[i] + (1 - weight) * onetime_pre[i - 1];

	}

	//二次指数平滑

	twotime_pre[0] = (onetime_pre[0] + onetime_pre[1] + onetime_pre[2]) / 3; //init

	for (int i = 1; i < len; i++)

	{

		twotime_pre[i] = weight * onetime_pre[i] + (1 - weight) * twotime_pre[i - 1];

	}

	//三次指数平滑

	threetime_pre[0] = (twotime_pre[0] + twotime_pre[1] + twotime_pre[2]) / 3; //init

	for (int i = 1; i < len; i++)

	{

		threetime_pre[i] = weight * twotime_pre[i] + (1 - weight) * threetime_pre[i - 1];

	}

	//计算截距和斜率

	at = 3 * onetime_pre[len - 1] - 3 * twotime_pre[len - 1] + threetime_pre[len - 1];

	bt = weight / (2 * (1 - weight) * (1 - weight)) * ((6 - 5 * weight) * onetime_pre[len - 1] - 2 * (5 - 4 * weight) * twotime_pre[len - 1] + (4 - 3 * weight) * threetime_pre[len - 1]);

	ct = (weight * weight) / (2 * (1 - weight) * (1 - weight)) * (onetime_pre[len - 1] - 2 * twotime_pre[len - 1] + threetime_pre[len - 1]);

	//printf("at = %f\n", at);

	//printf("bt = %f\n", bt);

	for (int T = 0; T < pre_time; T++)

	{

		y[T] = at + bt * (T + 1) + ct * (T + 1) * (T + 1);

	}

	double result = sumAllVectord(y, pre_time);

	if (result < 0) result = 0;

	free(onetime_pre);

	free(twotime_pre);

	free(threetime_pre);

	free(y);

	return floor(result);

}
