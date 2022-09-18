#include <bits/stdc++.h>
using namespace std;
lol fact(lol n);
 bool cmp(pair<lol,lol> a, pair<lol,lol>b)
 {
     return a.second<b.second;
 }
lol nCr(lol n, lol r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
lol fact(lol n)
{
    lol res = 1;
    for (lol i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n + 1], b[n + 1];
        vector<pair<long long, long long>> x;
        long long k, l, n1 = n, n2 = n;
        cin >> k >> l;
        x.push_back(make_pair(k, l));
        a[k] = 1, b[l] = 1;
        for (long long i = 1; i < n; i++)
        {
            cin >> k >> l;
            x.push_back(make_pair(k, l));
            if (a[k] != 0)
            {
                n1--;
            }
            if (b[l] != 0)
            {
                n2--;
            }
            a[k]++;
            b[l]++; 
        }   
          long long ans=0;
          ans+= nCr(n1,3);
          ans+= nCr(n2,3);
          long long sub=0;
        set<lol> s; 
         sort(x.begin(),x.end(),cmp); long long j = 0,i=0;
         while(j<n)
         {  
            
             while (x[j].first==x[i].first)
             {   s.insert(x[j].second);
                 i++;
                
             }  
             long long q= s.size();
                sub+= nCr(q,3);
                s.clear();
             j=i;
              cout<<q<<endl;
         } 
       ans= ans;
    
         
    }

    return 0;
}