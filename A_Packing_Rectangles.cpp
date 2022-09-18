#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol w, h, n;
bool check(lol x)
{
    return (floor(x / w)) * floor((x / h)) >= n;
}
int main()
{

    cin >> w >> h >> n;
    lol s = 0, e = max(w, h) * n;
    while (s!=e-1)
    {
        lol m = (s + e) / 2;
        if (check(m))
        {
            e = m;
        }
        else
            s = m;
           
    }
    cout<<e;

    return 0;
}