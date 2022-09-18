#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol n;
        cin >> n;
        vector<lol> ans;
        while (n > 0)
        {
            ans.push_back(n % 3);
            n = n / 3;
        }
        lol j = 0;
        for (lol i = 0; i < ans.size(); i++)
        {
            if (ans[i] == 2)
            {
                j = i;
            }
        }

        for (lol i = 0; i < ans.size(); i++)
        {
            if (i < j)
                ans[i] = 0;
            else
            {
                if (ans[i] == 2)
                {
                    ans[i] = 0;
                    if (i + 1 < ans.size())
                        ans[i + 1]++;
                    else
                        ans.push_back(1);
                }
                if (ans[i] == 3)
                {
                    ans[i] = 0;
                    if (i + 1 < ans.size())
                        ans[i + 1]++;
                    else
                        ans.push_back(1);
                }
            }
        }
        lol m = 0;
        lol v = 1;
        for (lol i = 0; i < ans.size(); i++)
        {
            m += ans[i] * 1ll * v;
            v = v * 1ll * 3;
        }
        cout << m << endl;
    }

    return 0;
}