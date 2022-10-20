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
        cout << 1 << " ";
        for (lol i = n; i > 1; i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}