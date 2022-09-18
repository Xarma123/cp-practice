#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, k;
vector<lol> a;
bool check(lol s)
{
    lol c = 1;
    lol sum = 0;
    for (lol i = 0; i < n; i++)
    {   if(a[i]>s)
          return false;
        if (sum + a[i] > s)
        {
            sum = a[i];
            c++;
        }
        else
        {
            sum += a[i];
        }
    }
    return c <= k;
}
int main()
{
    cin >> n >> k;
    lol e = 0;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        e += t;
        a.push_back(t);
    }
    
    lol s = 0;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (check(m))
        {
            e = m;
        }
        else
            s = m;
    }
    cout << e;

    return 0;
}