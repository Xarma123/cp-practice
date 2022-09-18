#include <bits/stdc++.h>
using namespace std;
#define lol long long
void towerOfHanoi(lol n, char cur_rod, char target_rod, char help_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, cur_rod, help_rod, target_rod);
    cout << "Move disk " << n << " from rod " << cur_rod << " to rod " << target_rod << endl;
    towerOfHanoi(n - 1, help_rod, target_rod, cur_rod);
}

int main()
{
    lol n;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
