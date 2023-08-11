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
        string s;
        cin >> s;
        map<pair<lol, lol>, lol> mp;
        lol d = 0, k = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'D')
                d++;
            else
                k++;
            lol g = __gcd(d, k);
            cout << (++mp[{(d / g), (k / g)}]) << " ";
        }
        cout << '\n';   
    }

    return 0;
}