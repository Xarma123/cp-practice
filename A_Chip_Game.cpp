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
        lol n, m;
        cin >> n >> m;
        n--;
        m--;
        if (n % 2 == 0 && m % 2 == 0)
            cout << "Tonya" << endl;
        else if (n % 2 != 0 && m % 2 != 0)
            cout << "Tonya" << endl;
        else
            cout << "Burenka" << endl;
    }

    return 0;
}