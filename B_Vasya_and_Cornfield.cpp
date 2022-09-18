#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, d;
    cin >> n >> d;
    lol m;
    cin >> m;
    while (m--)
    {
        lol x,y;
        cin>>x>>y;

        if(  (y+x-d)>=0&&(y-x-d)<=0&&(y+x-2*n+d)<=0&&(y-x+d)>=0    )
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }

    return 0;
}