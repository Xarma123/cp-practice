#include <bits/stdc++.h>
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
        lol a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (a[i] % b[0] != 0)
                    ans = false;
            }
        } 
        if(ans)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }

    return 0;
}