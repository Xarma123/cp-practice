#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol k;
        cin >> k;
        lol x = min((m - 1) + m * (n - 1), (n - 1) + (n) * (m - 1));
    
        if (x == k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}