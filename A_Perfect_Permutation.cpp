#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << ((-1) % 3);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        cout << n << " ";
        for (lol i = 1; i < n; i++)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
}