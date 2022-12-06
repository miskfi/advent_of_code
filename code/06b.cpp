#include <bits/stdc++.h>
using namespace std;

const int MARKER_LEN = 14;

/// @brief Check whether the marker is valid (all elements are distinct)
/// @return -1 if valid, index of the first duplicate element in the array if invalid
int is_valid(const array<char, MARKER_LEN> & marker)
{
    unordered_map<char, int> marker_map;
    for (int i = 0; i < marker.size(); i++)
    {
        const auto & [duplicate, success] = marker_map.insert({marker[i], i});
        if (! success)
            return duplicate->second;
    }

    return -1;
}

int main()
{
    array<char, MARKER_LEN> marker;
    for (int i = 0; i < MARKER_LEN; i++)
        cin >> marker[i];

    int read = MARKER_LEN, duplicate_idx;
    char current;

    while ((duplicate_idx = is_valid(marker)) > -1)
    {
        // Read n characters, where n is the index of the first duplicate.
        // This number might not be the optimal number of chars to skip
        // (for example duplicates on index 13 and 15 will return n == 1 because of the modulo)
        // but should never exceed the optimal amount.
        for (int i = 0; i <= duplicate_idx; i++)
        {
            cin >> current;
            marker[read++ % MARKER_LEN] = current;
        }
    }

    cout << read << "\n";
    return 0;
}