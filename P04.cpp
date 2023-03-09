#include <stdio.h>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

#define IN "P04IN.txt"
#define OUT "P04OUT.txt"

string nT = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string mT = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

bool isP(string str)
{
	string rev_str = str;
	reverse(rev_str.begin(), rev_str.end());
	return rev_str == str;
}

bool isM(string str)
{
	string rev_str = str;
	reverse(rev_str.begin(), rev_str.end());
	for (int i = 0; i < rev_str.size();i++)
	{
		int pos = nT.find(rev_str[i]);
		rev_str[i] = mT[pos];
	}
	return rev_str == str;
}

int main()
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
	clock_t cS = clock();

	string input;

	while (cin >> input)
	{
		bool P = isP(input);
		bool M = isM(input);

		printf("%s -- ", input.c_str());
		if (P && M)
			printf("is a mirrored palindrome.");
		else if (P)
			printf("is a regular palindrome.");
		else if (M)
			printf("is a mirrored string.");
		else
			printf("is not a palindrome.");
		printf("\n");

	}

	clock_t cE = clock();
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	double cost = (double)(cE - cS) / CLK_TCK;
	printf("cost time: %.2f\n", cost);
	
	return 0;
}
