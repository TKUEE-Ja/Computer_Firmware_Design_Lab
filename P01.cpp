#include <stdio.h>
#include <iostream>

using namespace std;

#define IN "P01IN.txt"
#define OUT "P01OUT,txt"

int main()
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
	long long n, count;
	while (cin >> n)
	{
		count = 0;
		while (n != 1)
		{
			if (n % 2)
			{
				n = 3 * n + 1;
				count++;
			}
			else
			{
				n /= 2;
				count++;
			}
		}
		cout << count << "\n";
	}

	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
