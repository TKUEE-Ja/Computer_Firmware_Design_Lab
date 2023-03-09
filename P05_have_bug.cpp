#include <stdio.h>
#include <ctime>

#define IN "P05IN.txt"
#define OUT "P05OUT.txt"

int main()
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
	clock_t cS = clock();

	int game = 0;
	int leng;
	while (scanf("%d", &leng) == 1 && leng)
	{
		int* s = new int[leng];		//store question
		int* g = new int[leng];		//store game
		int* st = new int[leng];	//copy question for operation

		printf("Game: %d\n", ++game);
		for (int i=0; i < leng; i++)
		{
			scanf("%d", &s[i]);
		}

		bool flag = true;
		while (flag)			//infinite loop
		{
			int A = 0;		//both number and location correct
			int B = 0;		//only number correct but location
			for (int i = 0; i < leng;i++)
			{
				scanf("%d", &g[i]);		//read guess number
				//check A
				st[i] = s[i];
				if (st[i] == g[i])
				{
					A++;
					st[i] = -1;
					g[i] = -1;
				}
				//check B
				
				
			}
			if (g[0] == 0)
			{
				flag = false;
			}
			else
			{
				for (int i = 0; i < leng;i++)
				{
					if (st[i] != -1)
					{
						for (int j = 0;j < leng;j++)
						{
							if (st[j] == g[i])
							{
								B++;
								st[j] = -1;
								break;
							}
						}
					}
				}
				printf("(%d,%d)\n", A, B);
			}
		}
		delete[] s, g, st;
	}


	clock_t cE = clock();
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	double cost = (double)(cE - cS) / (CLK_TCK);
	printf("Cost time: %.2f\n", cost);

	return 0;
}
