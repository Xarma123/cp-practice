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
    lol c[n + m];
    lol i = 0, j = 0, k = 0;
    while (i <= n && j <= m)
    {
        if (a[i] == INT_MAX && b[j] == INT_MAX)
            break;
        if (a[i] <= b[j])
        {
            c[k++] = a[i++];
        }
        else
            c[k++] = b[j++];
    }
    for (lol i = 0; i < n + m; i++)
    {
        cout << c[i] << " "; 
    }
    lol ans[m];
    

    return 0;
}