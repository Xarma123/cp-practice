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
        lol n;
        cin >> n;
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool ans = true;
        lol mx = a[n - 1];
        for (lol i = n - 2; i >= 0; i--)
        {
            if (a[i] <= mx && b[i] <= mx)
            {
                b[i] = min(a[i], b[i]);
            }
            else if (b[i] <= mx)
            {
                swap(a[i], b[i]);
            }
            else if (a[i] > mx && b[i] > mx)
                ans = false;
        }
        mx = b[n - 1];
        for (lol i = n - 2; i >= 0; i--)
        {
            if (b[i] > mx)
                ans = false;
        }
        if (!ans)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}