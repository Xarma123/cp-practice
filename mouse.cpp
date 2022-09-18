#include <bits/stdc++.h>
#define ll long long
using namespace std;
lol compare(const void* ap, const void* bp)
{
    
    const lol* a = (lol*)ap;
    const lol* b = (lol*)bp;
  
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        ll a[k];
        for (ll i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        sort(a,a+k);
        ll c = 0; ll ans = 0; ll it = k-1, s =0;
        while (c!=n)
        { 
            a[it]++;
            if(a[it]==n)
            {
                ans++;
                it--;
                if(it<s)
                {
                    break;
                }
            }  
            c++;
            while (a[s]==c)
            {
                s++;
               
            }
            
              if(s==it+1)
                break;


            
        } 
        cout<<ans<<endl;
        
    }

    return 0;
}