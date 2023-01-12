#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a;
    cin >> a;
    string y = "";
    lol b;
    cin >> b;
    string x = "";
    while (b)
    {
        x.push_back(char('0' + (b % 3)));
        b /= 3;
    }
    while (a)
    {
        y.push_back(char('0' + (a % 3)));
        a /= 3;
    }
    while (x.size() < y.size())
    {
        x = x + "0";
    }
    while (y.size() < x.size())
    {
        y = y + "0";
    }

    string ans = "";
    for (lol i = 0; i < x.size(); i++)
    {
        lol v = 0;
        v += y[i] - '0';
        ans.push_back(char((((x[i] - '0') - v + 3) % 3) + '0'));
    }
    lol q = 0;
    lol p = 1;
    for (lol i = 0; i < ans.size(); i++)
    {
        q += (ans[i] - '0') * 1ll * p;
        p = 3ll * p;
    }

    cout << q;

    return 0;
}