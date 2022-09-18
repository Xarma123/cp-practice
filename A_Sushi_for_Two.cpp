#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<lol> ans;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        if (j < n)
        {
            while (a[j] == a[i])
            {
                j++;
                if (j == n)
                    break;
            }
        }
        ans.push_back(j - i);
        i = j - 1;
    }
    lol as = LONG_LONG_MIN;
    for (lol i = 0; i < ans.size() - 1; i++)
    {
        as = max(as, 2 * 1ll * min(ans[i], ans[i + 1]));
    }
    cout << as;

    return 0;
}