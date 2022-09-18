#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol maxSum(vector<lol> &arr, lol k)
{
    lol n = arr.size();

    lol res = 0;
    for (lol i = 0; i < k; i++)
        res += arr[i];

    lol curr_sum = res;
    for (lol i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k];
        res = max(res, curr_sum);
    }

    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        vector<lol> a(n);
        int s=0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i]; 
            s+=a[i];
        }
        if (n >= k)
        { 
            cout<<maxSum(a,k)+k*(k-1)/2<<endl;
        }
        else
        {
            lol ans=s;
            if(n==1)
            ans+=k*(k-1)/2;
            else
            {
                for (lol i = 1; i < n; i++)
                {
                    ans+=i+((k-1-i)/(n-1))*(n-1);
                }
                ans+=((k-1)/(2*n-1))*(2*n-1);
                
            } 
            cout<<ans<<endl;


        }
    }

    return 0;
}