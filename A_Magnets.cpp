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
    n--;
    lol l;
    cin >> l;
    l /= 10;
    lol ans = 1;
    while (n--)
    {
        lol f;
        cin >> f;
        f /= 10;
        if (f == 1 - l)
        {
            ans++;
        }
        l = f;
    }
    cout << ans;

    return 0;
}