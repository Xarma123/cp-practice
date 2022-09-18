#include <bits/stdc++.h>
#define lol long long
#define lold long double
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lold a[n], p[n] = {0};
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
           
        }
        sort(a, a + n); 
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
                p[i] = a[i];
            else
                p[i] = p[i - 1] + a[i];
        }
       
        lold avg = INT_MIN;
        for (lol i = 0; i < n - 1; i++)
        {
            lold t = p[i] / (i + 1) + (p[n - 1] - p[i]) / (n-1-i);
            avg = max(avg, t); 
           
        }
        cout << setprecision(9) << avg << endl;
    }

    return 0;
}