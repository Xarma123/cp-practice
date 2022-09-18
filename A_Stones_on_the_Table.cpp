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
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        if (j < n)
        {
            while (s[j] == s[i])
            {
                j++;
                if (j == n)
                    break;
            }
        } 
        ans += j - i - 1;
        i=j-1;
    }
    cout << ans;

    return 0;
}