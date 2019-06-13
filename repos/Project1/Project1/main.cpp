#include<iostream>
#include<string>
#include<fstream>
#include<vector>
//#include"huffman.h"
#include"file.h"
#pragma warning(suppress : 4996)
using namespace std;



int main(){
	
	
cout << "请输入要压缩的文件：";
cin >> inadress;
//ifstream in(inadress);
/*strcpy(outadress, inadress);
strcat(outadress,".huf");
ofstream out(outadress);*/
FILE* in = fopen(inadress, "rb");
int tempch;
while ((tempch = getc(in)) != EOF)
{
	weight[tempch]++;
}
//char ch;
/*while(in.get(ch))
{
	int i = ch;
	
	weight[i]++;
	}*/
cout << "Bets\t" << "Weight" << endl;
for (int i = 0; i < 256; i++) {
	printf("0x%02x\t%6d\n", i, weight[i]);
}
return 0;
}


