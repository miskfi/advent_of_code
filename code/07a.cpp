#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int find_size(int & sum)
{
    int current_dir_sum = 0, file;
    string command;

    while (getline(cin, command))
    {
        if (command == "$ cd ..") break;
        if (command == "$ ls") continue;

        if (command.find("$ cd") != string::npos)
            current_dir_sum += find_size(sum);

        if (command.find_first_of("0123456789") != string::npos)
        {
            istringstream iss (command);
            iss >> file;
            current_dir_sum += file;
        }
    }

    if (current_dir_sum < 100000)
        sum += current_dir_sum;
    return current_dir_sum;
}

int main()
{
    string start;
    getline(cin, start);

    int sum = 0;
    int x = find_size(sum);

    cout << sum << "\n";
    return 0;
}