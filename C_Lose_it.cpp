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
    lol q[6] = {4, 8, 15, 16, 23, 42};
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        lol j = 0;
        for (; j < 6; j++)
        {
            if (q[j] == a[i])
                break;
        }
        if (j == 0)
            mp[q[j]]++;
        else
        {

            if (mp[q[j - 1]])
            {
                mp[q[j - 1]]--;
                mp[q[j]]++;
            }
        }
    }

    lol s = mp[q[5]];
    cout << n - 6 * s << endl;

    return 0;
}