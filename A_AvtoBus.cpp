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
        if (n % 2 != 0)
            cout << -1 << endl;
        else
        {
            lol mn = n / 6;
            if (n % 6 == 4)
            {
                mn++;
            }
            if (n % 6 == 2)
                mn++;
            lol mx = n / 4;
            cout << mn << " " << mx << endl;
        }
    }

    return 0;
}