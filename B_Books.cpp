#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, t;
    cin >> n >> t;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    deque<lol> x;
    lol ans = 0;
    lol lt = t;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] <= lt)
        {
            x.push_back(a[i]);
            lt -= a[i];
            lol s = x.size();
            ans = max(ans, s);
        }
        else
        {
            while (!x.empty() && lt < a[i])
            {
                lt += x.front();
                x.pop_front(); 
                lol s = x.size();
                ans = max(ans, s);
            }
            if (lt >= a[i])
            {
                x.push_back(a[i]); 
                lt-=a[i];
                lol s = x.size();
                ans = max(ans, s);
            } 
            
        }
    } 
    cout<<ans;

    return 0;
}