#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	freopen("P03IN.txt", "r", stdin);
	freopen("P03OUT.txt", "w", stdout);

	char a;
	char s[] = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'\\ZXCVBNM,./";
	while (cin.get(a))				//WARNING!! cin can't get the space
	{
		if (a == ' ')
		{
			cout << " ";
		}
		else
		{
			for (int i = 0; i < sizeof s / sizeof s[0]; i++)
			{
				if (a == s[i])
				{
					cout << s[i - 1];
				}
			}
		}
	}

	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);

	return 0;
}
