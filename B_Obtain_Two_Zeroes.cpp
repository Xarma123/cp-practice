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
        lol a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (2ll * a < b)
        {
            cout << "NO\n";
        }
        else
        {
            lol d = b - a;
            a -= d;

            if (a % 3 != 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}