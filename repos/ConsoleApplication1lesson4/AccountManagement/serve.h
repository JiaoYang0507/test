#pragma once


typedef struct Billing
{
	char aCardName[18];
	time_t tStart;
	time_t tEnd;
	float fAmount;//���ѽ��
	int nStatus;//��״̬
	int nDel;//ɾ��״̬
}Billing;

typedef struct LogonInfo
{
	char aCardName[18];//����
	time_t tLogon;
	float fLeft;
}LogonInfo;

typedef struct SettleInfo
{
	char aCardName[18];
	time_t tStart;
	time_t tEnd;
	float fAmount;
	float fLeft;
}SettleInfo;

typedef struct Money
{
	char aCardName[18];
	time_t tTime;
	int nStatus;
	float fMoney;
	int nDel;
}Money;

typedef struct MoneyInfo
{
	char aCardName[18];
	float fMoney;
	float fLeft;
}MoneyInfo;
