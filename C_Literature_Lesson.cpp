#include <bits/stdc++.h>
#define lol long long
using namespace std;
string a[10005];
lol n, k;
string suf(string q)
{
    lol c = k;
    for (lol i = q.size() - 1; i >= 0; i--)
    {
        if (q[i] == 'a' || q[i] == 'e' || q[i] == 'i' || q[i] == 'o' || q[i] == 'u')
            c--;
        if (c == 0)
        {
            return q.substr(i);
        }
    }
    return "NIL";
}
string solve(lol i)
{
    vector<string> v;
    lol c = i + 4;
    for (; i < c; i++)
    {
        string s = suf(a[i]);
        if (s == "NIL")
            return "NO";
        v.push_back(s);
    }

    if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3])
        return "aaaa";

    if (v[0] == v[1] && v[2] == v[3])
        return "aabb";
    if (v[0] == v[2] && v[1] == v[3])
        return "abab";
    if (v[0] == v[3] && v[1] == v[2])
        return "abba";
    return "NO";
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (lol i = 0; i < 4 * 1ll * n; i++)
    {
        cin >> a[i];
    }
    string q = ".";
    for (lol i = 0; i < 4ll * n; i += 4)
    {
        string s = solve(i);
        if (s == "NO")
        {
            q = s;
            break;
        }
        else if (q == ".")
        {
            q = s;
        }
        else if (s != q && q == "aaaa")
        {
            q = s;
        }
        else if (s != q && s != "aaaa")
        {
            q = "NO";
            break;
        }
    }
    cout << q;

    return 0;
}