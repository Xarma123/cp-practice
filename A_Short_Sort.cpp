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
        string a;
        cin >> a;
        lol c = 0;
        if (a[0] != 'a')
            c++;
        if (a[1] != 'b')
            c++;
        if (a[2] != 'c')
            c++;
        if (c <= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}