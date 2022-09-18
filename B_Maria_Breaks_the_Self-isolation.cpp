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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol c = n;
        lol i;
        for (i = n - 1; i >= 0; i--)
        {
            if (a[i] > c)
            {
                c--;
            }
            else
            {
                break;
            }
        }
        cout << i + 2 << endl;
    }

    return 0;
}