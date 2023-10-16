#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool check(string a, string b)
{
    if (a.size() < b.size())
        return false;
    for (lol i = 0; i + b.size() - 1 < a.size(); i++)
    {
        if (a.substr(i, b.size()) == b)
            return true;
    }
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
        lol n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;

        lol ans = 0;
        while (!check(a, b) && ans <= 10)
        {
            ans++;
            a = a + a;
        }
        if (check(a, b))
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
}