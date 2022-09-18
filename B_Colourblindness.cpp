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
        string s2;
        cin >> s2;
        lol c = 0;
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'R' || s2[i] == 'R')
            {
                if (s[i] != s2[i])
                    ans = false;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}