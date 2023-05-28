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
        /* code */

        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[j] == a[i])
                j++;
            if (a[i] == 0)
            {
                c = max(c, j - i);
            }
            i = j - 1;
        }
        cout << c << '\n';
    }
    return 0;
}