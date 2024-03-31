#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool cmp(string a, string b)
{
    lol i = (long long)a.size() - 1;
    while (i >= 0 && a[i] == '0')
        i--;
    lol j = (long long)b.size() - 1;
    while (j >= 0 && b[j] == '0')
        j--;

    lol v2 = (long long)b.size() - 1 - j;
    lol v1 = (long long)a.size() - 1 - i;
    if (v1 > v2)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        for (lol i = 0; i < n; i += 2)
        {
            while (a[i].back() == '0')
                a[i].pop_back();
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans += a[i].size();
        }
        if (ans >= m + 1)
        {
            cout << "Sasha\n";
        }
        else
            cout << "Anna\n";
    }

    return 0;
}
