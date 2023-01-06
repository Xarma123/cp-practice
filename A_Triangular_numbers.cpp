#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    if ((long long)sqrtl(1 + 8 * n) * (long long)sqrtl(1 + 8 * n) == 1 + 8 * n && (((long long)sqrtl(1 + 8 * n)) % 2) != 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}