#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        char c = 0;
        for (lol i = 0; i < 2 * n + 1; i++)
        {
            string s;
            cin >> s;
            for (auto e : s)
                c ^= e;
        }
        cout << c << '\n';
    }

    return 0;
}