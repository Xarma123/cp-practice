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
    lol ans = 0;
    while (n--)
    {
        lol o = 0, a;
        cin >> a;
        if (a)
            o++;
        cin >> a;
        if (a)
            o++;
        cin >> a;
        if (a)
            o++;
        if (o >= 2)
            ans++;
    }
    cout << ans;

    return 0;
}