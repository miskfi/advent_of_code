#include <bits/stdc++.h>
using namespace std;

char intersect(const vector<string> & rucksacks)
{
    vector<char> intersect;
    std::set_intersection(rucksacks[0].begin(), rucksacks[0].end(),
                          rucksacks[1].begin(), rucksacks[1].end(),
                          std::back_inserter(intersect));

    vector<char> intersect_total;
    std::set_intersection(rucksacks[2].begin(), rucksacks[2].end(),
                          intersect.begin(), intersect.end(),
                          std::back_inserter(intersect_total));

    return intersect_total[0];
}

int main()
{
    int sum = 0, cnt = 0;
    string line;
    vector<string> rucksacks;

    while(getline(cin, line))
    {
        sort(line.begin(), line.end());
        rucksacks.push_back(line);

        if (++cnt % 3 == 0)
        {
            char c = intersect(rucksacks);
            sum += islower(c) ? (c - 'a' + 1) : (c - 'A' + 27);

            rucksacks.clear();
        }
    }

    cout << sum << "\n";
    return 0;
}