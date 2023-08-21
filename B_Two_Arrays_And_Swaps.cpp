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
        lol n, k;
        cin >> n >> k;
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        lol i = 0, j = n - 1;
        while (k > 0 && i < n && j >= 0)
        {
            if (b[j] > a[i])
            {
                swap(b[j], a[i]);
                k--;
                j--;
                i++;
            }
            else
                break;
        }
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            s += a[i];
        }
        cout << s << '\n';
    }
}