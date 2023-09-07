#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol ans = 0;
    for (lol i = 1; i < n; i += 2)
    {
        if (s[i] == s[i - 1])
        {
            if (s[i] == 'a')
                s[i] = 'b';
            else
                s[i] = 'a';
            ans++;
        }
    }
    cout << ans << '\n';
    cout << s << endl;
}