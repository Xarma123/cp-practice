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
        lol x;
        cin >> x;
        if (x >= 67 && x <= 45000)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}