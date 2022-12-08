#include <bits/stdc++.h>
using namespace std;

const string FILENAME = "../inputs/08.txt";

vector<vector<int>> read_input()
{
    ifstream file (FILENAME);
    if (! file) throw std::invalid_argument("Input file doesn't exist");

    vector<vector<int>> trees;
    string line;

    while (getline(file, line))
    {
        vector<int> row;

        for (char c : line)
            row.push_back(c - '0');
        trees.push_back(row);
    }

    return trees;
}

bool is_visible(const vector<vector<int>> & trees, int i, int j)
{
    int x;

    // left
    for (x = j-1; x >= 0; x--)
        if (trees[i][x] >= trees[i][j])
            break;
    if (x == -1) return true;  // check if the for loop reached the end (didn't break)

    // right
    for (x = j+1; x < (int) trees[i].size(); x++)
        if (trees[i][x] >= trees[i][j])
            break;
    if (x == trees[i].size()) return true;

    // up
    for (x = i-1; x >= 0; x--)
        if (trees[x][j] >= trees[i][j])
            break;
    if (x == -1) return true;

    // down
    for (x = i+1; x < (int) trees.size(); x++)
        if (trees[x][j] >= trees[i][j])
            break;
    if (x == trees.size()) return true;

    return false;
}

int get_view_score(const vector<vector<int>> & trees, int i, int j)
{
    vector<int> scores = {0, 0, 0, 0};

    // left
    for (int x = j-1; x >= 0; x--)
    {
        scores[0]++;
        if (trees[i][x] >= trees[i][j]) break;
    }

    // right
    for (int x = j+1; x < (int) trees[i].size(); x++)
    {
        scores[1]++;
        if (trees[i][x] >= trees[i][j]) break;
    }

    // up
    for (int x = i-1; x >= 0; x--)
    {
        scores[2]++;
        if (trees[x][j] >= trees[i][j]) break;
    }

    // down
    for (int x = i+1; x < (int) trees.size(); x++)
    {
        scores[3]++;
        if (trees[x][j] >= trees[i][j]) break;
    }

    return scores[0] * scores[1] * scores[2] * scores[3];
}

int part_one(const vector<vector<int>> & trees)
{
    int visible_cnt = (int) trees.size() * 4 - 4;

    for (int i = 1; i < (int) trees.size()-1; i++)
        for (int j = 1; j < (int) trees[i].size()-1; j++)
            if (is_visible(trees, i, j))
                visible_cnt++;

    return visible_cnt;
}

int part_two(const vector<vector<int>> & trees)
{
    int max_score = INT_MIN, current_score;

    for (int i = 1; i < (int) trees.size()-1; i++)
        for (int j = 1; j < (int) trees[i].size()-1; j++)
            if ((current_score = get_view_score(trees, i, j)) > max_score)
                max_score = current_score;

    return max_score;
}

int main()
{
    vector<vector<int>> trees = read_input();
    cout << part_one(trees) << "\n";
    cout << part_two(trees) << "\n";
    return 0;
}