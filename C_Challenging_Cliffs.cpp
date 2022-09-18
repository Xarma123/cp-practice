#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        lol h[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        sort(h, h + n);
        lol ansi = 0;
        for (lol i = 0; i < n - 1; i++)
        {
            if (h[i + 1] - h[i] < h[ansi + 1] - h[ansi])
            {
                ansi = i;
            }
        }
        cout << h[ansi] << " ";
        for (lol i = ansi + 2; i < n; i++)
        {
            cout << h[i] << " ";
        }
        for (lol i = 0; i < ansi; i++)
        {
            cout << h[i] << " ";
        }
        cout << h[ansi + 1] << endl;
        ;
    }

    return 0;
}