#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0;
    string line, first, second;

    while(getline(cin, line))
    {
        size_t half = line.size()/2;
        first = line.substr(0, half);
        second = line.substr(half, half);

        for (char c : first)
        {
            if (second.find(c) != string::npos)
            {
                sum += islower(c) ? (c - 'a' + 1) : (c - 'A' + 27);
                break;
            }
        }
    }

    cout << sum << "\n";
    return 0;
}