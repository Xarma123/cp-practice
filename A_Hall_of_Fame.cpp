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
        bool ans = false;
        lol idx = -1;
        for (lol i = 0; i < n - 1; i++)
        {
            if (s[i] == 'R' && s[i + 1] == 'L')
            {
                ans = true;
                cout << 0 << endl;
                break;
            }
            else if (s[i] == 'R' && i + 2 < n && s[i + 2] == 'L')
            {
                idx = i + 2;
            }
            else if (s[i] == 'L' && i - 2 >= 0 && s[i - 2] == 'R')
            {
                idx = i - 1;
            }
            else if (s[i] == 'L' && i + 1 < n && s[i + 1] == 'R')
            {
                idx = i + 1;
            }
        }
        if (!ans)
            cout << idx << endl;
    }

    return 0;
}