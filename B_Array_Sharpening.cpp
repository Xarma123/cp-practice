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
        lol i;
        for (i = 0; i < n; i++)
        {
            if (a[i] < i)
            {
                break;
            }
        }
        i--;
        lol j;
        for (j = n - 1; j >= 0; j--)
        {
            if (a[j] < n - 1 - j)
                break;
        }
        j++;
        if (j > i)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}