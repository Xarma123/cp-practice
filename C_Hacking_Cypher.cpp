#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol a, b;
    cin >> a >> b;
    bool pre[s.size()];
    lol r = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        r = (((10 % a) * 1ll * (r)) % a + (s[i] - '0') % a) % a;

        if (r == 0)
            pre[i] = true;
        else
            pre[i] = false;
    }
    r = 0;
    lol p = 1;
    bool ans = false;
    for (lol i = s.size() - 1; i > 0; i--)
    {
        r = ((((s[i] - '0') % b) * 1ll * p) % b + r) % b;
        p = p * 10ll;
        p %= b;
        if (r == 0)
        {
            if (pre[i - 1])
            {
                if (s.substr(0, i) != "0" && s.substr(i) != "0")
                {
                    cout << "YES" << endl;
                    cout << s.substr(0, i) << endl
                         << s.substr(i);
                    ans = true;
                    break;
                }
            }
        }
    }
    if (!ans)
        cout << "NO";

    return 0;
}