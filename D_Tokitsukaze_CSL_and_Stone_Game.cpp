#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol sum = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    bool ans = true;
    lol c = 0;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && a[j] == a[i])
            j++;
        if (j - i > 1)
        {
            c++;
            if (j - i > 2)
            {
                ans = false;
                break;
            }
            if (a[i] == 0)
            {
                ans = false;
                break;
            }
            if (i)
            {
                if (a[i - 1] == a[i] - 1)
                {
                    ans = false;
                    break;
                }
            }
            if (c > 1)
            {
                ans = false;
                break;
            }
        }
        i = j - 1;
    }
    if (ans)
    {
        if (sum <= ((n * (n - 1) / 2ll)))
            sum = 0;
        else
            sum -= ((n * (n - 1) / 2ll));
        if (sum % 2 == 0)
        {
            cout << "cslnb";
        }
        else
            cout << "sjfnb";
    }
    else
        cout << "cslnb";
}