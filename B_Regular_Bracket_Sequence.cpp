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
    lol v = 0;
    lol ans = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            v++;
        }
        else
            v--;
        if (v < 0)
        {
            v = 0;
            ans++;
        }
    }
    ans += v;
    cout << s.size() - ans;

    return 0;
}