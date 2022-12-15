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
        string s;
        cin >> s;
        lol ans = 9ll * (s.size() - 1);
        ans += s[0] - '0';
        cout << ans << endl;
    }

    return 0;
}