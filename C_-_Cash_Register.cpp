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
    lol ans = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] != '0')
            ans++;
        else
        {
            lol j = i + 1;
            while (j < s.size() && s[j] == '0')
                j++;
            ans += (j - i) / 2 + (j - i) % 2;
            i = j - 1;
        }
    }
    cout << ans;

    return 0;
}