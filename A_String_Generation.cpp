#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        char a[3] = {'a', 'b', 'c'};
        lol p = 0;
        while (n--)
        {
            cout << a[p];
            p++;
            if (p == 3)
                p = 0;
        }
        cout << endl;
    }

    return 0;
}