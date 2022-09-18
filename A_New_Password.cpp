#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol i = 0;
    while (n--)
    {
        cout << char('a' + i);
        i++;
        i %= k;
    }

    return 0;
}