#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define IN "P12IN.txt"
#define OUT "P12OUT.txt"

typedef struct command
{
	string str;							//儲存命令字串 DR DC IR IC EX
	int r1, c1, r2, c2;					//儲存ex命令交換前後的座標
	int t;								//儲存 D/1 的執行次數
	int op[10];							//儲存 D/1 的行數
}CMD;									//command的縮寫

vector<CMD> cmd;

//模擬指令執行的副程式
bool simulate(int& r, int& c, int ops)
{
	for (int i = 0; i < ops; i++)
	{
		char c1 = cmd[i].str[0];
		char c2 = cmd[i].str[1];
		if (c1 == 'E')
		{
			if (cmd[i].r1 == r && cmd[i].c1 == c)
			{
				r = cmd[i].r2;
				c = cmd[i].c2;
			}
			else if (cmd[i].r2 == r && cmd[i].c2 == c)
			{
				r = cmd[i].r1;
				c = cmd[i].c1;
			}
		}
		else
		{
			int dR = 0, dC = 0;
			for (int T = 0; T < cmd[i].t;T++)
			{
				if (c1 == 'I')										//插入列/欄
				{
					if (c2 == 'R' && r >= cmd[i].op[T]) dR++;		//插入列 且 追蹤列數 >= 新增列
					if (c2 == 'C' && c >= cmd[i].op[T]) dC++;		//插入欄 且 追蹤欄數 >= 新增欄
				}
				else
				{
					//(c1 == 'D') 刪除列/欄
					if (c2 == 'R' && r == cmd[i].op[T]) return false;	//刪除列且追蹤列數 = 刪除列
					if (c2 == 'C' && c == cmd[i].op[T]) return false;	//刪除欄且追蹤欄數 = 刪除欄

					if (c2 == 'R' && r > cmd[i].op[T]) dR--;			//刪除列且追蹤列數 > 刪除列
					if (c2 == 'C' && c > cmd[i].op[T]) dC--;			//刪除欄且追蹤欄數 > 刪除欄
				}
			}
			r = r + dR;
			c = c + dC;
		}
	}
	return true;
}

int main()
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);

	int R, C, ops;
	int num = 0;
	while (cin >> R >> C >> ops)
	{
		//讀輸入檔的命令
		for (int i = 0;i < ops;i++)
		{
			cmd.resize(cmd.size() + 1);
			cin >> cmd[i].str;
			if (cmd[i].str[0] == 'E')
			{
				cin >> cmd[i].r1 >> cmd[i].c1 >> cmd[i].r2 >> cmd[i].c2;
			}
			else
			{
				cin >> cmd[i].t;
				for (int T = 0; T < cmd[i].t; T++)
				{
					cin >> cmd[i].op[T];
				}
			}
		}
		//印出工作列
		if (num > 0) cout << endl;
		cout << "Spreadsheet#" << ++num << endl;
		//開始追蹤
		int r0, c0;
		int T;
		cin >> T;						//讀要追蹤的數量
		for (int i = 0; i < T;i++)
		{
			cin >> r0 >> c0;
			cout <<  "Cell data in (" << r0 << ", " << c0 << ") ";
			if (simulate(r0, c0, ops))
			{
				cout << "moved to (" << r0 << "," << c0 << ")";
			}
			else
			{
				cout << "GONE.";
			}
			cout << "\n";
		}

	}


	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);

	return 0;
}
