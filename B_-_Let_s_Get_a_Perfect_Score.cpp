#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(string a, string b)
{
    for (lol i = 0; i < a.size(); i++)
    {
        if (a[i] == 'x' && b[i] == 'x')
            return false;
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = i + 1; j < n; j++)
        {
            if (check(a[i], a[j]))
                ans++;
        }
    }
    cout << ans;

    return 0;
}