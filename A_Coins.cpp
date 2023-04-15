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
        if (n % 2 == 0)
            cout << "YES\n";
        else
        {
            if (((k % 2) == 1) && n >= k)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }

    return 0;
}