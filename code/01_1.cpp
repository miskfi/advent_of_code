#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cur = 0, max = INT_MIN;
    string line;

    while (getline(cin, line))
    {
        if (line.empty())
        {
            if (cur > max)
                max = cur;
            cur = 0;
        }
        else
            cur += stoi(line);
    }

    cout << max << "\n";
    return 0;
}