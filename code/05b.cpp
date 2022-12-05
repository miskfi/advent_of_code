#include <bits/stdc++.h>
using namespace std;

vector<string> read_stacks()
{
    vector<string> lines;
    string line;
    while(getline(cin, line) && ! line.empty())
        lines.push_back(line);

    // create stack string for each column + 1 for easier indexing
    vector<string> stacks (lines.back().size()/4+1, "");

    lines.pop_back();
    for (int i = (int) lines.size()-1; i >= 0; i--)
        for (int j = 1; j < lines[i].size(); j += 4)
            if (! isblank(lines[i][j]))
                stacks[j/4].push_back(lines[i][j]);

    return stacks;
}

void move_one(vector<string> & stacks, int from, int to)
{
    stacks[to].push_back(stacks[from].back());
    stacks[from].pop_back();
}

int main()
{
    vector<string> stacks = read_stacks();

    string _;  // throwaway variable for reading the string parts of the input
    int amount, from, to;

    while(cin >> _ >> amount >> _ >> from >> _ >> to)
    {
        for (int i = 0; i < amount; i++)
            move_one(stacks, from-1, to-1);

        reverse(stacks[to-1].end()-amount, stacks[to-1].end());
    }

    for (auto stack : stacks)
        cout << stack.back();
    cout << "\n";
    return 0;
}