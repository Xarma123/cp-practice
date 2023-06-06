#include <bits/stdc++.h>
using namespace std;
#define lol long long

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
        if (a[n - 1] != 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (lol i = n - 1; i >= 0; i--)
            {
                lol j = i - 1;
                while (j >= 0 && a[i] == a[j])
                {
                    j--;
                }
                lol c = i - j;
                if (a[i] == 0)
                {
                    while (c--)
                    {
                        cout << 0 << " ";
                    }
                }
                else
                {
                    c--;
                    while (c--)
                    {
                        cout << 0 << " ";
                    }
                    cout << i - j << " ";
                }
                i = j + 1;
            }
            cout << '\n';
        }
    }
}