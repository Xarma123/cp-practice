#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol k;
string re(string &a, string &b)
{

    string c(k, 'z');
    for (lol i = 0; i < k; i++)
    {
        if (a[i] == b[i])
            c[i] = a[i];
        else
        {
            if (a[i] != 'S' && b[i] != 'S')
                c[i] = 'S';
            if (a[i] != 'E' && b[i] != 'E')
                c[i] = 'E';
            if (a[i] != 'T' && b[i] != 'T')
                c[i] = 'T';
        }
    }
    return c;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n >> k;
    string a[n];
    unordered_map<string, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a, a + n);
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        mp[a[i]]--;
        lol c = 0;
        for (lol j = i + 1; j < n; j++)
        {
            mp[a[j]]--;
            c += mp[re(a[i], a[j])];
            mp[a[j]]++;
        }
        ans += c / 2;
    }
    cout << ans;
}