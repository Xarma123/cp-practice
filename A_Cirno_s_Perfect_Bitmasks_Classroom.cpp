#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol x;
        cin >> x; 
        if(x==1)
        cout<<3<<endl;
        else if((x&(x-1))==0)
        {
            cout<<x+1<<endl;
        }
        else
        {
            int i=0;
            while((x&(1<<i))==0)
            i++;
            cout<<(1<<i)<<endl;
        }

    }

    return 0;
}