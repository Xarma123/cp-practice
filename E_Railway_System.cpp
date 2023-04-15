#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    pair<lol, lol> a[m];
    string s = "";
    for (lol i = 0; i < m; i++)
    {
        a[i].second = i;
        s += '0';
    }
    for (lol i = 0; i < m; i++)
    {
        if (i == 0)
            s[i] = '1';
        else
            swap(s[i - 1], s[i]);
        cout << "? " << s << endl;
        lol v;
        cin >> v;
        a[i].first = v;
    }
    sort(a, a + m);
    s[m - 1] = '0';
    lol sum = 0;
    for (lol i = 0; i < m; i++)
    {
        s[a[i].second] = '1';
        cout << "? " << s << endl;
        lol v;
        cin >> v;
        if (sum + a[i].first == v)
        {
            sum = v;
        }
        else
            s[a[i].second] = '0';
    }
    cout << "! " << sum << endl;

    return 0;
}