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
        if (n % 2)
            cout << -1 << '\n';
        else
        {
            for (lol i = 1; i <= n; i += 2)
            {
                cout << i + 1 << " " << i << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}