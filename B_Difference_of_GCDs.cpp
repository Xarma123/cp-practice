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
        lol n, l, r;
        cin >> n >> l >> r;
        // l to r ,, we must have divisor for each number
        // 2 to n
        bool f = true;
        for (lol i = 2; i <= n; i++)
        {
            if (l % i == 0)
                continue;
            if (l + i - (l % i) > r)
            {
                f = false;
            }
        }
        if (f)
        {
            cout << "YES" << endl;
            for (lol i = 1; i <= n; i++)
            {
                if (l % i == 0)
                    cout << l << " ";
                else
                    cout << l + i - (l % i) << " ";
            }
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}