#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol n;
string op(string s, lol k)
{
    if (k >= 0)
    {
        string a = "";
        for (lol i = k; i < n; i++)
        {
            a += s[i];
        }
        while (k--)
        {
            a += '0';
        }
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != s[i])
                a[i] = '1';
            else
                a[i] = '0';
        }
        return a;
    }
    else
    {
        k = -k;
        string a = "";

        while (k--)
        {
            a += '0';
        }
        for (lol i = 0; i < n - k; i++)
        {
            a += s[i];
        }
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != s[i])
                a[i] = '1';
            else
                a[i] = '0';
        }
        return a;
    }
}
lol hb(string a)
{
    for (lol i = 0; i < a.size(); i++)
    {
        if (a[i] == '1')
            return i;
    }
    return -1;
}
lol lb(string a)
{
    for (lol i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == '1')
            return i;
    }
    return -1;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        string a, b;
        cin >> a >> b;
        string x(n, '0');
        if (a == x && b == x)
            cout << 0 << '\n';
        else if (a != x && b != x)
        {
            vector<lol> ans;

            if (a[lb(b)] != '1')
            {
                lol i = lb(b);
                lol j = lb(a);

                a = op(a, -i + j);
                ans.push_back(-i + j);
            }
            lol h = hb(a);
            for (lol i = lb(b) + 1; i < n; i++)
            {
                if (a[i] == '1')
                {
                    a = op(a, -i + h);
                    ans.push_back(-i + h);
                }
            }
            lol x = lb(b);
            for (lol i = x - 1; i >= 0; i--)
            {
                if (a[i] != b[i])
                {
                    a = op(a, -i + x);
                    ans.push_back(-i + x);
                }
            }
            cout << ans.size() << '\n';
            for (auto e : ans)
                cout << e << " ";
            if (ans.size())
                cout << '\n';
        }
        else
            cout << -1 << '\n';
    }
}