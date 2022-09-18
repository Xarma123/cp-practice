#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol sum(lol n)
{
    if (n == 1)
        return 1;
    return 1 + 2* sum(n - 1);
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol ans=0;
        for (lol i = 0; i < 60; i++)
        {
            if ((1LL << i) & n)
            {
              ans+=sum(i+1);
            }
        } 
        cout<<ans<<endl;
    }

    return 0;
}