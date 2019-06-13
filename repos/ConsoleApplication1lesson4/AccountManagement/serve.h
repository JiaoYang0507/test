#pragma once


typedef struct Billing
{
	char aCardName[18];
	time_t tStart;
	time_t tEnd;
	float fAmount;//Ïû·Ñ½ð¶î
	int nStatus;//¿¨×´Ì¬
	int nDel;//É¾³ý×´Ì¬
}Billing;

typedef struct LogonInfo
{
	char aCardName[18];//¿¨ºÅ
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
