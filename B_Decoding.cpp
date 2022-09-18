#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol si = 0;
    string ans = s;
    lol i, j;
    if (s.size() % 2)
    {
        ans[s.size() / 2] = s[si];
        si++;
        i = s.size() / 2 - 1;
        j = s.size() / 2 + 1;
    }
    else
    {
        i = s.size() / 2 - 1;
        j = s.size() / 2;
    }
    while (si < s.size())
    {
        lol sz = i + 1;
        sz += n - j;
        if (sz % 2)
        {
            sz /= 2;
        }
        else
        {
            sz = sz / 2 - 1;
        }
        if (sz <= i)
        {
            ans[sz] = s[si];
            si++;
            i--;
        }
        else
        {
            sz -= i + 1;
            ans[j + sz] = s[si];
            si++;
            j++;
        }
    } 
    cout<<ans;

    return 0;
}