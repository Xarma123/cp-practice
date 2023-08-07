#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        lol i = 0, j = s.size() - 1;
        bool ans = true;
        vector<lol> tw;
        while (i < j && ans)
        {
            if (s[i] == '?' && s[j] == '?')
            {
                tw.push_back(i);
            }
            else if (s[i] != '?' && s[j] == '?')
            {
                s[j] = s[i];
            }
            else if (s[j] != '?' && s[i] == '?')
            {
                s[i] = s[j];
            }
            else if (s[i] != s[j])
            {
                ans = false;
            }
            i++;
            j--;
        }
        lol one = 0, zero = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                one++;
            else if (s[i] == '0')
                zero++;
        }
        if (((long long)s.size()) % 2 != 0 && s[s.size() / 2] == '?')
        {
            if ((a - zero) % 2 == 1)
            {
                s[s.size() / 2] = '0';
                zero++;
            }
            else if ((b - one) % 2 == 1)
            {
                s[s.size() / 2] = '1';
                one++;
            }
        }
        while (a - zero > 0 && ((a - zero) % 2 == 0) && tw.size())
        {
            lol i = tw.back();
            s[s.size() - 1 - i] = '0';
            s[i] = '0';
            zero += 2;
            tw.pop_back();
        }
        while (b - one > 0 && ((b - one) % 2 == 0) && tw.size())
        {
            lol i = tw.back();
            s[s.size() - 1 - i] = '1';
            s[i] = '1';
            one += 2;
            tw.pop_back();
        }

        if (one == b && zero == a && ans)
            cout << s << '\n';
        else
            cout << -1 << '\n';
    }
}