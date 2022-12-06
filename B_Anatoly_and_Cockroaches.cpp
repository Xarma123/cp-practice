#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    lol n;
    cin >> n;
    cin >> s;
    lol b = 0;
    for (auto c : s)
    {
        if (c == 'b')
            b++;
    }
    lol ans = LONG_LONG_MAX;
    // brbrb ..
    lol bw = 0, rw = 0;
    char c = 'b';
    for (lol i = 0; i < n; i++)
    {
        if (s[i] != c)
        {
            if (c == 'b')
                rw++;
            else
                bw++;
        }
        if (c == 'b')
            c = 'r';
        else
            c = 'b';
    }
    ans = min(ans, max(rw, bw));

    // rbrb..
    bw = 0, rw = 0;
    c = 'r';
    for (lol i = 0; i < n; i++)
    {
        if (s[i] != c)
        {
            if (c == 'b')
                rw++;
            else
                bw++;
        }
        if (c == 'b')
            c = 'r';
        else
            c = 'b';
    }
    ans = min(ans, max(rw, bw));
    cout << ans;

    return 0;
}