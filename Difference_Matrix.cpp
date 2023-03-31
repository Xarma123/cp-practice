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
        lol od = 1;
        lol ev = 2;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (od <= n * 1ll * n)
                    cout << (od) << " ", od += 2;
                else
                    cout << (ev) << " ", ev += 2;
            }
            cout << '\n';
        }
    }

    return 0;
}