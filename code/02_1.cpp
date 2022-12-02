#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

const char CONVERT = 'X' - 'A';

/// @return 6 if p2 won, 3 if it's a draw, 0 if p1 won
int outcome(char p1, char p2)
{
    if (p1 == p2) return 3;
    if ((p2 == 'Z' && p1 == 'X')) return 0;
    if ((p2 == 'X' && p1 == 'Z')) return 6;
    return (p2 > p1) * 6;
}

int main()
{
    char c1, c2;
    int total = 0;

    while (scanf("%c %c\n", &c1, &c2) == 2)
    {
        c1 += CONVERT;
        total += c2 - 'X' + 1 + outcome(c1, c2);
    }

    cout << total << "\n";
    return 0;
}