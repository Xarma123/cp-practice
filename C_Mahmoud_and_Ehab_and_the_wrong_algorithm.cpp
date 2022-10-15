#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    if (n <= 5)
        cout << -1 << endl;
    else
    {
        for (lol i = 2; i < n - 1; i++)
        {
            cout << i << " " << 1 << endl;
        }
        cout << n - 2 << " " << n - 1 << endl;
        cout << n - 2 << " " << n << endl;
    }
    for (lol i = 1; i < n; i++)
    {
        cout << i << " " << i + 1 << endl;
    }

    return 0;
}