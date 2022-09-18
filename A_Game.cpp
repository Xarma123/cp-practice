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
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol c = 0, x = 1, y = 0;
        for (lol i = 1; i < n; i++)
        {
            if (a[i] == 0)
            {
                y=i-1;
                break;
            }
        } 
        for (lol i = n-1; i>=0; i--)
        {
            if(a[i]==0)
            {
                x=i+1;
                break;
            }
        } 
        if(x==1)
        c=0;
        else
        c=x-y;
        cout<<c<<endl;
        
    }

    return 0;
}