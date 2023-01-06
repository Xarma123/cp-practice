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
        lol n, k;
        cin >> n >> k;
        lol p[n];
        lol st = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == st + 1)
                st++;
        }
        cout << (((n - st) / k) + (((n - st) % k) > 0)) << endl;
    }

    return 0;
}