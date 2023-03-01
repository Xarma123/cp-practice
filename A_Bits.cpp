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
    while (n--)
    {
        lol l, r;
        cin >> l >> r;
        if (l == r)
            cout << r << endl;
        else
        {
            lol j = -1;
            lol ans = r;
            for (lol i = 63; i >= 0; i--)
            {
                if (j != -1)
                    ans |= (1ll << i);
                if (!(l & (1ll << i)))
                {
                    if ((r & (1ll << i)) && j == -1)
                    {
                        ans ^= (1ll << i);
                        j = i;
                    }
                }
            }
            if ((ans | (1ll << j)) <= r)
            {
                ans |= (1ll << j);
            }
            cout << ans << endl;
        }
    }

    return 0;
}