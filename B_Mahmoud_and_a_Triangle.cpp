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
    sort(a, a + n);
    lol i;
    for (i = 0; i < n - 2; i++)
    {
        if (a[i] < a[i + 1] + a[i + 2])
            if (a[i + 1] < a[i] + a[i + 2])
                if (a[i + 2] < a[i] + a[i + 1])
                {
                  
                    break;
                }
    }
    if (i < n - 2)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}