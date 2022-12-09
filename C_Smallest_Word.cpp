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
    bool f = true;
    lol ans[s.size()];
    memset(ans, 0, sizeof(ans));
    for (lol i = 0; i < s.size(); i++)
    {

        if (s[i] == 'a')
        {
            lol j = i + 1;
            while (j < s.size() && s[j] == s[i])
                j++;
            if (i - 1 >= 0)
            {
                ans[i - 1] = 1;
            }
            ans[j - 1] = 1;
            i = j - 1;
        }
    }
    for (lol i = 0; i < s.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}