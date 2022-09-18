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
    vector<lol> f(26, 0);

    for (lol i = 0; i < s.size(); i++)
    {
        f[s[i] - 'a']++;
    }
    lol ans = 0;
    for (lol i = 0; i < 26; i++)
    {
        if (f[i] != 0)
            ans++;
       
    }

    if (ans % 2 != 0)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";

    return 0;
}