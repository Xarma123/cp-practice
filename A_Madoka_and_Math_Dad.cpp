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
        lol n;
        cin >> n;
        if (n % 3 == 0)
        {
            n /= 3;
            for (lol i = 0; i < n; i++)
            {
                cout << 21;
            }
        }
        else if (n % 3 == 1)
        {
            n /= 3;
            for (lol i = 0; i < n; i++)
            {
                cout << 12;
            }
            cout << 1;
        }
        else
        {
            n /= 3;
            for (lol i = 0; i < n; i++)
            {
                cout << 21;
            }
            cout << 2;
        }
        cout << '\n';
    }
}