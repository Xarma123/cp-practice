#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol k;
lol n;
vector<lol> a;
bool check(lol c)
{
    lol count = 0;
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] >= c)
        {
            count++;
        }
        else
        {
            if (s + a[i] < c)
            {
                s += a[i];
            }
            else
            {
                count++;

                s = s + a[i] - c;
            }
        }
    } 
    return count>=k;
}
int main()
{

    cin >> k;

    cin >> n;

    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
    } 
    lol s = 1;
    lol e = 1e18;
    while (s!=e-1)
    {
       lol m = (s+e)/2;
       if(check(m))
       s=m;
       else
       e=m;
    }
    cout<<s;

    return 0;
}