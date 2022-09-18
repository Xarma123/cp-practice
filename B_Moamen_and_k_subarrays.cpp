#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            mp[b[i]] = i;
        }
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            c++;
            lol j = mp[a[i]];
            j++;
            if (j < n)
            {
                while (a[i + 1] == b[j])
                {
                    i++;
                    j++;
                    if (j == n || i == n - 1)
                        break;
                }
            }
        }
        if (c <= k)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}