#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            mp[t]++;
        }
        lol q = mp.size();
        lol ans = q;
        for (lol i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                cout << ans << " ";
            }
            else
            {
                if (q == 1)
                {
                    ans++;
                    cout << ans << " ";
                }
                else
                {
                    q--;
                    cout << ans << " ";
                }
            }
        } 
        cout<<endl;
    }

    return 0;
}