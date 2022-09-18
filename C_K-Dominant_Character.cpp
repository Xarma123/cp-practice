#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string s;
    cin >> s;
    char c = 'a';
    lol ans = LONG_LONG_MAX;
    while (c <= 'z')
    {

        lol l = -1;
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                mx = max(mx, i - l);
                l = i;
            }
        }
        mx = max(mx, s.size() - l);
        ans = min(ans, mx);
        c++;
    }
    cout << ans;

    return 0;
}