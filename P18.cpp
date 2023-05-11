#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;



int main()
{
	freopen("P18IN.txt", "r", stdin);
	freopen("P18OUT.txt", "w", stdout);

	int T, M, id;				//T個隊伍 每隊有M個成員 以及其id
	int qCnt = 0;				//用來印出處理的佇列數

	while (cin >> T && T != 0)
	{
		//紀錄每個id的所屬隊伍
		map<int, int> tid;
		for (int t = 0;t < T;t++)
		{
			cin >> M;
			for (int m = 0;m < M;m++)
			{
				cin >> id;
				tid[id] = t;	//標記id所屬隊伍
			}
		}
		//處理佇列命令
		queue<int> qt;			//紀錄存在的隊伍
		queue<int> qid[1000];	//紀錄存在的id
		printf("Scenario #%d\n", ++qCnt);		//印出處理的佇列
		string s;				//讀命令字串 s
		while (cin >> s && s[0] != 'S')
		{
			int t0;
			if (s[0] == 'E')	//ENQUEUE命令
			{
				cin >> id;
				t0 = tid[id];	//取得所屬隊伍
				//檢查所屬隊伍是否存在
				if (qid[t0].empty())
					qt.push(t0);		//不存在則將所屬隊伍加入佇列
				qid[t0].push(id);		//id加入佇列
			}
			else
			{
				//s[0] == 'D' DEQUEUE 命令
				t0 = qt.front();		//取得對首的所屬隊伍
				cout << qid[t0].front() << "\n";		//印出要離隊的id
				qid[t0].pop();			//刪除離隊id
				//檢查隊伍是否還有id在佇列中
				if (qid[t0].empty())
					qt.pop();			//如果隊伍成員全部離隊 則刪除隊伍
			}
		}
	}
	
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
