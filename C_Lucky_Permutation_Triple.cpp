#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    if (n % 2 != 0)
    {
        for (lol i = 0; i < n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (lol i = 0; i < n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (lol i = 0; i < n; i++)
        {
            cout << (i + i) % n << " ";
        }
    }
    else
        cout << -1;

    return 0;
}