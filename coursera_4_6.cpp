#include <bits/stdc++.h>
using namespace std;
int main()
{
    long double n;
    cin >> n;

    long long k;
    k = floor((sqrt(1 + 8 * n) - 1) / 2);
    cout << k<<endl; 
       long long ans=0;
    for (long long  i = 1; i <=k ; i++)
    {   ans+=i; 
        if(i==k&&ans<n)
        {
            ans-=i;
            i=n-ans;
        }
        cout<<i<<" " ;

    }
    

    return 0;
}