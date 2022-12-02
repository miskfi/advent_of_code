#include <bits/stdc++.h>
using namespace std;

const char CONVERT = 'X' - 'A';
map<char, char> winning_shape = {{'Z', 'X'}, {'X', 'Y'}, {'Y', 'Z'}};

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
    char p1, p2, strategy;
    int total = 0;

    while (scanf("%c %c\n", &p1, &strategy) == 2)
    {
        p1 += CONVERT;

        if (strategy == 'Y') p2 = p1;
        else if (strategy == 'Z') p2 = winning_shape[p1];
        else p2 = winning_shape[winning_shape[p1]];

        total += p2 - 'X' + 1 + outcome(p1, p2);
    }

    cout << total << "\n";
    return 0;
}