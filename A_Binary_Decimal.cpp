#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < a.size(); i++)
        {
            if (a[i] - '0' > ans)
                ans = a[i] - '0';
        } 
        cout<<ans<<endl;
    }

    return 0;
}