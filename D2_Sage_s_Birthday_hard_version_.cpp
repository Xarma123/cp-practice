#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol s = 0;
    lol e = n / 2;
    vector<lol> ans;
    while (e < n && s < n / 2)
    {
        ans.push_back(a[e]);
        ans.push_back(a[s]);
        s++;
        e++;
    }
    if (e != n)
        ans.push_back(a[e]);
    lol c = 0;
    for (lol i = 1; i < n; i++)
    {
        if (i + 1 < n)
        {
            if (ans[i - 1] > ans[i] && ans[i + 1] > ans[i])
            {
                c++;
            }
        }
    }
    cout << c << endl;
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}