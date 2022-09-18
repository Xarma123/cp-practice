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
        bool ans = true;
        set<lol> x;
        for (lol i = 0; i < n; i++)
        {

            cin >> a[i];
            a[i] =(a[i]%n+n)%n; 
            a[i]=(a[i]+i)%n;
             
            if (x.count(a[i]))
                ans = false;
            x.insert(a[i]);
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}