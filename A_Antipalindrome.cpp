#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool q(string a)
{
    lol e = a.size() - 1;
    lol s = 0;
    while (s < e)
    {
        if (a[s] != a[e])
            return true;
        s++;
        e--;
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    lol n = s.size();
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = i + 1; j < n; j++)
        {
            if (q(s.substr(i, (j - i + 1))))
            {
                ans = max(ans, (j - i + 1));
            }
        }
    }
    cout << ans;

    return 0;
}