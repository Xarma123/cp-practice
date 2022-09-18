#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    lol c[a.size() + 1];
    c[0] = 0;
    for (lol i = 1; i <= a.size(); i++)
    {
        c[i] = c[i - 1];
        if (a[i - 1] == '1')
            c[i]++;
    }
    lol ans = 0;
    for (lol i = 0; i < b.size(); i++)
    {
        lol r = min((long long)a.size(), i + 1);
        lol l = max(0ll, a.size() - 1 - (b.size() - i - 1));
        if (b[i] == '0')
        {
            ans += c[r] - c[l];
        }
        else
        {
            ans += r - l;
            ans -= c[r] - c[l];
        }
       
    }
    cout << ans;

    return 0;
}