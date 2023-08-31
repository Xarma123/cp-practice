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
        lol n, a, b;
        cin >> n >> a >> b;
        if (a == n && b == n)
            cout << "Yes\n";
        else if (n - a - b > 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}