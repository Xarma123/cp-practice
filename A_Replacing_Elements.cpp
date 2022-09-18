#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(lol a[], lol n, lol d)
{
    lol s = 0, e = n - 1;
    while (s < e)
    {
        if (a[s] + a[e] <= d)
        {  
            return true;
        }
        else
        {
            e--;
        }
    }
    return false;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, d;
        cin >> n >> d;
        lol a[n];
        bool f1 = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > d)
                f1 = false;
        }
        if (f1)
            cout << "YES" << endl;
        else
        {
            sort(a, a + n);
            if (check(a, n, d))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}