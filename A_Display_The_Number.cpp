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
        // 0-6
        // 1-2
        // 2-5
        // 3-5
        // 4-4
        // 5-5
        // 6-6
        // 7-3
        // 8-7
        // 9-6
        if (n % 2 == 0)
        {
            n /= 2ll;
            while (n--)
            {
                cout << 1;
            }
            cout << '\n';
        }
        else
        {
            cout << 7;
            n -= 3;
            n /= 2ll;
            while (n--)
            {
                cout << 1;
            }
            cout << '\n';
        }
    }
}