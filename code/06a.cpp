#include <bits/stdc++.h>
using namespace std;

const int MARKER_LEN = 4;

bool is_valid(const array<char, MARKER_LEN> & marker)
{
    return  marker[0] != marker[1] && marker[0] != marker[2] &&
            marker[0] != marker[3] && marker[1] != marker[2] &&
            marker[1] != marker[3] && marker[2] != marker[3];
}

int main()
{
    array<char, MARKER_LEN> marker = {'0', '0', '0', '0'};
    cin >> marker[0] >> marker[1] >> marker[2];

    int read = MARKER_LEN-1;
    char current;

    while (cin >> current)
    {
        marker[read++ % MARKER_LEN] = current;
        if (is_valid(marker))
            break;
    }

    cout << read << "\n";
    return 0;
}