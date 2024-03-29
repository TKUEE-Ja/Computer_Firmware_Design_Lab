#include <stdio.h>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

string nT = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string mT = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

bool isP(string str) {
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    return rev_str == str;
}

bool isM(string str) {
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    for (int i = 0; i < rev_str.size(); i++) {
        int pos = nT.find(rev_str[i]);
        rev_str[i] = mT[pos];
    }
    return rev_str == str;
}

int main() {

    freopen("P04IN.txt", "r", stdin);
    freopen("P04OUT.txt", "w", stdout);

    string input;

    while (cin >> input) {
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

    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);

    return 0;
}
