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
        lol a[n];
        lol x = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x ^= a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            if ((x ^ a[i]) == a[i])
            {
                cout << a[i] << endl;
                break;
            }
        }
    }

    return 0;
}