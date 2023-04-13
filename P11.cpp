#include <stdio.h>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

#define IN "P11IN.txt"
#define OUT "P11OUT.txt"

//製作解碼查詢表
int T[8][128];
bool mkT()
{
	//查詢表前置處理
	memset(T, 0, sizeof(T));					//矩陣變數初始化(歸零)
	string str;
	while (getline(cin, str) && str.empty());	//跳過讀取空字串
	if(cin.eof() || cin.fail())					//讀取到結尾或失敗時回傳false
	{
		return false;
	}
	//製作查詢表
	int c = 0;									//讀取str字串的索引
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < (1 << i) -1 ;j++)		//1<<i 是位移計算子，1 << 1 = 2 , 1 << 3 = 8
		{
			T[i][j] = str[c];
			c++;
			if (c > str.size())
			{
				return true;
			}
		}
	}
}

//二進制轉十進制
int binToDec(int leng)
{
	int dec = 0;
	char c;
	for (int i = 0; i < leng;i++)
	{
		while ((c = getchar()) == '\n');		//用while迴圈跳過讀取到換行字元'\n'
		dec = dec * 2 + c - '0';				//因為字元讀到是ASCII編碼
	}
	return dec;
}
int main()
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
	clock_t cS = clock();

	while (mkT())
	{
		int leng;
		char c;
		while ((leng = binToDec(3)) != 0)		//解碼讀取長度為0時結束程式
		{
			int idx;
			while ((idx = binToDec(leng)) != (1 << leng) - 1)	//解碼索引(讀到全部都1 重新解碼長度)
			{
				c = T[leng][idx];				//int轉換為char
				cout << c;
			}
		}
		cout << endl;
	}

	clock_t cE = clock();

	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	double cost = (double)(cE - cS) / CLK_TCK;
	printf("Cost time:%.2f\n",cost);
	
	return 0;
}
