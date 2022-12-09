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
    lol o = 0;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == '1')
            o++;
    }
    cout << n - 2 * 1ll * min(o, n - o);

    return 0;
}