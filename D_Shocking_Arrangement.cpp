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
        lol a[n];
       
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
           
        }
        sort(a, a + n);
        lol ans[n];
        lol mx = a[n - 1] - a[0];
        lol l = 0, r = n - 1;
        lol sum = 0;
        for (lol i = 0; i < n; i++)
        {
            sum = a[i];
            lol j = i + 1;
            while (j < n && sum<= mx)

        }
    }

    return 0;
}