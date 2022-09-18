#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;

        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            a[i] = n - i;
        }
        lol p = n - 2;
        lol N = n;
        while (n--)
        {
            for (lol i = 0; i < N; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
            if(p-1>=0)
            swap(a[p], a[p - 1]);
            else
            swap(a[0],a[N-1]);
            p--;
        }
    }

    return 0;
}