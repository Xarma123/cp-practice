#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    lol f1[26];
    lol f2[26];
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    for (lol i = 0; i < s.size(); i++)
    {
        f1[s[i] - 'a']++;
    }
    for (lol i = 0; i < t.size(); i++)
    {
        f2[t[i] - 'a']++;
    }
    bool f = true;
    bool a = false;
    for (lol i = 0; i < 26; i++)
    {
        if (f1[i] < f2[i])
            f = false;
        if (f1[i] > f2[i])
            a = true;
    }
    if (f)
    {
        if (a)
        {
            lol i, j;
            for (i = 0, j = 0; i < s.size() && j < t.size();)
            {
                if (s[i] == t[j])
                {
                    i++;
                    j++;
                }
                if (s[i] != t[j])
                {
                    if (f1[s[i]-'a'] > f2[s[i]-'a'])
                        f1[s[i]-'a']--, i++;
                    else
                    {
                        break;
                    }
                }
            }
            if (j == t.size())
                cout << "automaton";
            else
                cout << "both";
        }
        else
        {
            cout << "array";
        }
    }
    else
    {
        cout << "need tree";
    }

    return 0;
}