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
        lol mi = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] < a[mi])
                mi = i;
            cin >> a[i];
        }
        if (mi + 1 < n && mi + 1 >= 2)
        {
            lol d = min(((a[mi + 1] - a[mi]) / 4), (a[mi + 1] / 3));
            a[mi+1]-=3*d;
            a[mi]+=d;
            a[mi-1]+=2*d;
        }

        sort(a, a + n);
        cout << a[0] << endl;
    }

    return 0;
}