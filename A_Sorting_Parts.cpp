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
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b, b + n);
        lol i;
        for (i = 0; i < n - 1; i++)
        {
            for (lol j = i - 1; j >= 0; j--)
            {
                if (a[j + 1] < a[j])
                    swap(a[j], a[j + 1]);
                else
                    break;
            }
            lol j;
            for ( j = 0; j <= i; j++)
            {
                if (b[j] != a[j])
                    break;
            }
            if (j == i + 1)
                break;
        }
      
        if (i == n - 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}