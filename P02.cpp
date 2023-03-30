#include <stdio.h>
#include <iostream>

using namespace std;

#define IN "P02IN.txt"
#define OUT "P02OUT,txt"

int main()
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);

	char c;
	int n = 1;
	while (cin >> c)
	{
		if (c == '"')
		{
			if (n % 2)
			{
				cout << "``";
				n++;
			}
			else
			{
				cout << "''";
				n++;
			}
		}
		else if (c == '.')
		{
			cout << ".\n";
		}
		else
		{
			cout << c;
		}
	}

	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
