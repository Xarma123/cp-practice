#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    unordered_set<char> mp;
    while (k--)
    {
        char c;
        cin >> c;
        mp.insert(c);
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (mp.count(a[i]))
        {

            lol j = i + 1;
            if (j < n)
            {
                while (mp.count(a[j]))
                {
                    j++;
                    if (j == n)
                        break;
                }
            }
            ans += (j - i) * (j - i + 1) / 2;
            i = j - 1;
        }
    }
    cout << ans;

    return 0;
}