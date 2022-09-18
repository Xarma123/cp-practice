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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (lol i = n - 1; i >= 0; i -= 2)
        {
            if (i - 1 >= 0)
            {
                if (a[i - 1] > a[i])
                    swap(a[i - 1], a[i]);
            }
        }
   

        if (is_sorted(a, a + n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}