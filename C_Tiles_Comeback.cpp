#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        lol i = 1;
        lol co = 1;
        while (i < n && co < k)
        {
            if (c[i] == c[0])
                co++;
            i++;
        }
        if (co < k)
            cout << "NO\n";
        else if (c[n - 1] == c[0])
            cout << "YES\n";
        else
        {
            lol j = n - 2;
            co = 1;
            while (j >= 0 && co < k)
            {
                if (c[j] == c[n - 1])
                    co++;
                j--;
            }
            if (i <= j + 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}