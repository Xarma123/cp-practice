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
    lol f[26];
    for (lol i = 0; i < 26; i++)
    {
        f[i] = 0;
    }
    for (lol i = 0; i < s.size(); i++)
    {
        f[s[i] - 'a']++;
    }
    lol od = 0;
    for (lol i = 0; i < 26; i++)
    {
        if (f[i] % 2 != 0)
            od++;
    }
    if (od == 0 || od % 2 != 0)
        cout << "First";
    else
        cout << "Second";

    return 0;
}