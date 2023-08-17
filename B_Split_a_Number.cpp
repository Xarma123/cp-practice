#include <bits/stdc++.h>
using namespace std;
#define lol long long
string add(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (b.size() < a.size())
        b.push_back('0');
    string v(a.size(), '0');
    lol c = 0;
    for (lol i = 0; i < a.size(); i++)
    {
        lol cr = (a[i] - '0') + (b[i] - '0') + c;
        c = cr / 10;
        cr %= 10;
        v[i] = char('0' + cr);
    }
    if (c)
        v.push_back('1');
    reverse(v.begin(), v.end());
    return v;
}
bool cmp(string a, string b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() > b.size())
        return false;
    return a < b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    string a = s.substr(0, n / 2);
    string b = s.substr(n / 2, n - n / 2);
    vector<string> v;
    if (b[0] != '0')
    {
        v.push_back(add(a, b));
    }
    lol i = n / 2;
    while (i < n && s[i] == '0')
        i++;
    if (i < n)
    {
        a = s.substr(0, i);
        b = s.substr(i, n - i);
        v.push_back(add(a, b));
    }
    i = n / 2 + 1;
    while (i < n && s[i] == '0')
        i++;
    if (i < n)
    {
        a = s.substr(0, i);
        b = s.substr(i, n - i);
        v.push_back(add(a, b));
    }
    i = n / 2 - 1;
    while (i < n && s[i] == '0')
        i++;
    if (i < n)
    {
        a = s.substr(0, i);
        b = s.substr(i, n - i);
        v.push_back(add(a, b));
    }
    i = n / 2 - 1;
    while (i >= 0 && s[i] == '0')
        i--;
    if (i > 0)
    {
        a = s.substr(0, i);
        b = s.substr(i, n - i);
        v.push_back(add(a, b));
    }
    i = n / 2;
    while (i >= 0 && s[i] == '0')
        i--;
    if (i > 0)
    {
        a = s.substr(0, i);
        b = s.substr(i, n - i);
        v.push_back(add(a, b));
    }
    i = n / 2 + 1;
    while (i >= 0 && s[i] == '0')
        i--;
    if (i > 0)
    {
        a = s.substr(0, i);
        b = s.substr(i, n - i);
        v.push_back(add(a, b));
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0];
}