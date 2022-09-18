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
    char a = 'a';
    lol ans = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        ans += min(abs(s[i] - a), 26 - abs(s[i] - a));
        a = s[i];
    }
    cout << ans;

    return 0;
}