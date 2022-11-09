#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    lol i;
    for (i = s.size() - 1; i >= 0; i--)
    {
        set<char> q;
        if (i - 1 >= 0)
            q.insert(s[i - 1]);
        if (i - 2 >= 0)
            q.insert(s[i - 2]);
        char c = s[i];
        c = char(c + 1);
        while (q.count(c))
        {
            if (c - 'a' == p)
                break;
            c = char(c + 1);
        }
        if (c - 'a' == p)
            continue;
        s[i] = c;

        lol j = i + 1;
        while (j < s.size())
        {
            q.clear();
            if (j - 1 >= 0)
                q.insert(s[j - 1]);
            if (j - 2 >= 0)
                q.insert(s[j - 2]);
            c = 'a';
            while (q.count(c))
                c = char(c + 1);
            s[j] = c;
            j++;
        }
        break;
    }
    if (i < 0)
        cout << "NO";
    else
        cout << s;

    return 0;
}