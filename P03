#include <stdio.h>
#include <ctime>

#define IN "P03IN.txt"
#define OUT "P03OUT.txt"

char table[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
	clock_t cS = clock();

	int iChar;
	bool bFlag;

	while ((iChar = getchar()) != EOF)
	{
		bFlag = true;
		for (int i = 0; table[i] && bFlag; i++)
		{
			if (iChar == ' ')
			{
				bFlag = false;
				putchar(iChar);
			}
			else if (iChar == table[i])
			{
				bFlag = false;
				putchar(table[i - 1]);
			}
			else
				continue;

		}
	}



	clock_t cE = clock();
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	double cost = (double)(cE - cS) / CLK_TCK;
	printf("Cost time: %.2f\n", cost);

	return 0;
}
