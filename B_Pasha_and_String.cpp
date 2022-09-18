#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol m;
    cin >> m;
    lol n = s.size() / 2 + (s.size() % 2);
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        a[i] = 0;
    }

    while (m--)
    {
        lol q;
        cin >> q;
        a[q - 1]++;
    }
    for (lol i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    for (lol i = 0; i < s.size(); i++)
    {
        if (i < n)
        {
            if (a[i] % 2 != 0)
                swap(s[i], s[s.size() - i - 1]);
        }
    }
    cout << s;

    return 0;
}