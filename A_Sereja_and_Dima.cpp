#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol s = 0, d = 0;
    lol t = 1;
    lol i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[i] >= a[j])
        {
            if (t)
                s += a[i];
            else
                d += a[i];
            i++;
        }
        else
        {
            if (t)
                s += a[j];
            else
                d += a[j];
            j--;
        }
        t = 1 - t;
    }
    cout << s << " " << d;

    return 0;
}