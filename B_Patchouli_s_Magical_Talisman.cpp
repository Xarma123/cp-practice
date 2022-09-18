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
        lol e = 0, o = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i]; 
            if(a[i]%2==0)
            {
                e++;
            }
            else
            o++;
        }
        if(o>0)
        cout<<e<<endl;
        else
        {   lol step=LONG_LONG_MAX;
            for (lol i = 0; i < n; i++)
            {
                lol c=0;
                while(a[i]%2==0)
                {
                    c++;
                    a[i]/=2;
                }
                step=min(step,c);
            } 
            cout<<step+e-1<<endl;
            
        }
    }

    return 0;
}