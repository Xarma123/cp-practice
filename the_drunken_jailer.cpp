#include <iostream>
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
        lol a[n + 1] ;
        for (lol i = 0; i<=n; i++)
        {
            a[i]=0;
        }
        
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = i; j <= n; j = j + i)
            {
                a[j] = 1 - a[j];
            }
        }
        lol ans = 0;
        for (lol i = 0; i <= n; i++)
        {
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}