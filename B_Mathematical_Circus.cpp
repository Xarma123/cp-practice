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
        if (k == 0)
            cout << "NO" << endl;
        else if (k % 2 != 0)
        {
            cout << "YES" << endl;
            for (lol i = 1; i < n; i++)
            {
                cout << i << " " << i + 1 << endl;
                i++;
            }
        }
        else if (k % 4 == 2)
        {
            cout << "YES" << endl;
            for (lol i = 2; i <= n; i += 2)
            {
                if (i % 4 != 0)
                {
                    cout << i << " " << i - 1 << endl;
                }
                else
                {
                    cout << i - 1 << " " << i << endl;
                }
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}