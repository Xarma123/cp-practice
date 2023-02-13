#include <bits/stdc++.h>
#define lol long long
using namespace std;
long double a[16][16];
string s[16];
vector<long double> v[32];
void dfs(lol c, lol l, lol r)
{
    if (r - l == 1)
    {
        v[c].push_back(1);
        return;
    }

    lol m = (l + r) / 2;
    dfs(2 * c + 1, l, m);
    dfs(2 * c + 2, m, r);
    lol i = 0;
    for (auto e : v[2 * c + 1])
    {
        long double q = 0;
        lol j = 0;
        for (auto ee : v[2 * c + 2])
        {
            q += e * ee * a[l + i][m + j] / (long double)100;
            j++;
        }
        v[c].push_back(q);
        i++;
    }
    i = 0;
    for (auto e : v[2 * c + 2])
    {
        long double q = 0;
        lol j = 0;
        for (auto ee : v[2 * c + 1])
        {
            q += e * ee * a[m + i][l + j] / (long double)100;
            j++;
        }
        v[c].push_back(q);
        i++;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (lol i = 0; i < 16; i++)
    {
        cin >> s[i];
    }
    for (lol i = 0; i < 16; i++)
    {
        for (lol j = 0; j < 16; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(0, 0, 16);
    lol i = 0;
    for (auto e : v[0])
    {
        cout << s[i];
        for (lol j = 0; j < 10 - s[i].size(); j++)
            cout << " ";
        cout << " p=";
        cout << fixed << setprecision(2) << e * (long double)100 << "%" << endl;
        i++;
    }

    return 0;
}