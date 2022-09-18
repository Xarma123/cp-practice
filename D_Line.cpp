#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;

        lol ans = 0;
        vector<lol> prof;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                ans += i;
                if (i < n - (i + 1))
                {
                    prof.push_back(n - (i + 1) - i);
                }
            }
            else if (s[i] == 'R')
            {
                ans += n - (i + 1);
                if (i > n - (i + 1))
                {
                    prof.push_back(i - (n - (i + 1)));
                }
            }
        }
        sort(prof.rbegin(), prof.rend());
        for (lol i = 1; i < prof.size(); i++)
        {
            prof[i] += prof[i - 1];
        }
        for (lol i = 0; i < n; i++)
        {
            if (i < prof.size())
            {
                cout << ans + prof[i] << " ";
            }
            else if (prof.size() > 0)
            {
                cout << ans + prof.back() << " ";
            }
            else
                cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}