#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol c = 1;
        lol c2 = n;
        lol a[n];
        for (lol i = 0; i < k; i++)
        {
            if (i % 2 == 0)
            {
                for (lol j = i; j < n; j += k)
                {
                    a[j] = (c++);
                }
            }
            else
            {
                for (lol j = i; j < n; j += k)
                {
                    a[j] = (c2--);
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
