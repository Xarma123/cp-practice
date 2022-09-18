#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol lps[s.size()];
    lps[0] = 0;
    lol i = 1, len = 0;
    while (i < s.size())
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;

            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;

                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
    lol n = s.size() - 1;
    if (lps[n] == 0)
        cout << "Just a legend";
    else
    {
        bool f = false;
        for (lol i = 0; i < n; i++)
        {
            if (lps[i] == lps[n])
                f = true;
        }
        if (f)
            cout << s.substr(0, lps[n]);
        else
        {
            if (lps[lps[n] - 1] == 0)
                cout << "Just a legend";
            else
                cout << s.substr(0, lps[lps[n] - 1]);
        }
    }
    return 0;
}