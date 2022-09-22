#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
lol a[(long long)(1e5 + 10)];
lol c[(long long)(1e5 + 10)];
lol mx(string &s, lol i)
{
    if (i < 0)
        return 0;
    if (s[i] == '1')
    {
        return max(c[i], mx(s, i - 1) + a[i]);
    }
    else
    {
        return mx(s, i - 1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    c[0] = 0;
    cin >> n;

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i + 1] = a[i];
        c[i + 1] += c[i];
    }
    string s;
    cin >> s;
    cout << mx(s, s.size() - 1);

    return 0;
}