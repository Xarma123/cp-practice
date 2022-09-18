#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    string s;
    cin >> s;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    lol ans = LONG_LONG_MIN;
    for (lol i = 0; i < 300; i++)
    {
        lol c = 0;
        for (lol j = 0; j < s.size(); j++)
        {
            lol q = a[j].second;
            q = i - q;
            if (q >= 0 && q % a[j].first == 0)
            {
                if (s[j] == '1')
                    s[j] = '0';
                else
                    s[j] = '1';
            }
            if (s[j] == '1')
                c++;
        }
        ans = max(ans, c);
    }
    cout<<ans;

    return 0;
}