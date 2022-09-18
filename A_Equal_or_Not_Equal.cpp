#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin>>a;
        lol n = 0;
        for (lol i = 0; i < a.size() - 1; i++)
        {
           if(a[i]=='N')
           n++;
        } 
        if(n==0)
        {
            if(a[a.size()-1]=='E')
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        else if(n==1)
        {
            if(a[a.size()-1]=='N')
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;

        }
        else
        {
            cout<<"YES"<<endl;
        }
    }

    return 0;
}