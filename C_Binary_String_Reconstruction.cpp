#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol x;
        cin >> x;
        string ans = s;
        for (lol i = 0; i < ans.size(); i++)
        {
            ans[i] = '2';
        }
        bool a = true;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (i - x >= 0)
                    ans[i - x] = '0';
                if (i + x < s.size())
                    ans[i + x] = '0';
            }
        }
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (i - x >= 0 && (ans[i - x] == '2' || ans[i - x] == '1'))
                {
                    ans[i - x] = '1';
                }
                else if (i + x < s.size() && (ans[i + x] == '2' || ans[i + x] == '1'))
                {
                    ans[i + x] = '1';
                }
                else
                {
                    a = false;
                    break;
                }
            }
        }
        for (lol i = 0; i < s.size(); i++)
        {
            if (ans[i] == '2')
                ans[i] = '1';
        }

        if (a)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}