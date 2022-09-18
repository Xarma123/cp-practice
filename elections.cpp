#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    { 
        lol a,b,c;
        cin>>a>>b>>c;
        if(a==b&&b==c)
        cout<<a+1<<" "<<a+1<<" "<<a+1<<endl;
        else
        {    lol m = max(b,c);
            if(a>m)
            {
                cout<<0<<" ";
            } 
            else if(a==m)
            {
                cout<<1<<" ";
            }
            else
            {
                cout<<m-a+1<<" ";
            }


            m = max(a,c);
            if(b>m)
            {
                cout<<0<<" ";
            } 
            else if(b==m)
            {
                cout<<1<<" ";
            }
            else
            {
                cout<<m-b+1<<" ";
            } 
            m = max(a,b);
            if(c>m)
            {
                cout<<0<<" ";
            } 
            else if(c==m)
            {
                cout<<1<<" ";
            }
            else
            {
                cout<<m-c+1<<" ";
            } 

            cout<<endl;



        }
    }

    return 0;
}