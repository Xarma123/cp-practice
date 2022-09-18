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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
            cout << 0 << endl;
        else
        {
            lol c = 0;
            map<lol, lol> mp;
            for (lol i = 0; i < n; i++)
            {
                mp[a[i]] = c;
                lol j = i + 1;
                if (j < n)
                {
                    bool f = a[j] > a[i];
                    mp[j] = c;
                    j++;
                    if (j < n)
                    {
                        if (f)
                        {
                            while (a[j] > a[j - 1])
                            {
                                mp[j] = c;
                                j++;
                                if (j == n)
                                    break;
                            }
                        }
                        else
                        {
                            while (a[j] < a[j - 1])
                            {
                                mp[j] = c;
                                j++;
                                if (j == n)
                                    break;
                            }
                        }
                    }
                    c++;
                    i = j - 1;
                }
            }
            cout << mp[n - 1] + 1 << endl;
        }
    }

    return 0;
}