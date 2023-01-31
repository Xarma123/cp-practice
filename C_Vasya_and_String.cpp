#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    lol j = 0;
    lol b = 0;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == 'b')
            b++;
        while (j <= i && b > k)
        {
            if (s[j] == 'b')
                b--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    b = 0;
    j = 0;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            b++;
        while (j <= i && b > k)
        {
            if (s[j] == 'a')
                b--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans;

    return 0;
}