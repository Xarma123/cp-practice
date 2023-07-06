#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    if (((long long)s.size()) % 2 != 0)
    {
        while (q--)
        {
            cout << "NO\n";
        }
        return 0;
    }
    set<lol> o, c;
    for (lol i = 1; i < s.size(); i++)
    {
        if (s[i] == '(' && s[i - 1] == '(')
            o.insert(i - 1);
    }
    for (lol i = 1; i < s.size(); i++)
    {
        if (s[i] == ')' && s[i - 1] == ')')
            c.insert(i - 1);
    }
    while (q--)
    {
        lol i;
        cin >> i;
        i--;
        if (i - 1 >= 0)
        {
            if (s[i] == s[i - 1])
            {
                if (s[i] == '(')
                    o.erase(i - 1);
                else
                    c.erase(i - 1);
            }
        }
        if (i + 1 < s.size())
        {
            if (s[i] == s[i + 1])
            {
                if (s[i] == '(')
                    o.erase(i);
                else
                    c.erase(i);
            }
        }
        if (s[i] == '(')
            s[i] = ')';
        else
            s[i] = '(';
        if (i - 1 >= 0)
        {
            if (s[i] == s[i - 1])
            {
                if (s[i] == '(')
                    o.insert(i - 1);
                else
                    c.insert(i - 1);
            }
        }
        if (i + 1 < s.size())
        {
            if (s[i] == s[i + 1])
            {
                if (s[i] == '(')
                    o.insert(i);
                else
                    c.insert(i);
            }
        }

        if (s[0] == ')' || s.back() == '(')
            cout << "NO\n";
        else if (o.size() == 0 && c.size() == 0)
            cout << "YES\n";
        else if (o.size() == 0)
            cout << "NO\n";
        else if (c.size() == 0)
            cout << "NO\n";
        else if ((*o.begin()) < (*c.begin()) && (*o.rbegin()) < (*c.rbegin()))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}