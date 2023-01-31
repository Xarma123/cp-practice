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
    string a = "";
    for (lol i = s.size() - 1; i >= 0; i--)
    {

        if (s[i] == '>')
            a = "1000" + a;
        else if (s[i] == '<')
            a = "1001" + a;
        else if (s[i] == '+')
            a = "1010" + a;
        else if (s[i] == '-')
            a = "1011" + a;
        else if (s[i] == '.')
            a = "1100" + a;
        else if (s[i] == ',')
            a = "1101" + a;
        else if (s[i] == '[')
            a = "1110" + a;
        else if (s[i] == ']')
            a = "1111" + a;
    }
    lol p = 1;
    lol m = 1e6 + 3;
    lol ans = 0;
    for (lol i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == '1')
            ans += p;
        ans %= m;
        p *= 2ll;
        p %= m;
    }
    cout << ans;

    return 0;
}