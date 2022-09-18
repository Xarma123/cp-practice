#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol f[3];
    f[0] = f[1] = f[2] = 0;
    for (lol i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        if (s[1] == '>')
        {
            f[s[0] - 'A']++;
        }
        else
        {
            f[s[2] - 'A']++;
        }
    }
    char ans[3];
    ans[0] = ans[1] = ans[2] = '\n';
    bool c = true;
    for (lol i = 0; i < 3; i++)
    {
        if (f[i] >= 0 && f[i] < 3)
        {
            if (ans[f[i]] != '\n')
                c = false;
            else
                ans[f[i]] = char('A' + i);
        }
        else
            c = false;
    }
    if (c)
    {
        for (lol i = 0; i < 3; i++)
        {
            cout << ans[i];
        }
    }
    else
        cout << "Impossible";

    return 0;
}