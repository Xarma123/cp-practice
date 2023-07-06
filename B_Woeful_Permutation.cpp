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
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            p[i] = i + 1;
        }
        for (lol i = n - 2; i >= 0; i -= 2)
        {
            swap(p[i], p[i + 1]);
        }
        for (lol i = 0; i < n; i++)
        {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
}