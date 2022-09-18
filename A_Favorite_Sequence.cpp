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
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        lol a[n];
        lol j = n - 1;
        lol c = n / 2;
        lol i = 1;
        while (c--)
        {
            a[i] = b[j];
            i += 2;
            j--;
        }
        i = 0;
        j = 0;
        while (i < n && j < n)
        {
            a[i] = b[j];
            j ++;
            i += 2;
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}