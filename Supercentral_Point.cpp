#include <iostream>
using namespace std;
bool l1(lol a[][2], lol r,lol n)
{
    lol up = 0, lw = 0, lt = 0, rt = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[r][0] == a[i][0] && i != r)
        {
            if (a[i][1] > a[r][1])
                up++;
            if (a[i][1] < a[r][1])
            {
                lw++;
            }
        }
        if (a[r][1] == a[i][1] && i != r)
        {
            if (a[i][0] > a[r][0])
                rt++;
            if (a[i][0] < a[r][0])
            {
                lt++;
            }
        }
    } 
    if(up&&lw&&lt&&rt)
    return true;
    else
    return false; 
}
int main()
{
    lol n;
    cin >> n;
    lol a[n][2]={0};
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (l1(a, i,n))
        {
            ans++;
           
        }
    }
    cout<<ans;
    return 0;
}