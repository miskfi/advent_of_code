#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

const int FS_SIZE = 70000000,
          FREE_SPACE_REQUIRED = 30000000,
          NEED_TO_FREE = FREE_SPACE_REQUIRED - (FS_SIZE - 43562874);

int find_size(int & smallest_to_delete)
{
    int current_dir_sum = 0, file;
    string command;

    while (getline(cin, command))
    {
        if (command == "$ cd ..") break;
        if (command == "$ ls") continue;

        if (command.find("$ cd") != string::npos)
            current_dir_sum += find_size(smallest_to_delete);

        if (command.find_first_of("0123456789") != string::npos)
        {
            istringstream iss (command);
            iss >> file;
            current_dir_sum += file;
        }
    }

    if (current_dir_sum > NEED_TO_FREE)
        smallest_to_delete = min(smallest_to_delete, current_dir_sum);
    return current_dir_sum;
}

int main()
{
    string start;
    getline(cin, start);

    int smallest_to_delete = FS_SIZE;
    find_size(smallest_to_delete);

    cout << smallest_to_delete << "\n";
    return 0;
}