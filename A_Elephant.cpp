#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x;
    cin >> x;
    lol ans = x / 5;
    x = x % 5;
    ans += x / 4;
    x %= 4;
    ans += x / 3;
    x %= 3;
    ans += x / 2;
    x %= 2;
    ans += x / 1;
    x %= 1;
    cout << ans;

    return 0;
}