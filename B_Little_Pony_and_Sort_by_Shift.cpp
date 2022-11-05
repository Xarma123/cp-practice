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
    lol mx = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (is_sorted(a, a + n))
        cout << 0;
    else if (a[0] < a[n - 1])
    {
        cout << -1;
    }
    else
    {
        lol j = n - 1;
        mx = a[0];
        while (a[j] <= mx)
            mx = a[j], j--;
        lol i = 0;
        bool ans = true;
        while (i < j)
        {
            if (a[i + 1] < a[i])
                ans = false;
            i++;
        }
        if (!ans)
            cout << -1;
        else
            cout << n - j - 1;
    }

    return 0;
}