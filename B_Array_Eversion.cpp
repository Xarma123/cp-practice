#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol mx = INT_MIN;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        lol c = 0;
        lol mxt = a[n - 1];
        if (mxt == mx)
        {
            cout << c << endl;
            continue;
        }
        for (lol i = n - 2; i >= 0; i--)
        {
            if (a[i] > mxt)
            {
                c++;
                if (a[i] == mx)
                    break;
                mxt = a[i];
            }
        }
        cout << c << endl;
    }

    return 0;
}