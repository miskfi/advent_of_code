#include <bits/stdc++.h>
using namespace std;

int main()
{
    int start1, end1, start2, end2, count = 0;

    while (scanf("%d-%d,%d-%d", &start1, &end1, &start2, &end2) == 4)
        if ((end2 >= start1 && end2 <= end1) || (end1 >= start2 && end1 <= end2))
            count++;

    printf("%d\n", count);
    return 0;
}