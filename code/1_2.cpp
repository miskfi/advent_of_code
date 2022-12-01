#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cur = 0;
    string line;
    vector<int> elves;

    while (std::getline(cin, line))
    {
        if (line.empty())
        {
            elves.push_back(cur);
            cur = 0;
        }
        else
            cur += stoi(line);
    }

    sort(elves.begin(), elves.end(), greater<int>());
    std::cout << elves[0] + elves[1] + elves[2] << "\n";
    return 0;
}