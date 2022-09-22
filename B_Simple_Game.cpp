#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    if (n == 1)
        cout << 1;
    else if (m - 1 >= n - m)
        cout << m - 1;
    else
        cout << m + 1;

    return 0;
}