#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, m;
bool check(lol v)
{
    if (v == m)
        return true;
    if (v % 3 != 0)
        return false;
    v /= 3;
    if (check(v))
        return true;
    v *= 2ll;
    if (check(v))
        return true;
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (check(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}