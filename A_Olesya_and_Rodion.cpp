#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, t;
    cin >> n >> t;
    if (n == 1 && t == 10)
    {
        cout << -1;
    }
    else
    {
        cout << t;
        n--;
        if (t == 10)
            n--;
        while (n--)
        {
            cout << 0;
        }
    }

    return 0;
}