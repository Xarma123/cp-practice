#include<bits/stdc++.h>
const lol maxn = 8010;
using namespace std;
typedef long long ll;
lol a[maxn],t,n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        lol b[maxn]={0};
        cin>>n;
        for(lol i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        ll ans =0;
        for(lol i=1;i<=n;i++)
        {
            lol sum=a[i];
            for(lol j=i+1;j<=n;j++)
            {
                sum+=a[j];
                if(sum>n)
                {
                    break;
                }
                else{
                    ans+=b[sum];
                    b[sum]=0;
                }
            } 
        }
        cout<<ans<<endl;
    }
    return 0;
}

