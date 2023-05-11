#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;
//簡化
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

typedef set<int> SET;		//型態定義:把set<int>改寫為SET
map<SET, int> setCatch;		//set 轉 id
vector<SET> idCatch;		//id 轉 set

int ID(SET x)
{
	//檢查x集合是否存在
	if (setCatch.count(x)) return setCatch[x];	//如果存在 就把x回傳
	//如果不存在 則新增集合 x 再回傳
	idCatch.push_back(x);
	setCatch[x] = idCatch.size() - 1;
	return setCatch[x];
}

int main()
{
	freopen("P17IN.txt", "r", stdin);
	freopen("P17OUT.txt", "w", stdout);

	int N, C;	// N 次運算 C個命令
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> C;
		stack<int> setID;
		for (int j = 0;j < C;j++)
		{
			string s;
			cin >> s;							//讀取命令字串
			if (s[0] == 'P')					//PUSH命令
			{
				SET x;
				setID.push(ID(x));
			}
			else if (s[0] == 'D')				//DUP命令
				setID.push(setID.top());
			else								//需要兩個集合做運算的命令
			{
				SET x1, x2, x;
				//堆疊最頂層的集合給x1 : 之後把堆疊最頂層彈出(刪除)
				x1 = idCatch[setID.top()];
				setID.pop();
				//堆疊最頂層的集合給x2 : 之後把堆疊最頂層彈出(刪除)
				x2 = idCatch[setID.top()];
				setID.pop();
				if (s[0] == 'U')
					set_union(ALL(x1), ALL(x2), INS(x));
				else if (s[0] == 'T')
					set_intersection(ALL(x1), ALL(x2), INS(x));
				else
				{
					x = x2;
					x.insert(ID(x1));
				}
				//處理完的輸出集合 加回 setID
				setID.push(ID(x));
			}
			//印出最後堆疊集合的層數
			cout << idCatch[setID.top()].size() << "\n";
		}
		cout << "***" << "\n";
	}
	
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
