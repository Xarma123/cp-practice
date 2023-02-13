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

        for (lol i = 2; i <= n; i++)
        {
            cout << i << ' ';
        }
        cout << 1 << '\n';
    }

    return 0;
}