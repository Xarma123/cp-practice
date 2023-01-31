#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    lol t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;
        lol i;
        for (i = 0; i < x.size(); i++)
        {
            if (a[i] != x[i])
                break;
        }
        cout << i << '\n';
    }

    return 0;
}