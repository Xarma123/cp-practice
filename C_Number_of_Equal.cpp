#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol a[n + 1], b[m + 1];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    a[n] = INT_MAX;
    b[m] = INT_MAX;

    lol i = 0, j = 0;
    lol q = 0;
    lol ans = 0;
    while (i <= n && j <= m)
    {
        if (a[i] == INT_MAX && b[j] == INT_MAX)
            break;
        if (a[i] < b[j])
        {
            i++;
        }
        else if(b[j]<a[i])
        {

            j++;
        }
        else
        {
            lol c1=1,c2=1,p1=i+1,p2=j+1;
            while (a[p1]==b[j])
            {
                c1++;
                p1++;
            }
            while (b[p2]==a[i])
            {
                c2++;
                p2++;
            }
            i=p1;
            j=p2;
            ans+= c1*c2;
            
            
        }
    }
    cout << ans;

    return 0;
}