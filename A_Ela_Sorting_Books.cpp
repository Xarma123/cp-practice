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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol f[26];
        memset(f, 0, sizeof(f));
        for (auto c : s)
        {
            f[c - 'a']++;
        }
        string ans = "";
        for (lol i = 0; i < k; i++)
        {
            lol c = n / k;
            lol j;
            for (j = 0; j < 26 && c; j++)
            {
                if (f[j])
                {
                    f[j]--;
                    c--;
                }
                else
                {
                    break;
                }
            }
            ans.push_back(char('a' + j));
        }
        cout << ans << endl;
    }

    return 0;
}