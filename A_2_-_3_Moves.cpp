#include <bits/stdc++.h>
#define lol long long
using namespace std;
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

        lol k = n / 6;

        if (n == 1)
        {
            cout << 2 << endl;
            continue;
        }

        if (n % 6 == 0)
            cout << 2 * k << endl;
        else if (n % 6 <= 2)
            cout << 2 * (k - 1) + 3 << endl;
        else if (n % 6 == 3)
            cout << 2 * k + 1 << endl;
        else
            cout << 2 * k + 2 << endl;
    }

    return 0;
}