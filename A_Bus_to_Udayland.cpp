#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s[n];
    bool ans = false;
    for (lol i = 0; i < n; i++)
    {
        cin >> s[i];

        for (lol j = 0; j < s[i].size() - 1 && !ans; j++)
        {
            if (s[i][j] == 'O' && s[i][j + 1] == 'O')
            {
                s[i][j] = s[i][j + 1] = '+';
                ans = true;
            }
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
        for (auto e : s)
            cout << e << endl;
    }
    else
        cout << "NO";

    return 0;
}