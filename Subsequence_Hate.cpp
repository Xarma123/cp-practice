#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol solve()
{

    string a;
    cin >> a;
    lol ans = 0;
    lol x = a.size() - 1;
    lol y = 0;
    while (a[y] == '1')
    {
        y++;
        if (y > a.size() - 1)
        {

            if (a.size() == 1)
                return 0;
            else
                return a.size() - 1;
        }
    }
    while (a[x] == '1')
    {
        x--;
    }
    if (y >  a.size() - 1-x)
    {
        ans +=  a.size() - 1-x;
    }
    else
        ans += y;

    for (lol i = y; i <= x; i++)
    {
        if (a[i] == '1')
            ans++; 
    } 
    return ans;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}